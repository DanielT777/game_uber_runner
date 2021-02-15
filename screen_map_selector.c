/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** settings map selector
*/

#include "runner.h"

void init_map_selector(myrunner_t *myh)
{
    myh->map_backbg = spriteinit("images/map_backbg.png");
    myh->pos_map_backbg = myposinit(0, 0, myh->map_backbg);
    myh->scale_map_backbg = mypscaleinit(0.8, 0.8, myh->map_backbg);

}

