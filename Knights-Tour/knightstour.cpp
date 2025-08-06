#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

const int SIZE = 100;
const int BOARD_SIZE = 8;
const int DELAY_MS = 150;

std::vector<std::pair<int, int>> knightMoves = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

bool isValid(int x, int y, const std::vector<std::vector<int>>& board) {
    return x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE && board[y][x] == -1;
}

bool solveTour(int x, int y, int moveNum, std::vector<std::vector<int>>& board) {
    if (moveNum == BOARD_SIZE * BOARD_SIZE)
        return true;

    for (auto move : knightMoves) {
        int nx = x + move.first;
        int ny = y + move.second;
        if (isValid(nx, ny, board)) {
            board[ny][nx] = moveNum;
            if (solveTour(nx, ny, moveNum + 1, board)) return true;
            board[ny][nx] = -1;
        }
    }
    return false;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(SIZE * BOARD_SIZE, SIZE * BOARD_SIZE), "Knight's Tour");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        std::cerr << "Could not load font.\n";
        return -1;
    }

    sf::Texture knightTexture;
    if (!knightTexture.loadFromFile("knight.png")) {
        std::cerr << "Could not load knight image.\n";
        return -1;
    }

    std::vector<std::vector<int>> board(BOARD_SIZE, std::vector<int>(BOARD_SIZE, -1));
    std::vector<sf::Vector2i> tourPath;
    sf::Clock clock;

    bool animating = false;
    int currentStep = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (!animating && event.type == sf::Event::MouseButtonPressed) {
                int col = event.mouseButton.x / SIZE;
                int row = event.mouseButton.y / SIZE;
                std::cout << "Clicked: " << col << ", " << row << "\n";

                board.assign(BOARD_SIZE, std::vector<int>(BOARD_SIZE, -1));
                tourPath.clear();
                board[row][col] = 0;

                if (solveTour(col, row, 1, board)) {
                    tourPath.resize(BOARD_SIZE * BOARD_SIZE);
                    for (int r = 0; r < BOARD_SIZE; ++r)
                        for (int c = 0; c < BOARD_SIZE; ++c)
                            tourPath[board[r][c]] = {c, r};

                    animating = true;
                    currentStep = 0;
                    clock.restart();
                } else {
                    std::cout << "No tour found.\n";
                }
            }
        }

        if (animating && clock.getElapsedTime().asMilliseconds() >= DELAY_MS) {
            currentStep++;
            clock.restart();
            if (currentStep >= tourPath.size())
                animating = false;
        }

        window.clear();

        // Draw chessboard
        for (int row = 0; row < BOARD_SIZE; ++row) {
            for (int col = 0; col < BOARD_SIZE; ++col) {
                sf::RectangleShape cell(sf::Vector2f(SIZE, SIZE));
                cell.setPosition(col * SIZE, row * SIZE);
                cell.setFillColor((row + col) % 2 == 0 ? sf::Color(240, 217, 181) : sf::Color(181, 136, 99));
                window.draw(cell);
            }
        }

        // Draw path lines
        if (currentStep >= 2) {
            sf::VertexArray path(sf::LineStrip, currentStep);
            for (int i = 0; i < currentStep; ++i) {
                path[i].position = sf::Vector2f(tourPath[i].x * SIZE + SIZE / 2, tourPath[i].y * SIZE + SIZE / 2);
                path[i].color = sf::Color::Blue;
            }
            window.draw(path);
        }

        // Draw knight sprite & step numbers
        for (int i = 0; i < currentStep; ++i) {
            sf::Vector2i pos = tourPath[i];

            sf::Sprite knightSprite;
            knightSprite.setTexture(knightTexture);
            knightSprite.setScale((float)SIZE / knightTexture.getSize().x * 0.7f, (float)SIZE / knightTexture.getSize().y * 0.7f);
            knightSprite.setPosition(pos.x * SIZE + 10, pos.y * SIZE + 10);
            window.draw(knightSprite);

            sf::Text text;
            text.setFont(font);
            text.setString(std::to_string(i));
            text.setCharacterSize(18);
            text.setFillColor(sf::Color::White);
            text.setPosition(pos.x * SIZE + 5, pos.y * SIZE + 5);
            window.draw(text);
        }

        window.display();
    }

    return 0;
}
