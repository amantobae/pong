#include <raylib.h>
#include "constants.h"

void draw_scores(int cpu_score, int player_score)
{
    DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", player_score), 3 * (screen_width / 4 - 20), 20, 80, WHITE);
}