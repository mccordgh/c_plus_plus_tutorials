#include <iostream>
#include <curses.h>

using namespace std;


const int worldHeight = 16, worldWidth = 32;
int playerX = 4, prevX = 4, playerY = 4, prevY = 4, score = 0;
// const char * player = "O", item = "u", monster = "X";

// WINDOW * win = newwin(worldHeight, worldWidth, 4, 4);

bool gameOver = false;

// #define KEY_UP 72
// #define KEY_DOWN 80
// #define KEY_LEFT 75
// #define KEY_RIGHT 77

void drawWorld(), addItems(), getInput(), updateScore(), checkCollisions();

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
    addItems();

    // while (gameOver == false)
    updateScore();

    while (true)
    {
        getInput();

        // move(prevY, prevX);
        // addch('x' | COLOR_CYAN);

        move(playerY, playerX);

        checkCollisions();

        addstr("0");
        move(0, 0);

        refresh();
        // drawWorld();
        // checkCollisions();
        // movePlayer();
    }
};

void checkCollisions()
{
    
}

void addItems()
{
    move(4, 8);
    addstr("u");
    move(4, 24);
    addstr("u");
    move(12, 8);
    addstr("u");
    move(12, 24);
    addstr("u");
}

void drawWorld()
{
    cout << endl;

    for (int x = 0; x < worldHeight; x++)
    {
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
    int input = 0, tempX = playerX, tempY = playerY;
    input = getch();

    if (input == ERR)
    {
        //
    } else {
        switch(input) {
            case KEY_UP:
                tempY -= 1;
                break;
            case KEY_DOWN:
                tempY += 1;
                break;
            case KEY_LEFT:
                tempX -= 1;
                break;
            case KEY_RIGHT:
                tempX += 1;
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

    if (tempY != playerY || tempX != playerX)
    {
        move(playerY, playerX);
        addstr(" ");

        playerY = tempY;
        playerX = tempX;
    }
}

void updateScore()
{
    const char * scoreText = "0" + score;

    move (2, 2);
    addstr("S");
    move (2, 3);
    addstr("C");
    move (2, 4);
    addstr("O");
    move (2, 5);
    addstr("R");
    move (2, 6);
    addstr("E");
    move (2, 7);
    addstr(":");
    move (2, 8);
    addstr(" ");
    move (2, 9);
    addstr(scoreText);
}
