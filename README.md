# PixelClock
This is a project to recreate the clock of the [Freebox Revolution](https://www.free.fr/freebox/freebox-revolution/)

## Presentation
This is the arduin source code.

### Software
The [`ino`](./src/PixelClock/PixelClock.ino) file depends of these two librairies:
* [Screen](https://github.com/6moon9/Screen) The librairy containing all functions to draw numbers on the screen
* [Time](https://github.com/6moon9/Time) Allow you to use and manipulate time on an arduino without any hardware

### Harware
* Arduino board (Uno, Mega, Nano, no matter)
* TFT Display 128*160

## Branches
### [main](https://github.com/6moon9/PixelClock/)
Contains the presentation of the project.

### [arduino (current)](https://github.com/6moon9/PixelClock/tree/arduino/)
Contains the source code for the arduino project.

### [chrome-extension](https://github.com/6moon9/PixelClock/tree/chrome-extension/)
Contains the source code for the chrome extension.

### [web](https://github.com/6moon9/PixelClock/tree/web/)
Contains the source code for the [webpage](https://6moon9.github.io/PixelClock/). This is the branch that is deployed by github pages.