#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

class snake
{
protected:
    std::vector<std::vector <int>> bodyCoord;
    int size;
    char direction;
    std::vector<int> firstElement;
    std::vector<int> deletedLastElement;
public:
    snake();
    void moveForward();
    //void moveBack();
    void moveRight();
    void moveLeft();
    void grow();
    int getSize();
    char getDirection();
    std::vector<int> GetFirstElement();
    std::vector<std::vector <int>> GetCoord();
};

#endif // SNAKE_H
