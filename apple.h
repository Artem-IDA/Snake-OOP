#pragma once

#include <iostream>
#include <ctime>

class field;
class snake;
class apple
{
protected:
    int x, y;
public:
    apple();
    void replace(field &Field, snake &Snake);
    int getX();
    int getY();
};

