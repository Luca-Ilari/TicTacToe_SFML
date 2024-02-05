#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "sprites.h"

#define WIDTH 400.f
#define HEIGHT WIDTH
#define GRID_SIZE 3
#define CELL_CENTER ((WIDTH/6)*1)     // With window size of 400 its ~= 66
#define SECOND_CELL_CENTER ((WIDTH/6)*3)    // With window size of 400 its ~= 200
#define THIRD_CELL_CENTER ((WIDTH/6)*5)     // With window size of 400 its ~= 333
#define FIRST_CELL_LIMIT ((WIDTH/6)*2)
#define SECOND_CELL_LIMIT ((WIDTH/6)*4)
#define THIRD_CELL_LIMIT WIDTH

int cordToMatrix(int x){
    if(x < FIRST_CELL_LIMIT){
        return 0;
    }
    if(x < SECOND_CELL_LIMIT){
        return 1;
    }
    if(x < THIRD_CELL_LIMIT){
        return 2;
    }

    return -1;
}
float cordToCell(int x){
    if(x < FIRST_CELL_LIMIT){
        return CELL_CENTER;
    }
    if(x < SECOND_CELL_LIMIT){
        return SECOND_CELL_CENTER;
    }
    if(x < THIRD_CELL_LIMIT){
        return THIRD_CELL_CENTER;
    }
    return 0;
}

int main() {
    bool canContinue = true;
    int tmpX, tmpY;
    float newSpriteX, newSpriteY;
    int playerTurn = 0;
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

    std::vector<std::vector<Sprite*>> movesMatrix(GRID_SIZE, std::vector<Sprite*>(GRID_SIZE)); //2d matrix to store players move
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            movesMatrix[i][j] = new Sprite(); //Initialize vector with empty obj
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

        window.clear();
        if (event.type == sf::Event::MouseButtonPressed){
            if (event.mouseButton.button == sf::Mouse::Left) {
                if(canContinue == true) {
                    tmpX = cordToMatrix(event.mouseButton.x);
                    tmpY = cordToMatrix(event.mouseButton.y);
                    newSpriteX = cordToCell(event.mouseButton.x);
                    newSpriteY = cordToCell(event.mouseButton.y);
                    auto cellClicked = movesMatrix[tmpX][tmpY];

                    if (cellClicked->type() == "Sprite") { //Check if the cell clicked is empty
                        if (playerTurn == 0) {
                            movesMatrix[tmpX][tmpY] = new crossSprite(newSpriteX, newSpriteY);
                            ++playerTurn;
                        } else {
                            movesMatrix[tmpX][tmpY] = new circleSprite(newSpriteX, newSpriteY);
                            --playerTurn;
                        }
                    }
                    //check for game end
                    for (int i = 0; i < GRID_SIZE; ++i) {
                        auto cell1 = movesMatrix[0][i];
                        auto cell2 = movesMatrix[1][i];
                        auto cell3 = movesMatrix[2][i];
                        
                        if (cell1->type() == "crossSprite" and cell2->type() == "crossSprite" and cell3->type() == "crossSprite") {
                            std::cout << ++i <<"\n";
                            canContinue = true;
                        }
                        if (cell1->type() == "circleSprite" and cell2->type() == "circleSprite" and cell3->type() == "circleSprite") {
                            std::cout << ++i <<"\n";
                            canContinue = true;
                        }

                    }
                }
            }
        }

        // draw grid
        window.draw(mapGrid, 8, sf::Lines);

        //Draw game status (X and O) on the screen
        for (int i = 0; i < GRID_SIZE; ++i) {
            for(const auto& obj : movesMatrix[i]){
                window.draw(*obj);
            }
        }
        window.display();
    }
    return 0;
}
