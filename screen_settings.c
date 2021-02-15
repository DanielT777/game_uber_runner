/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** settings
*/

#include "runner.h"

void init_settings(myrunner_t *myh)
{
    if (myh->is_mod_infi_on == 1) {
        myh->settingsbackg = spriteinit("images/settings_backg_ifinf_yes.png");
        myh->pos_settingsbackbgpos = myposinit(0, 0, myh->settingsbackg);
        myh->scale_settingsbackbgscale = mypscaleinit(0.8, 0.8,
        myh->settingsbackg);
    } else {
        myh->settingsbackg = spriteinit("images/settings_backbg.png");
        myh->pos_settingsbackbgpos = myposinit(0, 0,
        myh->settingsbackg);
        myh->scale_settingsbackbgscale = mypscaleinit(0.8, 0.8,
        myh->settingsbackg);
    }
    myh->settings_backbtn = spriteinit("images/backbtn.png");
    myh->pos_settings_backbtn = myposinit(50, 480, myh->settings_backbtn);
    myh->scale_settings_backbtn = mypscaleinit(0.5, 0.5, myh->settings_backbtn);
    init_settings_two(myh);
}

void print_settings(myrunner_t *myh, sfRenderWindow* window, sfEvent event)
{
    init_settings(myh);
    sfRenderWindow_drawSprite(window, myh->settingsbackg, NULL);
}

void hover_back_btn(myrunner_t *myh, sfRenderWindow* window, sfEvent event)
{
    sfBool isclick;
    if (myh->xmouse >= 50 && myh->xmouse <= 254
    && myh->ymouse >= 475 && myh->ymouse <= 530) {
        sfRenderWindow_drawSprite(window, myh->settings_hover_backbtn, NULL);
        isclick = sfMouse_isButtonPressed(sfMouseLeft);
    } else {
        sfRenderWindow_drawSprite(window, myh->settings_backbtn, NULL);
    }
    if (isclick == sfTrue) {
        myh->is_back = 1;
    }
}

void hover_fl_btn(myrunner_t *myh, sfRenderWindow* window, sfEvent event)
{
    sfBool isclick;
    if (myh->xmouse >= 530 && myh->xmouse <= 570
    && myh->ymouse >= 80 && myh->ymouse <= 120) {
        sfRenderWindow_drawSprite(window, myh->settings_btn_hover_fl_no, NULL);
        isclick = sfMouse_isButtonPressed(sfMouseLeft);
    } else {
        sfRenderWindow_drawSprite(window, myh->settings_btn_fl_no, NULL);
    }
    if (isclick == sfTrue) {
        myh->infin_mod = 1;
        myh->is_mod_infi_on = 1;
    }
}
