#include <iostream>
#include <raylib.h>
#include "ball.h"
#include "paddle.h"
#include "graphics.h"
#include "game_init.h"
#include "game.h"
#include "assets.h"

using namespace std;

Ball ball;
Paddle player;
Player2_Paddle player2;
CPU_Paddle CPU;
game_state current_state = menu_state;

void draw()
{
    game_frame++;
    switch (current_state)
    {
    case menu_state:
        draw_menu();
        break;
    case single_player_state:
        draw_game_mode_menu();
        break;
    case multiplayer_state:
        draw_game_mode_menu();
        break;
    case in_game_state:
        ClearBackground(BLACK);
        DrawLine(screen_width / 2.0f, 0, screen_width / 2.0f, screen_height, WHITE);
        ball.Draw();
        player.Draw();
        CPU.Draw();
        draw_scores(cpu_score, player_score);
        break;
    case in_multiplayer_game_state:
        ClearBackground(BLACK);
        DrawLine(screen_width / 2.0f, 0, screen_width / 2.0f, screen_height, WHITE);
        ball.Draw();
        player.Draw();
        player2.Draw();
        draw_scores(cpu_score, player_score);
        break;
    }
}

void update()
{
    switch (current_state)
    {
    case menu_state:
        update_menu();
        break;
    case in_game_state:
        ball.Update();
        player.Update();
        CPU.Update(ball.pos_y);
        ball.CheckPaddleCollision(player);
        ball.CheckPaddleCollision(CPU);
        break;
    case in_multiplayer_game_state:
        ball.Update();
        player.Update();
        player2.Update();
        ball.CheckPaddleCollision(player);
        ball.CheckPaddleCollision(player2);
        break;
    case single_player_state:
        update_game_mode_menu();
        break;
    case multiplayer_state:
        update_game_mode_menu();
        break;
    }
}

int main()
{
    InitWindow(screen_width, screen_height, "Pong");
    SetTargetFPS(60);

    InitializeGameObjects(ball, player, CPU, player2, screen_width, screen_height);

    load_fonts();
    load_textures();
    load_sounds();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        update();
        draw();

        EndDrawing();
    }

    unload_sounds();
    unload_textures();
    unload_fonts();

    CloseWindow();
    return 0;
}