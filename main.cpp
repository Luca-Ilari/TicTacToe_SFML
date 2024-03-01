#include <iostream>
#include <vector>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include "classes/Sprites.h"
#include "classes/CircleSprite.h"
#include "classes/CrossSprite.h"
#include "definitions.h"
#include "functions.h"

int main() {
    bool gameFinished = false;
    int tmpX, tmpY;
    float newSpriteX, newSpriteY;
    int playerTurn = 0;

    sf::Vertex winnerLine[2];

    sf::Vertex mapGrid[8] = {
            sf::Vertex(sf::Vector2f(133, 0)),
            sf::Vertex(sf::Vector2f(133, HEIGHT)),
            sf::Vertex(sf::Vector2f(266, 0)),
            sf::Vertex(sf::Vector2f(266, HEIGHT)),
            sf::Vertex(sf::Vector2f(0, 133)),
            sf::Vertex(sf::Vector2f(HEIGHT, 133)),
            sf::Vertex(sf::Vector2f(0, 266)),
            sf::Vertex(sf::Vector2f(HEIGHT, 266))
    };

    //2d matrix used to store players move
    std::vector<std::vector<CustomSprite*>> movesMatrix(GRID_SIZE, std::vector<CustomSprite*>(GRID_SIZE));
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            movesMatrix[i][j] = new CustomSprite(); //Initialize vector with empty obj
        }
    }

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "TRISSSS", sf::Style::Titlebar | sf::Style::Close, settings);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (!gameFinished) {
            if (leftMousePressed(event)) {
                tmpX = cordToMatrix(event.mouseButton.x);
                tmpY = cordToMatrix(event.mouseButton.y);
                newSpriteX = cordToCell(event.mouseButton.x);
                newSpriteY = cordToCell(event.mouseButton.y);

                auto cellClicked = movesMatrix[tmpX][tmpY];

                if (cellClicked->type() == EMPTY_CELL) { //Check if the cell clicked is empty
                    if (playerTurn == 0) {
                        CrossSprite *tmp = new CrossSprite(newSpriteX, newSpriteY);
                        movesMatrix[tmpX][tmpY] = tmp;
                        ++playerTurn;
                    } else {
                        CircleSprite *tmp = new CircleSprite(newSpriteX, newSpriteY);
                        movesMatrix[tmpX][tmpY] = tmp;
                        --playerTurn;
                    }
                }
            }

            gameFinished = checkGameEnded(movesMatrix, winnerLine);
            // draw grid
            window.draw(mapGrid, 8, sf::Lines);

            //Draw game status (X and O) on the screen
            for (int i = 0; i < GRID_SIZE; ++i) {
                for (const auto &obj: movesMatrix[i]) {
                    window.draw(*obj);
                }
            }
        }else{
            window.draw(winnerLine,2, sf::Lines);
            RESET_WINNERLINE //set coordinate of winnerLine to outside the screen
            window.display();

            Sleep(2000);
            window.clear(); //reset screen to start new game
            for (int i = 0; i < GRID_SIZE; ++i) {
                for (int j = 0; j < GRID_SIZE; ++j) {
                    delete movesMatrix[i][j];
                    movesMatrix[i][j] = new CustomSprite;
                }
            }

            playerTurn = 0;
            gameFinished = false;
            std::cout<<"Starting new game\n";
         }
        window.display();
    }
    return 0;
}
