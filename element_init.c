/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** spriteinit
*/

#include "runner.h"

sfSprite *spriteinit(char *file)
{
    sfSprite *mysprite;
    sfTexture *myimg = sfTexture_createFromFile(file, NULL);
    if (!file)
        return (NULL);
    else {
        mysprite = sfSprite_create();
        sfSprite_setTexture(mysprite, myimg, sfTrue);
        return (mysprite);
    }
}

sfVector2f myposinit(int posx, int posy, sfSprite *mysprite)
{
    sfVector2f mypos = {posx, posy};
    sfSprite_setPosition(mysprite, mypos);
    return (mypos);
}

sfVector2f mypscaleinit(float scalex, float scaley, sfSprite *mysprite)
{
    sfVector2f myscale = {scalex, scaley};
    sfSprite_setScale(mysprite, myscale);
    return (myscale);
}

sfMusic *mymusicinit(char *file)
{
    sfMusic *mysic = sfMusic_createFromFile(file);
    sfMusic_setVolume(mysic, 20);
    return (mysic);
}

sfSound *mysoundinit(char *file)
{
    sfSoundBuffer *mybuffersound = sfSoundBuffer_createFromFile(file);
    sfSound *mysound = sfSound_create();
    sfSound_setBuffer(mysound, mybuffersound);
    sfSound_setVolume(mysound, 40);
    return (mysound);
}

