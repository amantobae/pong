#include <raylib.h>
#include "constants.h"
#include <string>
#include "assets.h"
#include "game.h"
#include "graphics.h"
#include <cmath>

struct Text
{
    std::string str;
    Vector2 position = {0.50f, 0.50f};
    float size = 32.0f;
    Color color = WHITE;
    float spacing = 4.0f;
    Font *font = nullptr;
};

static int selected_menu_option = 0;
static const int MENU_OPTIONS_COUNT = 4;

void draw_text(const Text &text)
{
    const float font_size = text.size * screen_scale;
    Vector2 text_size = MeasureTextEx(*text.font, text.str.c_str(), font_size, text.spacing);

    const Vector2 pos = {
        screen_width * text.position.x - 0.5f * text_size.x,
        screen_height * text.position.y - 0.5f * text_size.y};

    DrawTextEx(*text.font, text.str.c_str(), pos, text.size * screen_scale, text.spacing, text.color);
}

void draw_scores(int cpu_score, int player_score)
{
    const Text cpu_text = {
        std::to_string(cpu_score),
        {0.25f, 0.05f},
        50.0f,
        WHITE,
        4.0f,
        &menu_font,
    };

    const Text player_text = {
        std::to_string(player_score),
        {0.75f, 0.05f},
        50.0f,
        WHITE,
        4.0f,
        &menu_font,
    };

    draw_text(cpu_text);
    draw_text(player_text);
}

void update_menu()
{
    if (IsKeyPressed(KEY_DOWN))
    {
        selected_menu_option = (selected_menu_option + 1) % MENU_OPTIONS_COUNT;
    }

    if (IsKeyPressed(KEY_UP))
    {
        selected_menu_option--;
        if (selected_menu_option < 0)
            selected_menu_option = MENU_OPTIONS_COUNT - 1;
    }

    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
    {
        extern game_state current_state;
        switch (selected_menu_option)
        {
        case 0:
            // Single Player
            current_state = single_player_state;
            break;
        case 1:
            // Multiplayer
            current_state = multiplayer_state;
            break;
        case 2:
            // Settings
            break;
        case 3:
            // Exit
            CloseWindow();
            break;
        }
    }
}

void draw_menu()
{
    ClearBackground(BLACK);

    float offset = std::sin(game_frame * 0.1f) * 0.01f;

    const Text game_title = {
        "Pong",
        {0.50f, 0.1f},
        200.0f,
        WHITE,
        4.0f,
        &menu_font,
    };
    draw_text(game_title);

    const Text option1 = {
        "Single Player",
        {0.10f, 0.40f + (selected_menu_option == 0 ? offset : 0.0f)},
        50.0f,
        selected_menu_option == 0 ? GRAY : WHITE,
        4.0f,
        &menu_font,
    };
    draw_text(option1);

    const Text option2 = {
        "Local Multiplayer",
        {0.10f, 0.50f + (selected_menu_option == 1 ? offset : 0.0f)},
        50.0f,
        selected_menu_option == 1 ? GRAY : WHITE,
        4.0f,
        &menu_font,
    };
    draw_text(option2);

    const Text option3 = {
        "Settings",
        {0.10f, 0.60f + (selected_menu_option == 2 ? offset : 0.0f)},
        50.0f,
        selected_menu_option == 2 ? GRAY : WHITE,
        4.0f,
        &menu_font,
    };
    draw_text(option3);

    const Text option4 = {
        "Exit",
        {0.10f, 0.70f + (selected_menu_option == 3 ? offset : 0.0f)},
        50.0f,
        selected_menu_option == 3 ? GRAY : WHITE,
        4.0f,
        &menu_font,
    };
    draw_text(option4);
}

static int selected_game_mode = 0;
static const int GAME_MODE_MENU_OPTIONS_COUNT = 2;

void update_game_mode_menu()
{
    if (IsKeyPressed(KEY_DOWN))
    {
        selected_game_mode = (selected_game_mode + 1) % GAME_MODE_MENU_OPTIONS_COUNT;
    }

    if (IsKeyPressed(KEY_UP))
    {
        selected_game_mode--;
        if (selected_game_mode < 0)
            selected_game_mode = GAME_MODE_MENU_OPTIONS_COUNT - 1;
    }

    if (IsKeyPressed(KEY_ESCAPE))
    {
        extern game_state current_state;
        current_state = menu_state;
    }

    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
    {
        extern game_state current_state;
        switch (selected_game_mode)
        {
        case 0:
            if (current_state == single_player_state)
            {
                current_state = in_game_state;
            }
            else if (current_state == multiplayer_state)
            {
                current_state = in_multiplayer_game_state;
            }
            break;
        case 1:
            if (current_state == single_player_state)
            {
                current_state = in_game_state;
            }
            else if (current_state == multiplayer_state)
            {
                current_state = in_multiplayer_game_state;
            }
            break;
        }
    }
}

void draw_game_mode_menu()
{
    ClearBackground(BLACK);

    float offset = std::sin(game_frame * 0.1f) * 0.01f;

    const Text game_title = {
        "Choose the Game Mode",
        {0.10f, 0.10f},
        100.0f,
        WHITE,
        4.0f,
        &menu_font,
    };
    draw_text(game_title);

    const Text option1 = {
        "Classic Mode",
        {0.10f, 0.40f + (selected_game_mode == 0 ? offset : 0.0f)},
        50.0f,
        selected_game_mode == 0 ? GRAY : WHITE,
        4.0f,
        &menu_font,
    };
    draw_text(option1);

    const Text option2 = {
        "Play with Modifications",
        {0.10f, 0.50f + (selected_game_mode == 1 ? offset : 0.0f)},
        50.0f,
        selected_game_mode == 1 ? GRAY : WHITE,
        4.0f,
        &menu_font,
    };
    draw_text(option2);
}