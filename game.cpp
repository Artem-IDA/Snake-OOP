#include "game.h"
#include "field.h"
#include "apple.h"
#include "snake.h"
#include <iostream>
#include <conio.h>
#include "windows.h"

game::game()
{
    field Field;
    apple Apple;
    snake Snake;
    moveSpeed = 500;
    movesLeft = 0;
    movesRight = 0;
    movesForward = 0;
    allMoves = 0;
    applesEaten = 0;
    points = 0;
    start(Field,Apple,Snake);
}

int game::start(field &Field, apple &Apple, snake &Snake)
{

    while(true)
    {

    int change = displayMainMenu();
    if(change == 1){
        system("cls");
        Field.displayApple(Apple);
        Field.updateApple(Apple, Snake);
        Field.displaySnake(Snake);
        char key;
        bool gameStatus = true;
        while(gameStatus){
            Field.show();
            Sleep(moveSpeed);
            if(kbhit()){
                key = getch();
                switch (key) {
                case 'a':increaseMovesLeft(1);break;
                case 'd':increaseMovesRight(1);break;
                }
            }
            else {
                key = 'w';
                increaseMovesForward(1);
            }
            int i = Field.updateSnake(Snake,Apple,key);
            if(i == 0)
            {
                displayStatistic();
                addToTable();
                system("pause");
                gameStatus = false;
            }
            else if (i == 2)
            {
                increaseApples(1);
            }
            system("cls");
        }
    }
    else if (change == 2){
        displayTopStatistics();
        system("cls");
    }
    else if (change == 3){
        displaySettings(Field);
    }
    else if (change == 4){
        system("cls");
        std::cout << "Thanks for playing!!!" << std::endl;
        std::cout << "Good buye!!!" << std::endl;
        return 0;
    }
    }
}

int game::displayMainMenu()
{
    system("cls");
    int change = 1;
    char key;
    while (true) {
    system("cls");
        for (int i = 0; i < MeinMenu.size(); i++) {
            if(change == i)
            {
                std::cout<< '>';
                std::cout << MeinMenu[i];
                std::cout<< '<' << std::endl;
            }
            else
            std::cout << MeinMenu[i]<< std::endl;
        }
    key = getch();
    switch(key){
    case 'w': change--; if(change < 1) change = MeinMenu.size()-1;break;
    case 's': change++; if(change > MeinMenu.size()-1) change = 1;break;
    case '\r':system("cls"); return change;
    }
    }
}

void game::displaySettings(field &Field)
{
    system("cls");
    int change = 0;
    char key;
    bool flag = true;
    while (flag) {
    system("cls");
        for (int i = 0; i < SettingsMenu.size(); i++) {
            if(change == i)
            {
                std::cout<< '>';
                std::cout << SettingsMenu[i];
            }
            else
            std::cout << SettingsMenu[i];
            switch (i) {
                case 0:std::cout << Field.getWeight() << std::endl; break;
                case 1:std::cout << Field.getHeight() << std::endl; break;
                case 2:std::cout << moveSpeed << std::endl; break;
            }
        }
    key = getch();
    switch(key){
    case 'w': change--; if(change < 0) change = SettingsMenu.size()-1;break;
    case 's': change++; if(change > SettingsMenu.size()-1) change = 0;break;
    case '\r':
        if(change == 0){
            system("cls");
            std::cout<< "Enter new value ->";
            int value;
            std::cin>>value;
            Field.setWeight(value);
            Field.reload();
        }
        else if(change == 1)
        {
            system("cls");
            std::cout<< "Enter new value ->";
            int value;
            std::cin>>value;
            Field.setHeight(value);
            Field.reload();
        }
        else if (change == 2)
        {
            system("cls");
            std::cout<< "Enter new value ->";
            std::cin>>moveSpeed;
        }
        else if(change == 3)
        {
            flag = false;
        }
        break;
    }
    }
}

void game::displayStatistic()
{
    system("cls");
    std::cout << "Statistics for this game" << std::endl << std::endl;
    std::cout << "Moves:" << allMoves << std::endl;
    std::cout << "Apples eaten:" << applesEaten << std::endl;
    std::cout << "Points:" << points << std::endl;
}
void game::displayTopStatistics()
{
    system("cls");
    if(!LeadersBoard.empty())
    {
    for (int i = 0; i < LeadersBoard.size(); i++) {
        std::cout<<"Player name: "<< LeadersBoard[i].Name << std::endl;
        std::cout<<"All moves: "<<LeadersBoard[i].allMoves << std::endl;
        std::cout<<"Apples eaten: "<<LeadersBoard[i].applesEaten << std::endl;
        std::cout<<"Points: "<<LeadersBoard[i].points << std::endl;
        std::cout<<"Moves Forward: "<<LeadersBoard[i].movesForward << std::endl;
        std::cout<<"Moves Right: "<<LeadersBoard[i].movesRight << std::endl;
        std::cout<<"Moves Left: "<<LeadersBoard[i].movesLeft<< std::endl;
        std::cout<<"-----------------------" << std::endl;
    }
    }
    else {
        std::cout<< "Leaders Board is empty!" << std::endl;
        std::cout<< "Someone play me please!" << std::endl;
    }
    system("pause");
}
void game::addToTable()
{
    Player comrade;
    std::cout<< "Enter your name, comrade!" << std::endl;
    std::cin>>comrade.Name;
    comrade.allMoves = allMoves;
    comrade.applesEaten = applesEaten;
    comrade.points = points;
    comrade.movesForward = movesForward;
    comrade.movesRight = movesRight;
    comrade.movesLeft = movesLeft;
    bool flag = true;
    for (int i = 0; i < LeadersBoard.size();i++) {
        if (LeadersBoard[i].Name == comrade.Name)
        {
            if(LeadersBoard[i].points < comrade.points)
                LeadersBoard[i] = comrade;
            flag = false;
        }
    }
    if(flag)
        LeadersBoard.push_back(comrade);
}

void game::increaseMovesForward(int count)
{
    movesForward+=count;
    allMoves+= count;
    points+=5;
}
void game::increaseMovesRight(int count)
{
    movesRight+=count;
    allMoves+= count;
    points+=10;
}
void game::increaseMovesLeft(int count)
{
    movesLeft+=count;
    allMoves+= count;
    points+=10;
}
void game::increaseApples(int count)
{
    applesEaten+=count;
    points+=50;
}

int game::getMovesForward()
{
    return movesForward;
}
int game::getMovesRight()
{
    return movesRight;
}
int game::getMovesLeft()
{
    return movesLeft;
}
int game::getApples()
{
    return applesEaten;
}
long game::getPoints()
{
    return points;
}
int game::getAllMoves()
{
    return allMoves;
}
