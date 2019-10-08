#pragma once

#include <iostream>
#include <vector>

class apple;
class snake;
class field
{
protected:
    int weight, height;
    std::vector<std::vector<char>> matrix;

    void init ();
public:
    field();
    int getWeight();
    int getHeight();
    void setWeight(int i);
    void setHeight(int i);
    void reload();
    void displayApple(apple &Apple);
    void updateApple(apple &Apple, snake &Snake);
    void displaySnake (snake &Snake);
    void clearSnake (snake &Snake);
    int updateSnake(snake &Snake, apple &Apple, char m);
    bool eatingCheck(apple &Apple, snake &Snake);
    bool collisionCheck(snake &Snake);
    void show ();
};

