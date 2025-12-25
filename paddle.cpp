#include "paddle.h"

void Paddle::LimitMovement()
{
    if (pos_y <= 0)
    {
        pos_y = 0;
    }
    if (pos_y + height >= screen_height)
    {
        pos_y = screen_height - height;
    }
}

void Paddle::Draw()
{
    DrawRectangle(pos_x, pos_y, width, height, WHITE);
}

void Paddle::Update()
{
    if (IsKeyDown(KEY_UP))
    {
        pos_y = pos_y - speed;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        pos_y = pos_y + speed;
    }

    LimitMovement();
}

void Player2_Paddle::Update()
{
    if (IsKeyDown(KEY_W))
    {
        pos_y = pos_y - speed;
    }
    if (IsKeyDown(KEY_S))
    {
        pos_y = pos_y + speed;
    }

    LimitMovement();
}

void CPU_Paddle::Update(int ball_y)
{
    if (pos_y + height / 2 > ball_y)
    {
        pos_y = pos_y - speed;
    }
    if (pos_y + height / 2 <= ball_y)
    {
        pos_y = pos_y + speed;
    }

    LimitMovement();
}