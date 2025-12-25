#include "assets.h"
#include "raylib.h"

void load_fonts()
{
    menu_font = LoadFontEx("data/fonts/sonic-1-title-card-fixed.ttf", 256, nullptr, 0);
}

void unload_fonts()
{
    UnloadFont(menu_font);
}

void load_textures()
{
}

void unload_textures()
{
}

void load_sounds()
{
    InitAudioDevice();
}

void unload_sounds()
{
    CloseAudioDevice();
}