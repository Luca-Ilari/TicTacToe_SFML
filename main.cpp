#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "sprites.h"

#define WIDTH 400
#define HEIGHT 400

void gameState(int mouseX, int mouseY){
    int playerTurn = 0;
}

bool checkWinner(int arr[][3]){
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

int main() {
    int arr[3][3]={{-1,1,-1},
                   {-1,-1,-1},
                   {-1,0,1}};
    checkWinner(arr);
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "TEST");

    sf::Vertex cross[4] = {
            sf::Vertex(sf::Vector2f(0, 0)),
            sf::Vertex(sf::Vector2f(100, 100)),
            sf::Vertex(sf::Vector2f(100, 0)),
            sf::Vertex(sf::Vector2f(0, 100)),
    };
    sf::Vertex mapGrid[8] = {
            sf::Vertex(sf::Vector2f(125, 0)),
            sf::Vertex(sf::Vector2f(125, HEIGHT)),
            sf::Vertex(sf::Vector2f(275, 0)),
            sf::Vertex(sf::Vector2f(275, HEIGHT)),
            sf::Vertex(sf::Vector2f(0, 125)),
            sf::Vertex(sf::Vector2f(HEIGHT, 125)),
            sf::Vertex(sf::Vector2f(0, 275)),
            sf::Vertex(sf::Vector2f(HEIGHT, 275))
    };

    std::vector<Sprite*> displayMoves;
    displayMoves.push_back(new circleSprite(10.f,10,10));
    displayMoves.push_back(new circleSprite(20.f,100,5));

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
            if (event.mouseButton.button == sf::Mouse::Left){
                //gameState[1]->move(gameState[1]->getX() + 1,gameState[1]->getY());
                //std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                //std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            }
        }

        // draw grid
        window.draw(mapGrid, 8, sf::Lines);
        //draw players X and O on the screen
        for(const auto& obj : displayMoves){
            window.draw(*obj);
        }
        window.display();
    }
    return 0;
}
