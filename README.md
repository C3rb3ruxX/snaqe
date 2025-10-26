# Snake Game
Classic snake game

### How the game works
The program stores a matrix of numbers where all information is stored.

Number 0 represents an empty space.
A diferent number can represent two things:
 * If it is between 1 and 127 (this will change in the future), the snake ocupies that position.
 * If its not an snake position, its an apple.

For each tick a new position for the snake head is calculated by its direction and It is represented by the length of the snake.
That logic allows us to move the snake by subtracting 1 to all values between 1 and 127.

