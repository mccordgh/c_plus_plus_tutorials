#include <iostream>
#include <curses.h>

using namespace std;


const int worldHeight = 16, worldWidth = 32;
int playerX = 4, prevX = 4, playerY = 4, prevY = 4;
const string padding = "\t\t", player = "O", item = "u", monster = "X";

// WINDOW * win = newwin(worldHeight, worldWidth, 4, 4);

bool gameOver = false;

// #define KEY_UP 72
// #define KEY_DOWN 80
// #define KEY_LEFT 75
// #define KEY_RIGHT 77

void drawWorld(), addItems(), getInput();

string world[worldHeight][worldWidth] = {
    {"*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
    {"*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
};

int main()
{
    initscr();
    cbreak();
    noecho();
    nonl();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    // attron(COLOR_PAIR(2));
    border(0, 0, 0, 0, 0, 0, 0, 0);

    // world[playerStartY][playerStartX] = player;
    // addItems();

    // while (gameOver == false)
    while (true)
    {
        // move(playerY, playerX);
        // addch(' ' | COLOR_CYAN);
        // cout << "REFRESH" << endl;
        getInput();

        move(playerY, playerX);
        // addch('O' | COLOR_CYAN);

        refresh();
        // drawWorld();
        // checkCollisions();
        // movePlayer();
    }
};

void addItems()
{
    world[4][8] = item;
    world[4][24] = item;
    world[12][8] = item;
    world[12][24] = item;
}

void drawWorld()
{
    cout << endl;

    for (int x = 0; x < worldHeight; x++)
    {
        cout << padding;

        for (int y = 0; y < worldWidth; y++)
        {
            cout << world[x][y];
        }

        cout << endl;
    }

    cout << endl;
}

void getInput()
{
    int input = 0;
    input = getch();

    if (input == ERR)
    {
        //
    } else {
        switch(input) {
            case KEY_UP:
                playerY -= 1;
                break;
            case KEY_DOWN:
                playerY += 1;
                break;
            case KEY_LEFT:
                playerX -= 1;
                break;
            case KEY_RIGHT:
                playerX += 1;
                break;
            case 13: // ENTER/RETURN KEY
                // delwin(win);
                endwin();
                exit(0);
            default:
                // cout << endl << input << endl;  // not arrow
                break;
            }
    }
}