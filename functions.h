#ifndef TICTACTOE_SFML_FUNCTIONS_H
#define TICTACTOE_SFML_FUNCTIONS_H

bool checkGameEnded(std::vector<std::vector<CustomSprite*>> arr, sf::Vertex *winnerLine);
bool leftMousePressed(sf::Event event);
bool rightMousePressed(sf::Event event);
int cordToMatrix(int x);
float cordToCell(int x);

#endif //TICTACTOE_SFML_FUNCTIONS_H
