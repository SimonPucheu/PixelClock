# PixelClock
This is a project to recreate the clock of the [Freebox Revolution](https://www.free.fr/freebox/freebox-revolution/)

## Presentation
### Numbers
All numbers are made up of 5 by 5 pixels.

This is a 5:

|   |   |   |   |   |
|:-:|:-:|:-:|:-:|:-:|
| 1 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 | 0 |
| 1 | 1 | 1 | 1 | 1 |
| 0 | 0 | 0 | 0 | 1 |
| 1 | 1 | 1 | 1 | 1 |

These are disposed like that (12h34):

|       | L | R |
|:------|:-:|:-:|
| **T** | 1 | 2 |
| **B** | 3 | 4 |

### Transitions
During a change of time (minutes or hours), the numbers come out on the left or on the right according to their positions (right or left column). New numbers enter from above or below (top or bottom line).

#### Step 1

|   | 2 | 0 |   |
|:-:|:-:|:-:|:-:|
|   | 1 | 9 |   |
|   | 5 | 9 |   |
|   | 0 | 0 |   |

#### Step 2

|   | 2 | 0 |   |
|:-:|:-:|:-:|:-:|
| 1 |   |   | 9 |
| 5 |   |   | 9 |
|   | 0 | 0 |   |

#### Step 3

|   |   |   |   |
|:-:|:-:|:-:|:-:|
|   | 2 | 0 |   |
|   | 0 | 0 |   |
|   |   |   |   |

## Branches
### [main (current)](https://github.com/6moon9/PixelClock/)
Contains the presentation of the project.

### [arduino](https://github.com/6moon9/PixelClock/tree/arduino/)
Contains the source code for the arduino project.

### [chrome-extension](https://github.com/6moon9/PixelClock/tree/chrome-extension/)
Contains the source code for the chrome extension.

### [web](https://github.com/6moon9/PixelClock/tree/web/)
Contains the source code for the [webpage](https://6moon9.github.io/PixelClock/). This is the branch that is deployed by github pages.