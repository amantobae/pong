#include <iostream>
#include <raylib.h>

using namespace std;

const int screen_width = 1280;
const int screen_height = 800;

class Ball
{
public:
    float pos_x, pos_y;
    int speed_x, speed_y;
    int radius;

    void Draw()
    {
        DrawCircle(pos_x, pos_y, radius, WHITE);
    }

    void Update()
    {
        pos_x += speed_x;
        pos_y += speed_y;

        if (pos_y + radius >= screen_height || pos_y - radius <= 0)
        {
            speed_y = -speed_y;
        }
        if (pos_x + radius >= screen_width || pos_x - radius <= 0)
        {
            speed_x = -speed_x;
        }
    }
};

class Paddle
{
public:
    float pos_x, pos_y;
    float width, height;
    int speed;

    void Draw()
    {
        DrawRectangle(pos_x, pos_y, width, height, WHITE);
    }

    void Update()
    {
        if (IsKeyDown(KEY_DOWN))
        {
            pos_y = pos_y + speed;
        }
        if (IsKeyDown(KEY_UP))
        {
            pos_y = pos_y - speed;
        }

        if (pos_y <= 0)
        {
            pos_y = 0;
        }
        if (pos_y + height >= screen_height)
        {
            pos_y = screen_height - height;
        }
    }
};

class CPU_Paddle : public Paddle
{
};

Ball ball;
Paddle player;
CPU_Paddle CPU;

int main()
{
    InitWindow(screen_width, screen_height, "Pong");
    SetTargetFPS(60);

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

    CPU.width = 25;
    CPU.height = 120;
    CPU.pos_x = 10;
    CPU.pos_y = screen_height / 2 - CPU.height / 2;
    CPU.speed = 6;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ball.Update();
        player.Update();

        ClearBackground(BLACK);
        DrawLine(screen_width / 2.0f, 0, screen_width / 2.0f, screen_height, WHITE);
        ball.Draw();
        player.Draw();
        CPU.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}