#include "ball.h"
#include "paddle.h"

void Ball::Draw()
{
    DrawCircle(pos_x, pos_y, radius, WHITE);
}

void Ball::Update()
{
    pos_x += speed_x;
    pos_y += speed_y;

    if (pos_y + radius >= screen_height || pos_y - radius <= 0)
    {
        speed_y = -speed_y;
    }

    if (pos_x + radius >= screen_width)
    {
        cpu_score++;
        ResetBall();
    }

    if (pos_x - radius <= 0)
    {
        player_score++;
        ResetBall();
    }
}

void Ball::CheckPaddleCollision(const Paddle &paddle)
{
    if (CheckCollisionCircleRec({pos_x, pos_y}, radius,
                                {paddle.pos_x, paddle.pos_y, paddle.width, paddle.height}))
    {
        speed_x = -speed_x;
    }
}

void Ball::ResetBall()
{
    pos_x = screen_width / 2;
    pos_y = screen_height / 2;

    int speed_choices[] = {-1, 1};
    speed_x *= speed_choices[GetRandomValue(0, 1)];
    speed_y *= speed_choices[GetRandomValue(0, 1)];
}