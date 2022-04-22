#include <iostream>
#include <conio.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x,y,fruitX,fruitY,score;
enum eDirection{STOP = 0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{
    system("clear");
    for (int i = 0; i < width + 2 ; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < height ; i++)
    {
        for (int j = 0 ; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == x && j == y)
                cout << "O";
            else if (i == fruitX && y == fruitY)
                cout << "F";
            else
                cout << " ";
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2 ; i++)
    {
        cout << "#";
    }
}
void Input(){
    if (_kbhit())
    {
        switch(_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x' :
                gameOver = true;
        }
    }
}
void Logic()
{
    switch (dir)
    {
        case UP:
            y++;
            break;
        case DOWN:
            y--;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
    }
}
int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
}