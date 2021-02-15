/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** spriteinit
*/

#include "runner.h"

void init_gameover_style(myrunner_t *myh)
{
    myh->game_hover_bg = spriteinit("images/over_background.png");
    myh->pos_game_hover_bg = myposinit(0, 0, myh->game_hover_bg);
    myh->scale_game_hover_bg = mypscaleinit(0.8, 0.8, myh->game_hover_bg);
}

void gameover_menu (myrunner_t *myh, sfRenderWindow *window, sfEvent event)
{
    sfRenderWindow_drawSprite(window, myh->game_hover_bg, NULL);
}

    // sfText *score = sfText_create();
    // sfFont *myfont = sfFont_createFromFile("font/scorefont.ttf");
    // sfVector2f font_pos = {380, 455};
    // sfText_setPosition(score, font_pos);
    // sfVector2f font_scale = {1.8, 1.8};
    // sfText_setScale(score, font_scale);
    // sfText_setFont(score, myfont);
    // sfText_setString(score, "210");
    //sfRenderWindow_drawText(window, score, NULL);
