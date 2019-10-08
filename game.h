#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>

class field;
class apple;
class snake;

struct Player{
    std::string Name;
    int movesForward;
    int movesRight;
    int movesLeft;
    int applesEaten;
    long int points;
    int allMoves;
};

class game
{
private:
    int movesForward;
    int movesRight;
    int movesLeft;
    int applesEaten;
    long int points;
    int allMoves;

    short int moveSpeed;

    std::vector<std::string> MeinMenu = {
        "Snake",
        "Start",
        "Statistics",
        "Settings",
        "Exit"
    };
    std::vector<std::string> SettingsMenu = {
        "Weight field: ",
        "Height field: ",
        "Move speed: ",
        "Exit"
    };
    std::vector<Player> LeadersBoard;
public:
    game();

    int start(field &Field, apple &Apple, snake &Snake);
    int displayMainMenu();
    void displaySettings(field &Field);

    void displayStatistic();
    void displayTopStatistics();
    void addToTable();

    void increaseMovesForward(int count);
    void increaseMovesRight(int count);
    void increaseMovesLeft(int count);
    void increaseApples(int count);

    int getMovesForward();
    int getMovesRight();
    int getMovesLeft();
    int getApples();
    long int getPoints();
    int getAllMoves();
};

#endif // GAME_H
