#include <iostream>
#include <raylib.h>

using namespace std;

const int screen_width = 1280;
const int screen_height = 800;

int player_score = 0;
int cpu_score = 0;

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

    void ResetBall()
    {
        pos_x = screen_width / 2;
        pos_y = screen_height / 2;

        int speed_choices[] = {-1, 1};
        speed_x *= speed_choices[GetRandomValue(0, 1)];
        speed_y *= speed_choices[GetRandomValue(0, 1)];
    }
};

class Paddle
{
protected:
    void LimitMovement()
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

        LimitMovement();
    }
};

class CPU_Paddle : public Paddle
{
public:
    void Update(int ball_y)
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
        CPU.Update(ball.pos_y);

        if (CheckCollisionCircleRec({ball.pos_x, ball.pos_y}, ball.radius, {player.pos_x, player.pos_y, player.width, player.height}))
        {
            ball.speed_x = -ball.speed_x;
        }
        if (CheckCollisionCircleRec({ball.pos_x, ball.pos_y}, ball.radius, {CPU.pos_x, CPU.pos_y, CPU.width, CPU.height}))
        {
            ball.speed_x = -ball.speed_x;
        }

        ClearBackground(BLACK);
        DrawLine(screen_width / 2.0f, 0, screen_width / 2.0f, screen_height, WHITE);
        ball.Draw();
        player.Draw();
        CPU.Draw();

        DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", player_score), 3 * (screen_width / 4 - 20), 20, 80, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}