/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** main hunter
*/

#include "runner.h"

void initguistruct(myrunner_t *myh)
{
    myh->backg = spriteinit("images/logobk.png");
    myh->playbtn = spriteinit("images/playbtn.png");
    myh->settingsbtn = spriteinit("images/settingsbtn.png");
    myh->exitbtn = spriteinit("images/exitbtn.png");
    myh->playbtn_hover = spriteinit("images/playhover.png");
    myh->settingsbtn_hover = spriteinit("images/settingshover.png");
    myh->exitbtn_hover = spriteinit("images/exithover.png");
    myh->backbgpos = myposinit(0, 0, myh->backg);
    myh->backbgscale = mypscaleinit(0.8, 0.8, myh->backg);
    myh->pos_playbtn = myposinit(50, 480, myh->playbtn);
    myh->pos_settingsbtn = myposinit(310, 480, myh->settingsbtn);
    myh->pos_exitbtn = myposinit(570, 480, myh->exitbtn);
    myh->scale_playbtn = mypscaleinit(0.5, 0.5, myh->playbtn);
    myh->scale_settingsbtn = mypscaleinit(0.5, 0.5, myh->settingsbtn);
    myh->scale_exitbtn = mypscaleinit(0.5, 0.5, myh->exitbtn);
}

void initmygame(myrunner_t *myh, sfRenderWindow* window)
{
    sfRenderWindow_drawSprite(window, myh->backg, NULL);
    sfRenderWindow_drawSprite(window, myh->playbtn, NULL);
    sfRenderWindow_drawSprite(window, myh->settingsbtn, NULL);
    sfRenderWindow_drawSprite(window, myh->exitbtn, NULL);
}

int guiinit(void)
{
    myrunner_t *myh = malloc(sizeof(myrunner_t));
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfEvent event;
    window = sfRenderWindow_create(mode,
    "UBERUNNER | DELIVER PIZZA WITHOUT DROPPING IT", sfResize | sfClose, NULL);
    init_my_assets(myh, window, event);
    play_music(myh, window, event);
    while (sfRenderWindow_isOpen(window)) {
        dispatch_my_main_func(myh, window, event);
        dispatch_my_second_func(myh, window, event);
        dispatch_my_third_func(myh, window, event);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                sfMusic_stop(myh->music_menu);
            }
        }
        sfRenderWindow_display(window);
    }
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        help_disp();
        return (0);
    }
    else if (argc >= 2 && argv[1] != "-h") {
        my_putstr("Wrong argument!Type -h to get help.\n");
        return (84);
    } else {
        guiinit();
        return (0);
    }
    return (0);
}