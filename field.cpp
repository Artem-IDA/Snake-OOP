#include "field.h"
#include "apple.h"
#include "snake.h"

field::field()
{
    weight = 60;
    height = 130;
    init();
}

void field::init(){
    for (int i = 0;i < weight; i++) {
        std::vector<char> buff;
        for (int j = 0;j < height; j++) {
            buff.push_back('#');
        }
        matrix.push_back(buff);
    }
    for (int i = 1;i < weight-1;i++) {
        for (int j = 1;j < height-1;j++) {
            matrix[i][j]=' ';
        }
    }
}

int field::getHeight(){
    return height;
}
int field::getWeight(){
    return weight;
}
void field::setWeight(int value)
{
    weight = value;
}
void field::setHeight(int value)
{
    height = value;
}

void field::reload()
{
    matrix.clear();
    init();
}

void field::displayApple(apple &Apple){
    matrix[Apple.getX()][Apple.getY()] = '*';
}
void field::updateApple(apple &Apple, snake &Snake){
    matrix[Apple.getX()][Apple.getY()] = ' ';
    Apple.replace(*this, Snake);
    displayApple(Apple);
}

void field::displaySnake(snake &Snake){
    for(int i = 0; i < Snake.getSize(); i++){
        matrix[Snake.GetCoord()[i][0]][Snake.GetCoord()[i][1]] = '+';
    }
}
void field::clearSnake(snake &Snake){
    for(int i = 0; i < Snake.getSize(); i++){
        matrix[Snake.GetCoord()[i][0]][Snake.GetCoord()[i][1]] = ' ';
    }
}

int field::updateSnake(snake &Snake, apple &Apple, char m){
    bool eaten = false;
    switch (m) {
    case 'w':{
        clearSnake(Snake);
        Snake.moveForward();
        if(eatingCheck(Apple,Snake)){
            eaten = true;
            Snake.grow();
            updateApple(Apple,Snake);
        }
        if(collisionCheck(Snake)){
            system("cls");
            return 0;
        }
        displaySnake(Snake);
        break;
    }
    case 'a':{
        clearSnake(Snake);
        Snake.moveLeft();
        if(eatingCheck(Apple,Snake)){
            eaten = true;
            Snake.grow();
            updateApple(Apple,Snake);
        }
        if(collisionCheck(Snake)){
            system("cls");
            return 0;
        }
        displaySnake(Snake);
        break;
    }
    case 'd':{
        clearSnake(Snake);
        Snake.moveRight();
        if(eatingCheck(Apple,Snake)){
            eaten = true;
            Snake.grow();
            updateApple(Apple,Snake);
        }
        if(collisionCheck(Snake)){
            system("cls");
            return 0;
        }
        displaySnake(Snake);
        break;
    }
    }
    if(eaten)return 2;
    return 1;
}
bool field::eatingCheck(apple &Apple, snake &Snake){
    bool check = false;
    if(Apple.getX() == Snake.GetFirstElement()[0] && Apple.getY() == Snake.GetFirstElement()[1])
       check = true;
    return check;
}
bool field::collisionCheck(snake &Snake){
    bool check = false;
    if (Snake.GetFirstElement()[0] == 0 || Snake.GetFirstElement()[1] == 0 || Snake.GetFirstElement()[0] == getWeight() - 1 || Snake.GetFirstElement()[1] == getHeight() - 1)
        check = true;
    for (int i = 0;i < Snake.getSize();i++){
         if (Snake.GetFirstElement()[0] == Snake.GetCoord()[i][0] && Snake.GetFirstElement()[1] == Snake.GetCoord()[i][1] && i!=0)
             check = true;
    }
    return check;
}

void field::show(){
    for (int i = 0;i < weight; i++) {
        for (int j = 0;j < height; j++) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}
