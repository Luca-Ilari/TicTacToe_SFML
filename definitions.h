#define WIDTH 400.f
#define HEIGHT WIDTH
#define GRID_SIZE 3
#define CELL_CENTER ((WIDTH/6)*1)     // With window size of 400 its ~= 66
#define SECOND_CELL_CENTER ((WIDTH/6)*3)    // With window size of 400 its ~= 200
#define THIRD_CELL_CENTER ((WIDTH/6)*5)     // With window size of 400 its ~= 333
#define FIRST_CELL_LIMIT ((WIDTH/6)*2)
#define SECOND_CELL_LIMIT ((WIDTH/6)*4)
#define THIRD_CELL_LIMIT WIDTH

#define EMPTY_CELL "CustomSprite"
#define CROSS "CrossSprite"
#define CIRCLE "CircleSprite"

#define RESET_WINNERLINE winnerLine[0] = sf::Vertex(sf::Vector2f (-1,-1)); winnerLine[1] = sf::Vertex(sf::Vector2f (-1,-1));