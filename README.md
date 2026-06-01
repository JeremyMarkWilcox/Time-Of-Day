# UE5 Time of Day Subsystem

A data-table-driven, tick-based world subsystem for Unreal Engine 5 that manages discrete time-of-day states with smooth lerp transitions, cinematic override support, and a dynamic Light Wisp companion actor.
---

## Overview

Most time-of-day systems in UE5 projects are managed through Blueprint logic scattered across level blueprints or game mode actors. This system centralizes all lighting state into a `UTickableWorldSubsystem`, making it accessible from anywhere in the world without actor references or component lookups.

Designers author lighting presets in a `UDataTable` asset. Engineers call a single `RequestTimeState()` function. The subsystem handles transitions, cinematic overrides, and sky recapture automatically.

---

## Features

- **11 discrete time states** — Dawn, Morning, Noon, Day, Afternoon, Evening, Twilight, Night, Cave, InsideLight, InsideDark
- **Smooth lerp transitions** — Fast (1.5s) and Slow (10s) modes; all float lighting properties interpolated per tick
- **Deferred sky recapture** — `RecaptureSky()` fires once at transition end, not every frame, avoiding per-frame GPU cost
- **Data-table-driven presets** — Designers tune lighting values in a `UDataTable` asset without touching code
- **C++ fallback defaults** — System runs fully without a data table; all 11 states have built-in defaults
- **Cinematic lock** — `CinematicBeginOverride()` prevents gameplay state changes from interrupting cutscene lighting; auto-releases after a configurable timeout if `CinematicEndOverride()` is never called
- **Auto-discovery** — Finds `ADirectionalLight`, `ASkyLight`, `AExponentialHeightFog`, and `SkySphere` from the world on `Initialize()` — level managers don't need to gather and pass actor refs
- **Interface-based sky sphere** — Decoupled from `BP_Sky_Sphere`'s specific class via `ISkySphereInterface`; any Blueprint implementing the interface works
- **Light Wisp** — Optional companion actor that spawns and attaches to the current party leader; rebinds automatically on party leader change
- **Save/load support** — `RestoreTimeState()` snaps to a saved state on game load without triggering a transition

---

## Architecture

```
UTimeOfDaySubsystem (UTickableWorldSubsystem)
│
├── Initialize()          — Auto-discovers world actors, loads DataTable presets, applies default state
├── RequestTimeState()    — Public API for gameplay/gate triggers; blocked during cinematic lock
├── CinematicBeginOverride() / CinematicEndOverride()  — Cutscene lighting control
├── RestoreTimeState()    — Snap to saved state on load
│
├── Tick()
│   └── TickTransition()  — Lerps all float properties each frame, defers RecaptureSky to completion
│
└── SetTimeState()
    ├── Instant/None → ApplyPresetToLights() immediately
    └── Fast/Slow    → Begin lerp; ApplyPresetToLights() fires each tick until Alpha >= 1.0
```

**Subsystem choice:** `UWorldSubsystem` gives zero-dependency access via `GetWorld()->GetSubsystem<UTimeOfDaySubsystem>()` from any actor, component, or Blueprint in the world. No actor references to pass around, no singleton hacks.

---

## Files

| File | Description |
|------|-------------|
| `TimeOfDaySubsystem.h` | Subsystem class declaration — public API, private state, design notes |
| `TimeOfDaySubsystem.cpp` | Full implementation — initialization, transitions, wisp logic, cinematic lock |
| `TimeOfDayTypes.h` | `FTimeStatePreset` (DataTable row), `FTimeOfDayConfig`, `ETimeTransitionMode` |
| `SkySphereInterface.h` | `ISkySphereInterface` — decouples the subsystem from Blueprint sky sphere class |

---

## Usage

### Initialize (called by level manager on world entry)

