/*
** EPITECH PROJECT, 2021
** MyRUNNER
** File description:
** screen_dispatcher
*/

#include "runner.h"

void dispatch_my_main_func(myrunner_t *myh,
sfRenderWindow* window, sfEvent event)
{
    if (myh->exitset == 0) {
        initguistruct(myh);
        initmygame(myh, window);
        hover_function(myh, window, event);
    }
    if (myh->open_settings == 1 && myh->exitset == 1 && myh->play_mod == 0) {
        print_settings(myh, window, event);
        hover_back_btn(myh, window, event);
        play_music(myh, window, event);
        if (myh->is_mod_infi_on == 1 && myh->play_mod == 0) {
            sfRenderWindow_drawSprite(window, myh->settings_btn_fl_ok, NULL);
            sfSprite_destroy(myh->settings_btn_fl_no);
        } else {
            myh->infin_mod = 0;
        }
    }
    if (myh->infin_mod == 0 && myh->open_settings == 1
    && myh->is_mod_infi_on == 0 && myh->play_mod == 0) {
        hover_fl_btn(myh, window, event);
    }
}

void dispatch_my_second_func(myrunner_t *myh,
sfRenderWindow* window, sfEvent event)
{
        if (myh->is_back == 1) {
            sfRenderWindow_clear(window, sfBlack);
            sfSprite_destroy(myh->settingsbackg);
            sfSprite_destroy(myh->settingsbtn);
            sfSprite_destroy(myh->settingsbtn_hover);
            myh->hover_aft_back = 1;
        }
        if (myh->is_back == 1 && myh->hover_aft_back == 1) {
            myh->is_back = 0;
            myh->open_settings = 0;
            myh->exitset = 0;
            myh->infin_mod = 0;
            myh->exitsettings = 0;
        }
        if (myh->infin_mod == 1) {
            sfRenderWindow_drawSprite(window, myh->settings_btn_fl_ok, NULL);
            sfSprite_destroy(myh->settings_btn_fl_no);
        }
}

void dispatch_my_third_func(myrunner_t *myh,
sfRenderWindow* window, sfEvent event)
{
    myh->xmouse = sfMouse_getPositionRenderWindow(window).x;
    myh->ymouse = sfMouse_getPositionRenderWindow(window).y;
    if (myh->play_mod == 1 && myh->game_over == 0) {
        sfRenderWindow_clear(window, sfBlack);
        display_game(myh, window, event);
        animate_sprite(myh, window, event);
        character_check_jumping(myh, window, event);
        manage_obstacles(myh, window, event);
        reset_obstacles_position(myh);
        spawn_random_obstacles(myh);
        hit_obstacles(myh, window, event);
    }
    if (myh->game_over == 1)
    {
        sfRenderWindow_clear(window, sfBlack);
        gameover_menu(myh, window, event);
    }
}

int init_my_assets(myrunner_t *myh, sfRenderWindow* window, sfEvent event)
{
    if (!window)
        return (0);
    sfRenderWindow_setFramerateLimit(window, 30);
    init_my_music(myh);
    initguistruct(myh);
    init_screen_play(myh);
    init_obstacles(myh, window, event);
    init_gameover_style(myh);
}