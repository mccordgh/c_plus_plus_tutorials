#include <iostream>
#include <curses.h>

using namespace std;

class Item
{
    public:
        int x;
        int y;
        bool found;
};

// const int worldHeight = 16, worldWidth = 32;
int playerX = 4, prevX = 4, playerY = 4, prevY = 4, score = 0;
Item item1, item2, item3, item4;

// const char * player = "O", item = "u", monster = "X";

// WINDOW * win = newwin(worldHeight, worldWidth, 4, 4);

bool gameOver = false;

// #define KEY_UP 72
// #define KEY_DOWN 80
// #define KEY_LEFT 75
// #define KEY_RIGHT 77

void drawWorld(), initItems(), getInput(), updateScore(), checkCollisions(), drawItems(), increaseScore(), youWin(), pressEnter();

// string world[worldHeight][worldWidth] = {
//     {"*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*"},
//     {"*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
// };

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
    initItems();
    drawItems();

    // while (gameOver == false)
    updateScore();

    while (1)
    {
        getInput();
        
        if (score >= 4)
        {
            youWin();
            pressEnter();
        } else {

            move(playerY, playerX);

            checkCollisions();

            addstr("0");
            move(0, 0);
        }

        refresh();
    }

};

void pressEnter()
{
    move(14, 12);
    addstr("P");

    move(14, 13);
    addstr("R");
    
    move(14, 14);
    addstr("E");
    
    move(14, 15);
    addstr("S");
    
    move(14, 16);
    addstr("S");
    
    move(14, 17);
    addstr(" ");
    
    move(14, 18);
    addstr("E");

    move(14, 19);
    addstr("N");

    move(14, 20);
    addstr("T");

    move(14, 21);
    addstr("E");
    
    move(14, 22);
    addstr("R");
    
    move(14, 23);
    addstr(".");
}

void youWin()
{
    move(12, 12);
    addstr("Y");

    move(12, 13);
    addstr("O");
    
    move(12, 14);
    addstr("U");
    
    move(12, 15);
    addstr(" ");
    
    move(12, 16);
    addstr("W");
    
    move(12, 17);
    addstr("I");
    
    move(12, 18);
    addstr("N");

    move(12, 19);
    addstr("!");

    move(12, 20);
    addstr("!");
}

void drawItems() {
    // if (item1.found == false)
    // {
        move(item1.y, item1.x);
        addstr("1");
    // }

    // if (item2.found == false)
    // {
        move(item2.y, item2.x);
        addstr("2");
    // }

    // if (item3.found == false)
    // {
        move(item3.y, item3.x);
        addstr("3");
    // }

    // if (item1.found == false)
    // {
        move(item4.y, item4.x);
        addstr("4");
    // }
}

void checkCollisions()
{
    if (playerX == item1.x && playerY == item1.y && item1.found == false)
    {
        item1.found = true;
        increaseScore();
    }
    
    if (playerX == item2.x && playerY == item2.y && item2.found == false)
    {
        item2.found = true;
        increaseScore();
    }
    
    if (playerX == item3.x && playerY == item3.y && item3.found == false)
    {
        item3.found = true;
        increaseScore();
    }
    
    if (playerX == item4.x && playerY == item4.y && item4.found == false)
    {
        item4.found = true;
        increaseScore();
    }
}

void increaseScore()
{
    score +=  1;
    updateScore();
}

void initItems()
{
    // move(4, 8);
    item1.y = 4;
    item1.x = 8;
    item1.found = false;

    // move(4, 24);
    item2.y = 4;
    item2.x = 24;
    item2.found = false;

    // move(12, 8);
    item3.y = 12;
    item3.x = 8;
    item3.found = false;

    // move(12, 24);
    item4.y = 12;
    item4.x = 24;
    item4.found = false;
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
    addstr(to_string(score).c_str());
    move (playerY, playerX);
}
