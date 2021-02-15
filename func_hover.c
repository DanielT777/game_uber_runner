/*
** EPITECH PROJECT, 2021
** RUNNER
** File description:
** hover function for button
*/

#include "runner.h"

void hover_function(myrunner_t *myh, sfRenderWindow* window, sfEvent event)
{
    myh->pos_playbtn = myposinit(50, 480, myh->playbtn_hover);
    myh->pos_settingsbtn = myposinit(310, 480, myh->settingsbtn_hover);
    myh->pos_exitbtn = myposinit(570, 480, myh->exitbtn_hover);
    myh->scale_playbtn = mypscaleinit(0.5, 0.5, myh->playbtn_hover);
    myh->scale_settingsbtn = mypscaleinit(0.5, 0.5, myh->settingsbtn_hover);
    myh->scale_exitbtn = mypscaleinit(0.5, 0.5, myh->exitbtn_hover);
    funcexitbtn(myh, window, event);
    funcplaybtn(myh, window, event);
    funcsettingsbtn(myh, window, event);
}

void funcexitbtn(myrunner_t *myh, sfRenderWindow* window, sfEvent event)
{
    sfBool isclick;
    myh->xmouse = sfMouse_getPositionRenderWindow(window).x;
    myh->ymouse = sfMouse_getPositionRenderWindow(window).y;
    int exitbtnx = sfSprite_getPosition(myh->exitbtn_hover).x;
    int exitbtny = sfSprite_getPosition(myh->exitbtn_hover).y;
    if (myh->xmouse >= 558 && myh->xmouse <= 775
    && myh->ymouse >= 475 && myh->ymouse <= 570 && myh->exitset != 1) {
        sfRenderWindow_drawSprite(window, myh->exitbtn_hover, NULL);
        isclick = sfMouse_isButtonPressed(sfMouseLeft);
    } else {
        sfRenderWindow_drawSprite(window, myh->exitbtn, NULL);
    }
    if (isclick == sfTrue) {
        sfRenderWindow_close(window);
    }
}

void funcplaybtn(myrunner_t *myh, sfRenderWindow* window, sfEvent event)
{
    sfBool isclick;
    myh->xmouse = sfMouse_getPositionRenderWindow(window).x;
    myh->ymouse = sfMouse_getPositionRenderWindow(window).y;
    if (myh->xmouse >= 50 && myh->xmouse <= 254
    && myh->ymouse >= 475 && myh->ymouse <= 530) {
        sfRenderWindow_drawSprite(window, myh->playbtn_hover, NULL);
        isclick = sfMouse_isButtonPressed(sfMouseLeft);
    } else {
        sfRenderWindow_drawSprite(window, myh->playbtn, NULL);
    }
    if (isclick == sfTrue) {
        myh->play_mod = 1;
    }
}

void funcsettingsbtn(myrunner_t *myh, sfRenderWindow* window, sfEvent event)
{
    sfBool isclick;
    myh->xmouse = sfMouse_getPositionRenderWindow(window).x;
    myh->ymouse = sfMouse_getPositionRenderWindow(window).y;
    if (myh->xmouse >= 300 && myh->xmouse <= 515
    && myh->ymouse >= 475 && myh->ymouse <= 530) {
        sfRenderWindow_drawSprite(window, myh->settingsbtn_hover, NULL);
        isclick = sfMouse_isButtonPressed(sfMouseLeft);
    } else {
        sfRenderWindow_drawSprite(window, myh->settingsbtn, NULL);
    }
    if (isclick == sfTrue) {
        myh->exitsettings = 1;
        myh->exitset = 1;
        hider(myh, window);
        myh->open_settings = 1;
    }
}

void hider(myrunner_t *myh, sfRenderWindow* window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_destroy(myh->backg);
    if (myh->exitsettings == 1) {
        sfSprite_destroy(myh->exitbtn);
        sfSprite_destroy(myh->exitbtn_hover);
        sfSprite_destroy(myh->settingsbtn);
        sfSprite_destroy(myh->settingsbtn_hover);
        sfSprite_destroy(myh->playbtn);
        sfSprite_destroy(myh->playbtn_hover);
    }
}