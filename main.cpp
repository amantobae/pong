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

Ball ball;

int main()
{
    InitWindow(screen_width, screen_height, "Pong");
    SetTargetFPS(60);

    ball.radius = 20;
    ball.pos_x = screen_width / 2.0f;
    ball.pos_y = screen_height / 2.0f;
    ball.speed_x = 7;
    ball.speed_y = 7;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ball.Update();

        ClearBackground(BLACK);
        DrawLine(screen_width / 2.0f, 0, screen_width / 2.0f, screen_height, WHITE);
        ball.Draw();
        DrawRectangle(10.0f, screen_height / 2.0f - 60, 25.0f, 120.0f, WHITE);
        DrawRectangle(screen_width - 35.0f, screen_height / 2.0f - 60, 25.0f, 120.0f, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}