#ifndef ASSETS_H
#define ASSETS_H

#include "raylib.h"

inline Font menu_font;

void load_fonts();
void unload_fonts();

void load_textures();
void unload_textures();

void load_sounds();
void unload_sounds();

#endif // ASSETS_H