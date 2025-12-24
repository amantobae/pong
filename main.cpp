#include <iostream>
#include <raylib.h>
#include "ball.h"
#include "paddle.h"
#include "graphics.h"
#include "game_init.h"

using namespace std;

Ball ball;
Paddle player;
CPU_Paddle CPU;

void draw()
{
    ClearBackground(BLACK);
    DrawLine(screen_width / 2.0f, 0, screen_width / 2.0f, screen_height, WHITE);
    ball.Draw();
    player.Draw();
    CPU.Draw();

    draw_scores(cpu_score, player_score);
}

void update()
{
    ball.Update();
    player.Update();
    CPU.Update(ball.pos_y);

    ball.CheckPaddleCollision(player);
    ball.CheckPaddleCollision(CPU);
}

int main()
{

    InitWindow(screen_width, screen_height, "Pong");
    SetTargetFPS(60);

    InitializeGameObjects(ball, player, CPU, screen_width, screen_height);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        update();
        draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}