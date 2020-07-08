# Game of Life
Recreation of Conway's Game of Life.

## Usage

Game User Interface consists of the following features:

* **Run button**: Starts the game. Update speed is based on the *Speed* slider. Game progresses by X ticks at a time.

* **Stop button**: Stops the game and pauses the timer.

* **Progress by 1 tick button**: Progresses the game by one generation.

* **Progress by x ticks button**: Progresses the game by X generations (editable).

* **Reset button**: Clears all live cells from the grid and resets the game timer.

* **Random seed button**: Re-initialises the game to a random seed by resetting the game, clearing all existing cells and filling the grid with random cells (based on Gaussian distribution).

* **Load bitmap button**: Re-initialises the game to an image. Similarly to seed, it resets the game, clears all existing cells and sets live cells based on black pixels in the image.

* **Update Grid button**: Updates grid dimensions (X and Y) and re-draws the table. Does not stop the running simulation. If Constrain to Grid is enabled, 'kills' all live cells outside the bounds.

* **X edit box**: Allows the user to change grid's X dimension. To apply changes, click **Update Grid**.

* **Y edit box**: Allows the user to change grid's Y dimension. To apply changes, click **Update Grid**.

* **Seed edit box**: Allows the user to input a seed for random pattern generation. Modifying the value resets the game and generates a new random pattern from given seed.

* **Ticks edit box**: Allows the user to modify the number of generations that will be progressed every clock cycle (i.e. intermediate generations will not be drawn). Editing the value stops the game.

* **Constrain to Grid checkbox**: When enabled, constrains cells to the grid by killing anything outside the bounds. When disabled, cells can live outside the bounds and would become visible if the grid size was increased.

* **Zoom slider**: Allows the user to change the displayed grid cells.

* **Speed slider**: Allows the user to change game speed (generations/second).

* **Alive cells display**: Shows the number of alive cells for the current generation.


##To-do list
* Improve multi-thread performance (restructure mutex locks, etc.)
* Finish writing Unit Tests
* Add overflow protections
* Add and enforce grid size (X,Y) limits
* Add and enforce game speed (ticks) limit
* Convert TableView to PixelMap to see if it improves table drawing performance
* Update random seed generation to use non-Gaussian distributions
* Spruce up UI to feel more modern than Windows 2000

## Known issues
* When the game is running with high number of cells (e.g. 500 x 500 random seed) and the user tries to Reset the grid/seed/load bitmap, the grid continues updating. This is possibly due to blocking inside thread calculations.

* Currently, timer is implemented as an open-loop signal transmitter. When running high number of cells, the calculations cannot keep up and timer emits multiple update requests. 

* Issue with QtConcurrent::mappedReduced when using member functions as reducers. Temporary solution is to declare function outside member class.

## UI Improvements:
* Slider click actions have not been implemented
* Mouse drag to move grid not implemented
* Update timer to incorporate some form of feedback loop (see issue above)
