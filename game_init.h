#pragma once
#include "ball.h"
#include "paddle.h"

void InitializeGameObjects(Ball &ball, Paddle &player, Paddle &cpu,
                           int screen_width, int screen_height)
{
    ball.radius = 20;
    ball.pos_x = screen_width / 2.0f;
    ball.pos_y = screen_height / 2.0f;
    ball.speed_x = 7;
    ball.speed_y = 7;

    player.width = 25;
    player.height = 120;
    player.pos_x = screen_width - player.width - 10;
    player.pos_y = screen_height / 2 - player.height / 2;
    player.speed = 6;

    cpu.width = 25;
    cpu.height = 120;
    cpu.pos_x = 10;
    cpu.pos_y = screen_height / 2 - cpu.height / 2;
    cpu.speed = 6;
}