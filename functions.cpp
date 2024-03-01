#include <iostream>
#include <vector>
#include "classes/Sprites.h"
#include "definitions.h"
#include "functions.h"

#define WINNING_CONDITION cell1->type() != EMPTY_CELL and (cell1->type() == cell2->type() and cell2->type() == cell3->type())
#define SET_WINNERLINE winnerLine[0] = sf::Vertex(sf::Vector2f(cell1->getX(),cell1->getY()), sf::Color::Red);winnerLine[1] = sf::Vertex(sf::Vector2f(cell3->getX(), cell3->getY()), sf::Color::Red);

bool checkGameEnded(std::vector<std::vector<CustomSprite*>> arr, sf::Vertex *winnerLine){
    CustomSprite *cell1;
    CustomSprite *cell2;
    CustomSprite *cell3;
    for (int i = 0; i < GRID_SIZE; ++i) {
        //check row
        cell1 = arr[0][i];
        cell2 = arr[1][i];
        cell3 = arr[2][i];
        if (WINNING_CONDITION) {
            SET_WINNERLINE;
            return true;
        }
        //check column
        cell1 = arr[i][0];
        cell2 = arr[i][1];
        cell3 = arr[i][2];
        if (WINNING_CONDITION) {
            SET_WINNERLINE
            return true;
        }
    }
    //check diagonals
    cell1 = arr[0][0];
    cell2 = arr[1][1];
    cell3 = arr[2][2];
    if (WINNING_CONDITION) {
        SET_WINNERLINE
        return true;
    }
    cell1 = arr[2][0];
    cell2 = arr[1][1];
    cell3 = arr[0][2];
    if (WINNING_CONDITION) {
        SET_WINNERLINE
        return true;
    }
    //check tie
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            cell1 = arr[i][j];
            if(cell1->type() == EMPTY_CELL){
                return false;
            }
        }
    }
    std::cout << "Parita\n";
    return true;
}

bool leftMousePressed(sf::Event event){
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            return true;
        }
    }
    return false;
}
bool rightMousePressed(sf::Event event){
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Right) {
            return true;
        }
    }
    return false;
}
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
