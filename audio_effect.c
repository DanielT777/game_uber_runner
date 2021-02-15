/*
** EPITECH PROJECT, 2021
** MyRUNNER
** File description:
** audio_effect
*/

#include "runner.h"

void init_my_music(myrunner_t *myh)
{
    myh->music_menu = mymusicinit("audio/menu_music.wav");
    myh->jumping_sound = mysoundinit("audio/jumping.wav");
}

void play_music(myrunner_t *myh, sfRenderWindow* window, sfEvent event)
{
    sfMusic_play(myh->music_menu);
    sfMusic_setLoop(myh->music_menu, sfTrue);
}