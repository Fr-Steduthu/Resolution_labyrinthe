#include "pch.h"
#include "player.h"
#include <iostream>
using namespace std;

bool hasnWon = true;
int hp = 100;

enum Direction = { up, right, left down };

struct Player {
    char sprite;
    int x;
    int y;
};

    class Player {
    public:
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
        }



    };