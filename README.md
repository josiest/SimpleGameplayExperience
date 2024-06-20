# Simple Gameplay Experience Plugin

The Simple Gameplay Experience Plugin allows you to rapidly bootstrap
your game using data-oriented design. If you're familiar with Unreal's
[Lyra Starter Game](https://dev.epicgames.com/community/learning/paths/Z4/lyra-starter-game),
this is pretty much dumbed-down version of the
[Gameplay Experiences](https://x157.github.io/UE5/LyraStarterGame/Experience/)
there. The project is still in its early stages of development, and
new features will likely be rapidly added.

![Snapshot of GameplayExperience and PawnData assets](Resources/Gameplay-Experience-And-Pawn-Data.png)

## Quickstart

Here's the checklist to quickly get started:
- Clone this repository into the `Plugins` folder in your project.
- In your `World Settings` change the `GameModeOverride` to
  `SimpleExperienceGameMode`
![Screenshot of where to find the Game Mode Override in World Settings](Resources/Experience-Game-Mode.png)
- Fire up the editor and navigate to `Edit > Project Settings`
- Under Game, look for `Simple Experience Settings` or search  for
  `Default Gameplay Experience`
- Set the `Default Gameplay Experience` to `EXP_DefaultExperience`
![Screenshot of the Default Experience in Project Settings](Resources/Default-Experience.png)

This will set up the most basic gameplay experience and pawn data
using a simple example game-mode. If you need to write your own game
mode, or if you have a more complex project set-up,
[see the documentation](https://github.com/josiest/SimpleGameplayExperience/wiki) for how to use the various components to
set up the gameplay experiences with your own code.

To see more complex examples of gameplay experiences in action, check out
[Lyra, Simplified](https://github.com/josiest/LyraSimplified/tree/main).

## Motivation

Lyra's Gameplay Experiences seem like a really cool data oriented
approach to setting up a game. The only issue is that the feature is
pretty deeply integrated into Lyra's codebase. On top of this, it has
dependencies on the multiplayer and gameplay ability systems. If you're
working on an incredibly small-scoped 2D game with very simple
mechanics, setting up these requirements and dependencies doesn't make
a whole lot of sense. But if you still want to work with the
data-oriented experiences, this plugin hopefully satisfies your needs!