```cpp
FTimeOfDayConfig Config;
Config.DefaultTimeState = EC_LightSets::Day;
Config.bAllowLightWisp  = true;

TimeOfDaySubsystem->Initialize(
    Config,
    ALightWisp::StaticClass(),
    DT_LightingPresets,   // Optional UDataTable — nullptr uses C++ defaults
    MoonLightActor        // Optional — nullptr if level has no moon light
);
```

### Trigger a time change from gameplay

```cpp
// Instant snap
SubSys->RequestTimeState(EC_LightSets::Night, ETimeTransitionMode::Instant);

// Smooth transition
SubSys->RequestTimeState(EC_LightSets::Dawn, ETimeTransitionMode::Slow);
```

### Cinematic override

```cpp
// Lock lighting for a cutscene — auto-releases after 30s if EndOverride is never called
SubSys->CinematicBeginOverride(EC_LightSets::Twilight, ETimeTransitionMode::Fast, true, true);

// Restore normal gameplay lighting control
SubSys->CinematicEndOverride();
```

### Restore from save

```cpp
SubSys->RestoreTimeState(SaveGame->SavedTimeState);
```

---

## Data Table Setup

Create a `UDataTable` asset with row struct `FTimeStatePreset`. Row names must match `EC_LightSets` enum value names (e.g., `Dawn`, `Night`, `Cave`).

Each row controls:

| Property | Description |
|----------|-------------|
| `SunRotation` | Directional light world rotation |
| `LightBrightness` | Directional light intensity |
| `LightTemperature` | Color temperature in Kelvin (lower = warmer) |
| `Exposure` | Scene exposure offset |
| `SkyLightIntensity` | Sky light intensity |
| `SkySunBrightness` | Sky sphere sun disc brightness |
| `SkySunHeight` | 0–1 value driving sky sphere color curve sampling |
| `SkyCloudOpacity` | Cloud visibility |
| `bSkyColorsByPosition` | False for interior/cave states where sky is not visible |
| `FogDensity` | Exponential height fog density |
| `MoonIntensity` | Moon light intensity (0 when sun is up) |

States not present in the table fall back to C++ defaults — no crashes, no missing states.

---

## Sky Sphere Integration

The subsystem communicates with `BP_Sky_Sphere` (or any custom sky actor) through `ISkySphereInterface` rather than casting to a specific Blueprint class. Any sky actor implementing the interface will work.

**Blueprint implementation of `ApplySkySpherePreset` should:**
1. Set `SunBrightness`, `SunHeight`, `CloudOpacity`, `ColorsDeterminedBySunPos` variables
2. Call `UpdateSunDirection`

**Blueprint implementation of `RefreshSkySphere` should:**
1. Call `RefreshMaterial`

---

## Design Decisions

**Why a world subsystem instead of a game mode component or singleton?**
World subsystems have a managed lifetime tied to the world, are accessible without actor references, and work correctly in PIE with multiple worlds. A singleton would break in editor; a game mode component requires a cast.

**Why defer `RecaptureSky()` to transition end?**
`RecaptureSky()` is a GPU capture operation. Calling it every tick for a 10-second slow transition would be wasteful. Float properties lerp each tick for visual smoothness; the sky capture fires once when the transition completes.

**Why C++ fallback defaults instead of requiring a data table?**
The system needs to be testable in isolation and robust to missing assets. Fallback defaults mean a level works immediately on first pass — designers iterate the data table later without breaking anything.

**Why an interface for the sky sphere?**
`BP_Sky_Sphere` is a Blueprint class. Casting to it from C++ requires a class reference lookup that couples the subsystem to a specific asset path. An interface keeps the subsystem decoupled and lets any sky actor (custom or default) plug in.

**Why an auto-release timer on cinematic lock?**
Cutscene systems can fail silently — a sequence that gets interrupted or a Blueprint that crashes mid-play could leave the lock set permanently, breaking all lighting transitions for the rest of the session. The 30-second auto-release is a guaranteed fallback.
