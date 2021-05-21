Snake Game
Video Demo:  <https://www.youtube.com/watch?v=jpqVB7lrrvM>

Hello guys, my name is Pedro, I am from Brazil and this is my final project. I tried to learn more
about game developing using python since CS50's class about it,
and ended up getting into developing games in this language,
wich was pretty cool.
                To start I had to create
widgets, that could manipulate content,
 so I created a window to display the whole game, inside of wich I created a label, that is
in charge of displaying the score whenever the snake eats the food, and increases it's size,
and a canvas that is in charge of actually displaying the whole dinamic of my game.
                This is the classic snake game, the challenge to develop this was to learn how in code we can
make objects move in the screen so I started learning all about displaying widgets with python,
using the tkinter library.
                I used object-oriented programming to manipulate the "food" in the game, wich is a oval ,
that has to be generated randomly every time someone run the code, that could be done using the
random library.
                I specifically created a class for the Snake and another one for the Food. So I could organize
it's attributes and methods for each one separated, and than use it later in the code.
                What I did to make the snake move, was creating a function that will increase and decrease
the coordinates in the x axis and y axis, when a command from keybord is toggled on, like going up, down,
left or right.
                I thought that many times I could use the snake's speed, so I created a constant, that
value's can be changed only one time in the code, not everytime it appears.
It was kind of a design decision, but it is funnier to those who play and want to
make the experience easier or harder.
                I had to check all the types of colisions that could end the game, so I created a function
to check it, that basically checks if the coordinates of whatever it touches, that shouldn't have,
coincides.
                And finally I created a function to end the game, so every time you loose, it is displayed "game over"
in the screen, that literaly works deleting everything that is currently in the canvas, that is
the same principle used if I was to make a text editor for example, and wanted to delete everything
or in other words, making it disappear from the screen.
                This was my Snake Game project using python.
