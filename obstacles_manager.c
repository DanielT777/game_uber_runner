/*
** EPITECH PROJECT, 2021
** MyRUNNER
** File description:
** obstacles handler
*/

#include "runner.h"

void manage_obstacles (myrunner_t *myh, sfRenderWindow *window, sfEvent event)
{
    myh->live_pos_car_x = sfSprite_getPosition(myh->obs_car).x;
    myh->live_pos_taxi_x = sfSprite_getPosition(myh->obs_taxi).x;
    myh->live_pos_trash_x = sfSprite_getPosition(myh->obs_trash).x;
    sfRenderWindow_drawSprite(window, myh->obs_car, NULL);
    sfRenderWindow_drawSprite(window, myh->obs_taxi, NULL);
    sfRenderWindow_drawSprite(window, myh->obs_trash, NULL);
}

void checker(myrunner_t *myh) {
    if (myh->live_pos_car_x <= -210)
        set_obstacles_position(myh, myh->obs_car);
    if (myh->live_pos_taxi_x <= -210)
        set_obstacles_position(myh, myh->obs_taxi);
    if (myh->live_pos_trash_x <= -210)
        set_obstacles_position(myh, myh->obs_trash);
}

void reset_obstacles_position (myrunner_t *myh)
{
    checker(myh);
    if (myh->live_pos_taxi_x > -210 && myh->live_pos_trash_x > -210) {
        if (myh->spawning_nb == 2) {
            moving_obstacles(myh, myh->obs_car);
        }
    }
    if (myh->live_pos_car_x > -210 && myh->live_pos_trash_x > -210) {
        if (myh->spawning_nb == 3 ) {
            moving_obstacles(myh, myh->obs_taxi);
        }
    }
    if (myh->live_pos_car_x > -210 && myh->live_pos_taxi_x > -210) {
        if (myh->spawning_nb == 4 ) {
            moving_obstacles(myh, myh->obs_trash);
        }
    }
}

void set_obstacles_position(myrunner_t *myh, sfSprite *sprite)
{
    sfVector2f reset_pos = {830, 480};
    sfSprite_setPosition(sprite, reset_pos);
}

void moving_obstacles (myrunner_t *myh, sfSprite *sprite) {
    int rand_speed = (rand() % (7 - 15)) + 7;
    rand_speed *= -1;
    sfVector2f moving = {rand_speed, 0};
    sfSprite_move(sprite, moving);
}

int spawn_random_obstacles (myrunner_t *myh)
{
    if (myh->live_pos_taxi_x <= -210 |
    myh->live_pos_trash_x <= -210 | myh->live_pos_car_x <= -210) {
        myh->spawning_nb = (rand() % (2 - 5)) + 2;
    }
}

void hit_obstacles (myrunner_t *myh, sfRenderWindow *window, sfEvent event)
{
    myh->character_pos_x = sfSprite_getPosition(myh->game_sprite_p).x;
    myh->character_pos_y = sfSprite_getPosition(myh->game_sprite_p).y;
    if (myh->live_pos_car_x <= 377 && myh->live_pos_car_x >= 199
    && myh->character_pos_y <= 480 && myh->character_pos_y >= 425)
        myh->game_over = 1;
    if (myh->live_pos_taxi_x <= 377 && myh->live_pos_taxi_x >= 206
    && myh->character_pos_y <= 480 && myh->character_pos_y >= 425)
        myh->game_over = 1;
    if (myh->live_pos_trash_x <= 380 && myh->live_pos_trash_x >= 220
    && myh->character_pos_y <= 480 && myh->character_pos_y >= 425)
        myh->game_over = 1;
}