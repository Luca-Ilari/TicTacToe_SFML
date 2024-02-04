#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "sprites.h"

#define WIDTH 400.f
#define HEIGHT WIDTH
#define GRID_SIZE 3
#define CELL_SIZE ((WIDTH/6)*2)
#define CELL_CENTER ((WIDTH/6)*1)     // With window size of 400 its ~= 66
#define SECOND_CELL_CENTER ((WIDTH/6)*3)    // With window size of 400 its ~= 200
#define THIRD_CELL_CENTER ((WIDTH/6)*5)     // With window size of 400 its ~= 333
#define FIRST_CELL_LIMIT ((WIDTH/6)*2)
#define SECOND_CELL_LIMIT ((WIDTH/6)*4)
#define THIRD_CELL_LIMIT WIDTH

bool checkWinner(int arr[][3]){  // MUST SIMPLIFY
    // croce = 1, cerchio = -1
    int x;
    //check rows
    for (int i = 0; i < 3; ++i) {
        x = 0;
        for (int j = 0; j < 3; ++j) {
            x += arr[i][j];
        }
        if (x == 3){
            std::cout << "Croce vince righa " << ++i;
            return true;
        }
        if (x == -3){
            std::cout << "Cerchio vince righa " << ++i;
            return true;
        }
    }
    //check column
    for (int i = 0; i < 3; ++i) {
        x = 0;
        for (int j = 0; j < 3; ++j) {
            x += arr[j][i];
        }
        if (x == 3){
            std::cout << "Croce vince colonna " << ++i;
            return true;
        }
        if (x == -3){
            std::cout << "Cerchio vince colonna " << ++i;
            return true;
        }
    }
    //check diag
    x = 0;
    for (int j = 0; j < 3; ++j) {
        x += arr[j][j];
    }
    if (x == 3){
        std::cout << "Croce vince diagonale 1";
        return true;
    }
    if (x == -3){
        std::cout << "Cerchio vince diagonale 1";
        return true;
    }
    x = 0;
    int jj = 2;
    for (int j = 0;  j < 3; ++j) {
        x += arr[j][jj];
        --jj;
    }
    if (x == 3){
        std::cout << "Croce vince diagonale 2";
        return true;
    }
    if (x == -3){
        std::cout << "Cerchio vince diagonale 2";
        return true;
    }

    return false;
}

