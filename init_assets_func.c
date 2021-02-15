/*
** EPITECH PROJECT, 2021
** MyRUNNER
** File description:
** console_help
*/

#include "runner.h"

void help_disp(void)
{
    my_putstr("***************** UBERUNNER *****************\n");
    my_putchar('\n');
    my_putstr("The goal of the game is to run to");
    my_putstr("quickly deliver the pizza !\n");
    my_putstr("But beware of obstacles that can slow you down and");
    my_putstr("even cause you to fall and destroy the pizzas.\n\n");
    my_putstr("∕∕∕∕-> USAGE\n");
    my_putstr("Use the SPACE key to jump and avoid obstacles.\n\n");
    my_putstr("∕∕∕∕-> SETTINGS\n");
    my_putstr("You can choose between two game modes:");
    my_putstr("infinite or with a defined map.\n\n");
    my_putstr("!WARNING!.\n");
    my_putstr("The choice of the game mode is 'one-shot' so it will not");
    my_putstr("be modifiable, you will have to restart the game.\n\n");
    my_putstr("******************* ENJOY *******************\n");
}

void init_settings_two (myrunner_t *myh)
{
    myh->settings_hover_backbtn = spriteinit("images/backbtnhover.png");
    myh->pos_settings_hover_backbtn = myposinit(50, 480,
    myh->settings_hover_backbtn);
    myh->scale_settings_hover_backbtn = mypscaleinit(0.5, 0.5,
    myh->settings_hover_backbtn);
    myh->settings_btn_fl_ok = spriteinit("images/settings_btn_fl_ok.png");
    myh->settings_btn_fl_no = spriteinit("images/settings_btn_fl_no.png");
    myh->settings_btn_hover_fl_no = spriteinit("images/settings_fl_hover.png");
    myh->pos_settings_btnfl_hover = myposinit(530, 82,
    myh->settings_btn_hover_fl_no);
    myh->scale_settings_btnfl_hover = mypscaleinit(0.5, 0.5,
    myh->settings_btn_hover_fl_no);
    myh->pos_settings_btnfl = myposinit(530, 82, myh->settings_btn_fl_no);
    myh->scale_settings_btnfl = mypscaleinit(0.5, 0.5,
    myh->settings_btn_fl_no);
    myh->pos_settings_btnfl = myposinit(533, 82, myh->settings_btn_fl_ok);
    myh->scale_settings_btnfl = mypscaleinit(0.5, 0.5,
    myh->settings_btn_fl_ok);
}

void init_obstacles (myrunner_t *myh, sfRenderWindow *window, sfEvent event)
{
    myh->obs_car = spriteinit("images/obstacles_car.png");
    myh->pos_obs_car = myposinit(830, 490, myh->obs_car);
    myh->scale_obs_car = mypscaleinit(0.6, 0.6, myh->obs_car);
    myh->obs_taxi = spriteinit("images/obstacles_taxi.png");
    myh->pos_obs_taxi = myposinit(-230, 470, myh->obs_taxi);
    myh->scale_obs_taxi = mypscaleinit(0.6, 0.6, myh->obs_taxi);
    myh->obs_trash = spriteinit("images/obstacles_trash.png");
    myh->pos_obs_trash = myposinit(830, 480, myh->obs_trash);
    myh->scale_obs_trash = mypscaleinit(0.16, 0.16, myh->obs_trash);
}

void init_my_rec (myrunner_t *myh)
{
    myh->game_clock = sfClock_create();
    myh->game_deliver_rect.top = 10;
    myh->game_deliver_rect.left = 1820;
    myh->game_deliver_rect.height = 200;
    myh->game_deliver_rect.width = 164;
}