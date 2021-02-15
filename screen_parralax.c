/*
** EPITECH PROJECT, 2021
** MyRUNNER
** File description:
** parralax effect
*/

#include "runner.h"

void parralax_effect_midground(myrunner_t *myh,
sfRenderWindow *window, sfEvent event)
{
    int x = sfSprite_getPosition(myh->game_third_backbg).x;
    int y = sfSprite_getPosition(myh->game_third_backbg).y;
    sfVector2f posback = {24, -14};
    if (x <= -999)
        sfSprite_setPosition(myh->game_third_backbg,
    myh->pos_game_third_backbg);
    sfVector2f my_mover = {-5, 0};
    sfSprite_move(myh->game_third_backbg, my_mover);
}

void parralax_effect_foreground(myrunner_t *myh,
sfRenderWindow *window, sfEvent event)
{
    int x = sfSprite_getPosition(myh->game_second_backbg).x;
    int y = sfSprite_getPosition(myh->game_second_backbg).y;
    sfVector2f posback = {0, 0};
    if (x <= -1050)
        sfSprite_setPosition(myh->game_second_backbg,
        myh->pos_game_second_backbg);
    if (x % - 20 == 0)
        spawn_random_obstacles(myh);
    sfVector2f my_mover = {-1, 0};
    sfSprite_move(myh->game_second_backbg, my_mover);
}