# UE4-Sim-Motion-Controller
Simulation of movement and rotation of a motion controller component using the keyboard.
https://www.niveisalis.com/2016/11/28/working-with-the-vive-without-a-vive/

# Controls of the controller
To move the controller the following controls are currently set up:

| Button | Action |
|:-:|:-:|
| J | Move the controller to the left |
| L | Move the controller to the right |
| I | Move the controller forwards |
| , (comma) | Move the controller back |
| U | Move the controller up |
| O | Move the controller down |
| H | Rotate the controller positively along the X axis. |
| T | Rotate the controller positively along the Y axis. |
| G | Rotate the controller positively along the Z axis. |
| Y | Rotate the controller negatively along the X axis. |
| R | Rotate the controller negatively along the Y axis. |
| F | Rotate the controller negatively along the Z axis. |

# Before using
In the **SimulatedMotionController.cpp** file, in the constructor, the position is set to (200.0, 0.0, 0.0).
When using in another project, it should be set at (0.0,0.0,0.0) to avoid any tracking problems.

# Usage with actual controllers
If used with actual controllers, you can toggle the ShouldBeSimulated flag to override the custom behaviour
and revert back to the function of the original controller.
