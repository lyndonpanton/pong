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

### MVP

#### Gameplay

- [x] Draw the divider
- [x] Draw ball
- [x] Move ball in the pre-defined direction on start
- [x] Handle collisions between ball and horizontal edges
- [ ] Move ball in random direction (within boundary)
- [ ] Move ball on keypress (i.e., spacebar)
- [ ] Handle collisions between ball and vertical edges
    - [ ] Give players a "points" member
    - [ ] The relevant player's "points" member should be updated
- [ ] Handle collisions between a ball and a paddle
    - [ ] Change velocity of ball based on what edge of paddle was hit
        - [x] Hitting "front" of paddle should reverse the x velocity
        of the ball
        - [ ] Hitting top or bottom of padding should reverse the y
        velocity of the ball
            - [ ] Prioritise front of paddle over top and bottom of paddle
        - [ ] Change velocity of ball based on what section of "front"
        edge was hit
- [x] Game can be won (default: 10 points)
- [x] Game can be paused and unpaused (default: Escape key)
- [ ] Game can be restarted (default: R key)

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

- [ ] Mouse cursor
- [ ] Window icon

#### Modifications

- [ ] Game
    - [ ] Target score
    - [ ] Is Playing
- [ ] Paddle
    - [ ] Colour of a paddle can be modified
    - [ ] Height of a paddle can be modified
    - [ ] Name of a player can be modified
    - [ ] Speed of a paddle can be modified
- [ ] Ball
    - [ ] Colour of a ball can be modified
    - [ ] Point count of a ball can be modified
    - [ ] Radius of a ball can be modified
    - [ ] Velocity of a ball can be modified

#### Maintenance

- [ ] Create an Entity class
- [ ] Store the players and ball in a collection
- [ ] Modify the Player and Ball classes
- [ ] Modify the draw and update methods
- [ ] Use a configuration file
    - [ ] Window properties
    - [ ] Font properties
    - [ ] Game properties
    - [ ] Divider properties
    - [ ] Ball properties
    - [ ] Player one properties
    - [ ] Player two properties

### Extended

- [ ] Keys for actions can be modified
- [ ] Score system can be modified
- [ ] Players can switch between score mode and timer mode

#### Window Extended

#### Modifications Extended

## Notes

## Credits

## References
