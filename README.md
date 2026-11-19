# Time Of Day (UE5 plugin)

A data-table-driven world subsystem that moves a level between discrete lighting states
(Dawn, Morning, Noon, Day, Afternoon, Evening, Twilight, Night, Cave, InsideLight, InsideDark)
with smooth transitions, a cinematic lock, and an optional companion light.

## Install

1. Copy the `TimeOfDay` folder into your project's `Plugins/` folder (create it if needed).
2. Right-click the `.uproject` and choose **Generate Visual Studio project files**, then build.
3. The plugin is enabled automatically.

Your sun (Directional Light) must have **Mobility: Movable** to rotate at runtime.

## Try it in 30 seconds

Press Play and use the keyboard:

| Key | What it does |
|---|---|
| `/` | Show or hide the overlay (state, blend progress, timeline, live light values) |
| `]` / `[` | Blend to the next / previous outdoor state (slow, 10 s) |
| Shift + `]` / `[` | Same, fast (1.5 s) |
| `\` | Start or stop the demo loop, Dawn to Night |
| `;` | Blend back to the level's original lighting |

Or open the console with `~`:

| Command | What it does |
|---|---|
| `tod.Set Evening slow` | Blend to a state. Modes: `slow`, `fast`, `instant` |
| `tod.Next` / `tod.Prev` | Step through the outdoor states |
| `tod.Demo 3 slow` / `tod.Demo off` | Loop Dawn to Night, holding each state 3 s |
| `tod.Debug` | Toggle the overlay |
| `tod.Hotkeys 0` | Turn the keyboard shortcuts off |
| `tod.Status` | Log the current state |

No setup is needed for testing: the first key or command initializes the system with built-in presets
and captures the level's own lighting as state `None`.

## Use it in a game

```cpp
UTimeOfDaySubsystem* TimeOfDay = GetWorld()->GetSubsystem<UTimeOfDaySubsystem>();
TimeOfDay->InitializeTimeOfDay(Config, DT_LightingPresets); // once per level
TimeOfDay->RequestTimeState(ETimeOfDayState::Evening, ETimeTransitionMode::Slow);
```

Every function is also Blueprint-callable (category **Time Of Day**), and `OnTimeStateChanged`
fires when a state finishes applying.

- **Presets:** create a Data Table with row struct `FTimeStatePreset`. Name rows after states
  (`Dawn`, `Night`...). Rows override the built-in defaults, so lighting is tuned without code.
- **Cinematics:** `CinematicBeginOverride` blocks gameplay requests until `CinematicEndOverride`,
  and releases itself after a timeout if the end call never comes.
- **Save/load:** `RestoreTimeState` snaps to a saved state with no transition.
- **Picking lights:** the subsystem finds the sun, sky light, height fog and unbound post process
  volume on its own. Tag an actor `TimeOfDaySun` or `TimeOfDayMoon` to choose a specific light.
- **Sky sphere (optional):** implement `ISkySphereInterface` on a sky dome Blueprint to drive it.
  Sky Atmosphere levels don't need this.
- **Companion light (optional):** set `bAllowCompanionLight` and `CompanionLightClass` in the
  config, then call `SetCompanionLightEnabled(true)` to spawn it on the player pawn.

## Design notes

- `UTickableWorldSubsystem`: reachable from anywhere in the world with no actor references.
- Sun rotation blends with quaternion slerp, so it always takes the short way around.
- Transitions ease in and out, and start from the current on-screen values, so interrupting one never pops.
- The sky light recapture runs once at the end of a transition, not every frame.
- Runs only in game and PIE worlds, never in editor preview worlds.
