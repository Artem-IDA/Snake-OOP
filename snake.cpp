#include "snake.h"

snake::snake()
{
    size = 3;
    bodyCoord = {{1,3},{1,2},{1,1}};
    direction = 'n';
    deletedLastElement = {1,1};
    firstElement = {1,3};
}

void snake::moveForward(){
    deletedLastElement[0] = bodyCoord[size-1][0];
    deletedLastElement[1] = bodyCoord[size-1][1];
    bodyCoord.pop_back();
    std::vector<std::vector<int>> tempBody;
    /*std::vector<int> firstElement;*/
    switch (direction) {
    case 'n':firstElement = {bodyCoord[0][0], bodyCoord[0][1] + 1};break;
    case 's':firstElement = {bodyCoord[0][0], bodyCoord[0][1] - 1};break;
    case 'w':firstElement = {bodyCoord[0][0] - 1, bodyCoord[0][1]};break;
    case 'e':firstElement = {bodyCoord[0][0] + 1, bodyCoord[0][1]};break;
    }
    tempBody.push_back(firstElement);
    for (int i = 0;i < size - 1; i++) {
        std::vector <int> element;
        element.push_back(bodyCoord[i][0]);
        element.push_back(bodyCoord[i][1]);
        tempBody.push_back(element);
    }
    bodyCoord = tempBody;
}
/*void snake::moveBack(){
    bodyCoord.pop_back();
    std::vector<std::vector<int>> tempBody;
    std::vector<int> firstElement;
    switch (direction) {
    case 'n':firstElement = {bodyCoord[0][0], bodyCoord[0][1] - 1};direction = 'n';break;
    case 's':firstElement = {bodyCoord[0][0], bodyCoord[0][1] + 1};direction = 's';break;
    case 'w':firstElement = {bodyCoord[0][0] + 1, bodyCoord[0][1]};direction = 'w';break;
    case 'e':firstElement = {bodyCoord[0][0] - 1, bodyCoord[0][1]};direction = 'e';break;
    }
    tempBody.push_back(firstElement);
    for (int i = 0;i < size; i++) {
        std::vector <int> element;
        element.push_back(bodyCoord[i][0]);
        element.push_back(bodyCoord[i][1]);
        tempBody.push_back(element);
    }
    bodyCoord = tempBody;
}*/
void snake::moveLeft(){
    deletedLastElement[0] = bodyCoord[size-1][0];
    deletedLastElement[1] = bodyCoord[size-1][1];
    bodyCoord.pop_back();
    std::vector<std::vector<int>> tempBody;
    /*std::vector<int> firstElement;*/
    switch (direction) {
    case 'n':firstElement = {bodyCoord[0][0] - 1, bodyCoord[0][1]};direction = 'w';break;
    case 's':firstElement = {bodyCoord[0][0] + 1, bodyCoord[0][1]};direction = 'e';break;
    case 'w':firstElement = {bodyCoord[0][0], bodyCoord[0][1] - 1};direction = 's';break;
    case 'e':firstElement = {bodyCoord[0][0], bodyCoord[0][1] + 1};direction = 'n';break;
    }
    tempBody.push_back(firstElement);
    for (int i = 0;i < size - 1; i++) {
        std::vector <int> element;
        element.push_back(bodyCoord[i][0]);
        element.push_back(bodyCoord[i][1]);
        tempBody.push_back(element);
    }
    bodyCoord = tempBody;
}
void snake::moveRight(){
    deletedLastElement[0] = bodyCoord[size-1][0];
    deletedLastElement[1] = bodyCoord[size-1][1];
    bodyCoord.pop_back();
    std::vector<std::vector<int>> tempBody;
    /*std::vector<int> firstElement;*/
    switch (direction) {
    case 'n':firstElement = {bodyCoord[0][0] + 1, bodyCoord[0][1]};direction = 'e';break;
    case 's':firstElement = {bodyCoord[0][0] - 1, bodyCoord[0][1]};direction = 'w';break;
    case 'w':firstElement = {bodyCoord[0][0], bodyCoord[0][1] + 1};direction = 'n';break;
    case 'e':firstElement = {bodyCoord[0][0], bodyCoord[0][1] - 1};direction = 's';break;
    }
    tempBody.push_back(firstElement);
    for (int i = 0;i < size - 1; i++) {
        std::vector <int> element;
        element.push_back(bodyCoord[i][0]);
        element.push_back(bodyCoord[i][1]);
        tempBody.push_back(element);
    }
    bodyCoord = tempBody;
}

void snake::grow()
{
    bodyCoord.push_back(deletedLastElement);
    size++;
}

int snake::getSize(){
    return size;
}
char snake::getDirection()
{
    return direction;
}

std::vector<int> snake::GetFirstElement()
{
    return firstElement;
}
std::vector<std::vector <int>> snake::GetCoord(){
    std::vector<std::vector <int>> coord = bodyCoord;
    return coord;
}

