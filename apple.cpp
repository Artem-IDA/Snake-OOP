#include "apple.h"
#include "field.h"
#include "snake.h"

apple::apple()
{
    x = y = 1;
}

void apple::replace(field &Field, snake &Snake)
{
    srand(time(0));
    bool flag = false;
    do{
    flag = false;
    x = 1 + rand() % (Field.getWeight() - 2);
    y = 1 + rand() % (Field.getHeight() - 2);
    for(int i = 0; i < Snake.getSize(); i++){
        if(x == Snake.GetCoord()[i][0] && y == Snake.GetCoord()[i][1])
            flag = true;
    }
    }while(flag == true);
}

int apple::getX(){
    return x;
}
int apple::getY(){
    return y;
}
