#pragma once
#include <raylib.h>
#include "constants.h"

class Paddle;

class Ball
{
public:
    float pos_x, pos_y;
    int speed_x, speed_y;
    int radius;

    void Draw();
    void Update();

    void CheckPaddleCollision(const Paddle &paddle);

    void ResetBall();
};