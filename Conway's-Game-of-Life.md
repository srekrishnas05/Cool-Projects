## Hello, I originally coded Conway's Game of Life in 2023, but came across it on my computer and thought I would share. I used **C++ and SFML!** I'll attach the code down below! ##

```

#include <SFML/Graphics.hpp>
#include <vector>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int ROWS = 50;
const int COLS = 50;
const int CELL_SIZE = WINDOW_WIDTH / COLS;

using Grid = std::vector<std::vector<bool>>;

int countAliveNeighbors(const Grid& grid, int row, int col) {
    int count = 0;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;
            int r = row + dr;
            int c = col + dc;
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && grid[r][c]) {
                ++count;
            }
        }
    }
    return count;
}

Grid nextGeneration(const Grid& grid) {
    Grid newGrid = grid;
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            int neighbors = countAliveNeighbors(grid, r, c);
            if (grid[r][c]) {
                newGrid[r][c] = (neighbors == 2 || neighbors == 3);
            } else {
                newGrid[r][c] = (neighbors == 3);
            }
        }
    }
    return newGrid;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Conway's Game of Life");
    window.setFramerateLimit(10);

    Grid grid(ROWS, std::vector<bool>(COLS, false));
    bool running = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space)
                    running = !running;
                else if (event.key.code == sf::Keyboard::C)
                    grid = Grid(ROWS, std::vector<bool>(COLS, false));
            }

            if (event.type == sf::Event::MouseButtonPressed && !running) {
                int x = event.mouseButton.x / CELL_SIZE;
                int y = event.mouseButton.y / CELL_SIZE;
                if (x >= 0 && x < COLS && y >= 0 && y < ROWS)
                    grid[y][x] = !grid[y][x];
            }
        }

        if (running)
            grid = nextGeneration(grid);

        window.clear(sf::Color::White);
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
                cell.setPosition(c * CELL_SIZE, r * CELL_SIZE);
                cell.setFillColor(grid[r][c] ? sf::Color::Black : sf::Color::White);
                window.draw(cell);
            }
        }
        window.display();
    }

    return 0;
}

```

To run this code, you do need:
1) C++17 or newer
2) SFML 2.5.1
These can be downloaded through brew!

To run this through your terminal on Mac, copy & paste the code into VSCode, save & name the file "conway.cpp," then in your terminal, enter the following script!

```bash
g++ -std=c++17 conway.cpp -o game \
-I/opt/homebrew/opt/sfml@2/include \
-L/opt/homebrew/opt/sfml@2/lib \
-lsfml-graphics -lsfml-window -lsfml-system
```

followed by 
```
./game
```