int cordToMatrix(float x){
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

bool isEmpty(int x){
    if(x == 0) return true;
    return false;
}

int main() {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "TRISSSS", sf::Style::Titlebar | sf::Style::Close, settings);

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
    std::vector<std::vector<Sprite*>> displayMoves(GRID_SIZE, std::vector<Sprite*>(GRID_SIZE)); //2d matrix to store players move
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            displayMoves[i][j] = new Sprite();
        }
    }

    int p=1;
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
                //std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                //std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                /* STUPID STUFF MUST FIX
                 for (int i = 0; i < GRID_SIZE; ++i) {
                    for (int j = 0; j < GRID_SIZE; ++j) {
                        std::cout << arr[i][j];
                    }
                    std::cout << "\n";
                }
                std::cout <<"\n";

                if (p == -1){
                    if(event.mouseButton.x < 133){
                        if(event.mouseButton.y < 133){
                            if(arr[0][0] == 0){
                                displayMoves.push_back(new circleSprite(66,66));
                                arr[0][0] = -1;
                                p += 2;
                            }
                        }else if(event.mouseButton.y < 266){
                            if(arr[1][0] == 0) {
                                displayMoves.push_back(new circleSprite(66, 200));
                                arr[1][0] = -1;
                                p += 2;
                            }
                        }else if(event.mouseButton.y < 400){
                            if(arr[2][0] == 0) {
                                displayMoves.push_back(new circleSprite(66,333));
                                arr[2][0] = -1;
                                p += 2;
                            }
                        }
                    }else if(event.mouseButton.x < 266){
                        if(event.mouseButton.y < 133){
                            if(arr[0][1] == 0) {
                                displayMoves.push_back(new circleSprite(200, 66));
                                arr[0][1] = -1;
                                p += 2;
                            }
                        }else if(event.mouseButton.y < 266){
                            if(arr[1][1] == 0) {
                                displayMoves.push_back(new circleSprite(200, 200));
                                arr[1][1] = -1;
                                p += 2;
                            }
                        }else if(event.mouseButton.y < 400){
                            if(arr[2][1] == 0) {
                                displayMoves.push_back(new circleSprite(200, 333));
                                arr[2][1] = -1;
                                p += 2;
                            }
                        }
                    }else if(event.mouseButton.x < 400){
                        if(event.mouseButton.y < 133){
                            if(arr[0][2] == 0) {
                                displayMoves.push_back(new circleSprite(333, 66));
                                arr[0][2] = -1;
                                p += 2;
                            }
                        }else if(event.mouseButton.y < 266){
                            if(arr[1][2] == 0) {
                                displayMoves.push_back(new circleSprite(333,200));
                                arr[1][2] = -1;
                                p += 2;
                            }

                        }else if(event.mouseButton.y < 400){
                            if(arr[2][2] == 0) {
                                displayMoves.push_back(new circleSprite(333, 333));
                                arr[2][2] = -1;
                                p += 2;
                            }
                        }
                    }
                }else{
                    if(event.mouseButton.x < 133){
                        if(event.mouseButton.y < 133){
                            if(arr[0][0] == 0){
                                displayMoves.push_back(new crossSprite(66,66));
                                arr[0][0] = 1;
                                p -= 2;
                            }
                        }else if(event.mouseButton.y < 266){
                            if(arr[1][0] == 0) {
                                displayMoves.push_back(new crossSprite(66, 200));
                                arr[1][0] = 1;
                                p -= 2;
                            }
                        }else if(event.mouseButton.y < 400){
                            if(arr[2][0] == 0) {
                                displayMoves.push_back(new crossSprite(66,333));
                                arr[2][0] = 1;
                                p -= 2;
                            }
                        }
                    }else if(event.mouseButton.x < 266){
                        if(event.mouseButton.y < 133){
                            if(arr[0][1] == 0) {
                                displayMoves.push_back(new crossSprite(200, 66));
                                arr[0][1] = 1;
                                p -= 2;
                            }
                        }else if(event.mouseButton.y < 266){
                            if(arr[1][1] == 0) {
                                displayMoves.push_back(new crossSprite(200, 200));
                                arr[1][1] = 1;
                                p -= 2;
                            }
                        }else if(event.mouseButton.y < 400){
                            if(arr[2][1] == 0) {
                                displayMoves.push_back(new crossSprite(200, 333));
                                arr[2][1] = 1;
                                p -= 2;
                            }
                        }
                    }else if(event.mouseButton.x < 400){
                        if(event.mouseButton.y < 133){
                            if(arr[0][2] == 0) {
                                displayMoves.push_back(new crossSprite(333, 66));
                                arr[0][2] = 1;
                                p -= 2;
                            }
                        }else if(event.mouseButton.y < 266){
                            if(arr[1][2] == 0) {
                                displayMoves.push_back(new crossSprite(333,200));
                                arr[1][2] = 1;
                                p -= 2;
                            }
                        }else if(event.mouseButton.y < 400){
                            if(arr[2][2] == 0) {
                                displayMoves.push_back(new crossSprite(333, 333));
                                arr[2][2] = 1;
                                p -= 2;
                            }
                        }
                    }
                }*/
                //checkWinner(arr);
            }
        }

        // draw grid
        window.draw(mapGrid, 8, sf::Lines);

        //Draw game status (X and O) on the screen
        for(const auto& obj : displayMoves[0]){
            window.draw(*obj);
        }
        window.display();
    }
    return 0;
}
