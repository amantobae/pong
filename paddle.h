#pragma once
#include <raylib.h>
#include "constants.h"

class Paddle
{
protected:
    void LimitMovement();

public:
    float pos_x, pos_y;
    float width, height;
    int speed;

    void Draw();
    void Update();
};

class CPU_Paddle : public Paddle
{
public:
    void Update(int ball_y);
};