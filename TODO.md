# TODO

## Description

A list of tasks related to the complete of this pong project.

## Content

### Topics

- [MVP](#mvp)
    - [Gameplay](#gameplay)
    - [UI](#ui)
    - [Audio](#audio)
    - [Assets](#assets)
    - [Scenes](#scenes)
    - [Window](#window)
    - [Modifications](#modifications)
    - [Maintenance](#maintenance)
- [Extended](#extended)
    - [Window Extended](#window-extended)
    - [Modifications Extended](#modifications-extended)
- [Bugs](#bugs)

### MVP

#### Gameplay

- [x] Draw the divider
- [x] Draw ball
- [x] Move ball in the pre-defined direction on start
- [x] Handle collisions between ball and horizontal edges
- [ ] Move ball with a random velocity on start (within range)
    - [ ] Direction should be random (within range)
    - [ ] Speed should be random (within range)
- [x] Move ball on keypress on start (default key: Spacebar)
- [x] Handle collisions between ball and vertical edges
    - [x] Give players a "points" member
    - [x] The relevant player's "points" member should be updated
- [ ] Handle collisions between a ball and a paddle
    - [ ] Change velocity of ball based on what edge of paddle was hit
        - [x] Hitting "front" of paddle should reverse the x velocity
        of the ball
        - [x] Hitting top or bottom of padding should reverse the y
        velocity of the ball
            - [x] Prioritise front of paddle over top and bottom of paddle
    - [ ] Change velocity of ball based on what section of "front" edge
    was hit
- [x] Game can be won (default: 10 points)
- [x] Game can be paused and unpaused (default key: Escape)
- [x] Game can be restarted (default key: R)

#### UI

- [x] Display the score for each player
- [x] Display message with winner name when game finishes
- [x] Display message whilst the game is paused

#### Audio

- [ ] Game starts
- [ ] Ball collides with top or bottom edge
- [ ] Ball collides with player 1
- [ ] Ball collides with player 2
- [ ] Player 1 scores a point
- [ ] Player 2 scores a point
- [ ] A player wins

#### Assets

#### Scenes

#### Window

- [x] Game should use a custom mouse cursor
- [x] Game should a custom window icon
    - [x] Icon for open window
    - [x] Icon for dock

#### Modifications

- [x] Game
    - [x] Target score
    - [x] Is playing
- [ ] Paddle
    - [x] Colour
    - [x] Height
    - [ ] Position
    - [ ] Initial position
    - [ ] Name
    - [x] Speed
- [x] Ball
    - [x] Colour
    - [x] Point count
    - [x] Radius
    - [x] Velocity

#### Maintenance

- [ ] Create an Entity class
- [ ] Store the players and ball in a collection
- [ ] Modify the Player and Ball classes
- [ ] Modify the draw and update methods
- [ ] Create a function for drawing imgui components
- [ ] Use a configuration file
    - [x] Window properties (size, title, resizable cursor path)
    - [x] Font properties (path, size, red value, green value, blue value)
    - [x] Game properties
    - [x] Divider properties
    - [x] Ball properties
    - [x] Player one properties
    - [x] Player two properties
    - [ ] Modification ranges

### Extended

#### Window Extended

#### Modifications Extended

- [ ] Keys for actions can be modified
- [ ] Players can switch between score mode and timer mode

### Bugs

- [ ] Custom mouse cursor displays under top window bar
- [ ] Custom mouse cursor displays under imgui window
- [ ] Pause message is not displaying

## Notes

## Credits

## References
