/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** spriteinit
*/

#include "runner.h"

void init_screen_play(myrunner_t *myh)
{
    myh->game_first_backbg = spriteinit("images/game_first_background.png");
    myh->pos_game_first_backbg = myposinit(0, 0, myh->game_first_backbg);
    myh->scale_game_first_backbg = mypscaleinit(0.8, 0.8,
    myh->game_first_backbg);
    myh->game_second_backbg = spriteinit("images/game_second_background.png");
    myh->pos_game_second_backbg = myposinit(0, 0,
    myh->game_second_backbg);
    myh->scale_game_second_backbg = mypscaleinit(0.8, 0.8,
    myh->game_second_backbg);
    myh->game_third_backbg =
spriteinit("images/game_third_background.png");
    myh->pos_game_third_backbg = myposinit(0, -14,
    myh->game_third_backbg);
    myh->scale_game_third_backbg = mypscaleinit(0.8, 0.8,
    myh->game_third_backbg);
    myh->game_sprite_p = spriteinit("images/pizzasprite.png");
    myh->pos_game_sprite_p = myposinit(300, 425, myh->game_sprite_p);
    myh->scale_game_sprite_p = mypscaleinit(0.8, 0.8, myh->game_sprite_p);
    init_my_rec(myh);
}

void display_game(myrunner_t *myh, sfRenderWindow* window, sfEvent event)
{
    sfRenderWindow_drawSprite(window, myh->game_first_backbg, NULL);
    sfRenderWindow_drawSprite(window, myh->game_second_backbg, NULL);
    sfRenderWindow_drawSprite(window, myh->game_third_backbg, NULL);
    sfSprite_setTextureRect(myh->game_sprite_p, myh->game_deliver_rect);
    sfRenderWindow_drawSprite(window, myh->game_sprite_p, NULL);
    parralax_effect_midground(myh, window, event);
    parralax_effect_foreground(myh, window, event);
}

void animate_sprite(myrunner_t *myh, sfRenderWindow* window, sfEvent event)
{
    myh->game_time = sfClock_getElapsedTime(myh->game_clock);
    myh->seconds_clock = myh->game_time.microseconds/100000.0;
    if (myh->seconds_clock > 0.5) {
        myh->game_deliver_rect.left -= 222;
        if (myh->game_deliver_rect.left <= 120) {
            myh->game_deliver_rect.left = 1820;
        }
        sfClock_restart(myh->game_clock);
    }
}

void character_check_jumping(myrunner_t *myh,
sfRenderWindow* window, sfEvent event)
{
    int character_posx = sfSprite_getPosition(myh->game_sprite_p).x;
    int character_posy = sfSprite_getPosition(myh->game_sprite_p).y;
    int x = character_posx;
    int y = character_posy;
    sfBool isjumping = sfKeyboard_isKeyPressed(sfKeySpace);
    if (isjumping == sfTrue && character_posy == 425) {
        sfSound_play(myh->jumping_sound);
        if (character_posy > 300) {
            sfVector2f movingeasy = {0, -190};
            sfSprite_move(myh->game_sprite_p, movingeasy);
        }
    }
    if (character_posy != 425) {
        sfVector2f back = {0, 5};
        sfSprite_move(myh->game_sprite_p, back);
    }
}