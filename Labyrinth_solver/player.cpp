#include "pch.h"
#include "player.h"
#include <iostream>
using namespace std;

bool hasnWon = true;
int hp = 100;

enum direction = { up, right, left, down };

struct Player {
    char sprite;
    int x;
    int y;
};

    class Player {
    public:
        int HEIGTH = 21, WIDTH = 31;
        Player player;
        player.sprite = '@';
        player.x = 0;
        player.y = 0;
        unsigned char maze[10][10];
        while (hasnWon)
        {
            if (maze[player.x][player.y] == ' ') {
                maze[player.x][player.y] = player.sprite;
            }
            else if (maze[player.x][player.y] == '>') {
                maze[player.y][player.x] == '%';
            }

            for (int y = 0; y < HEIGTH; y++) {
                cout << endl;
                for (int x = 0; x < WIDTH; x++) {
                    cout << maze[y][x];
                }
            }
        }



    };