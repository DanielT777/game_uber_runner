/*
** EPITECH PROJECT, 2020
** RUNNER
** File description:
** my.h
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Rect.h>
#include <math.h>

typedef struct myrunner_s
{
    int xmouse;
    int ymouse;
    sfVideoMode resolution;
    sfEvent myevent;
    sfRenderWindow* mywin;
    int exitset;
    int exitsettings;
    int open_settings;
    int isfl;
    int isrlyfl;
    sfSprite *backg;
    sfVector2f backbgpos;
    sfVector2f backbgscale;
    sfSprite *playbtn;
    sfSprite *settingsbtn;
    sfSprite *exitbtn;
    sfSprite *playbtn_hover;
    sfSprite *settingsbtn_hover;
    sfSprite *exitbtn_hover;
    sfVector2f pos_playbtn;
    sfVector2f pos_settingsbtn;
    sfVector2f pos_exitbtn;
    sfVector2f scale_playbtn;
    sfVector2f scale_settingsbtn;
    sfVector2f scale_exitbtn;
    sfSprite *settingsbackg;
    sfVector2f pos_settingsbackbgpos;
    sfVector2f scale_settingsbackbgscale;
    sfSprite *settingsbackg_infyes;
    sfVector2f pos_settings_backg_ifinf_yes;
    sfVector2f scale_settings_backg_ifinf_yes;
    sfSprite *settings_backbtn;
    sfVector2f pos_settings_backbtn;
    sfVector2f scale_settings_backbtn;
    sfSprite *settings_hover_backbtn;
    sfVector2f pos_settings_hover_backbtn;
    sfVector2f scale_settings_hover_backbtn;
    sfSprite *settings_hover_bg;
    sfVector2f pos_settings_hover_bg;
    sfVector2f scale_settings_hover_bg;
    int is_back;
    int hover_aft_back;
    sfSprite *settings_btn_fl_ok;
    sfSprite *settings_btn_fl_no;
    sfVector2f pos_settings_btnfl;
    sfVector2f scale_settings_btnfl;
    sfSprite *settings_btn_hover_fl_no;
    sfVector2f pos_settings_btnfl_hover;
    sfVector2f scale_settings_btnfl_hover;
    sfSprite *map_backbg;
    sfVector2f pos_map_backbg;
    sfVector2f scale_map_backbg;
    sfSprite *game_first_backbg;
    sfVector2f pos_game_first_backbg;
    sfVector2f scale_game_first_backbg;
    sfSprite *game_second_backbg;
    sfVector2f pos_game_second_backbg;
    sfVector2f scale_game_second_backbg;
    sfSprite *game_third_backbg;
    sfVector2f pos_game_third_backbg;
    sfVector2f scale_game_third_backbg;
    sfSprite *game_sprite_p;
    sfVector2f pos_game_sprite_p;
    sfVector2f scale_game_sprite_p;
    sfSprite *obs_car;
    sfVector2f pos_obs_car;
    sfVector2f scale_obs_car;
    sfSprite *obs_taxi;
    sfVector2f pos_obs_taxi;
    sfVector2f scale_obs_taxi;
    sfSprite *obs_trash;
    sfVector2f pos_obs_trash;
    sfVector2f scale_obs_trash;
    sfSprite *game_hover_bg;
    sfVector2f pos_game_hover_bg;
    sfVector2f scale_game_hover_bg;
    int infin_mod;
    int is_mod_infi_on;
    int play_mod;
    sfIntRect game_deliver_rect;
    sfClock *game_clock;
    double seconds_clock;
    sfTime game_time;
    int jumpx;
    int jumpy;
    int spawning_nb;
    int nbtemp;
    int live_pos_car_x;
    int live_pos_taxi_x;
    int live_pos_trash_x;
    int obs_start;
    sfBool is_at_end;
    int character_pos_x;
    int character_pos_y;
    int game_over;
    int score;
    sfVector2f pos_score;
    sfVector2f scale_score;
    sfMusic *music_menu;
    sfSound *jumping_sound;
} myrunner_t;

void my_putchar(char c);
int my_putstr(char const *str);
sfSprite *spriteinit(char *file);
sfVector2f myposinit(int posx, int posy, sfSprite *mysprite);
sfVector2f mypscaleinit(float scalex, float scaley, sfSprite *mysprite);
sfMusic *mymusicinit(char *file);
sfSound *mysoundinit(char *file);
void initguistruct(myrunner_t *myh);
void initmygame(myrunner_t *myh, sfRenderWindow* window);
void funcexitbtn(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
void funcplaybtn(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
void funcsettingsbtn(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
void hider(myrunner_t *myh, sfRenderWindow* window);
void hover_function(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
void init_settings(myrunner_t *myh);
void print_settings(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
void hover_back_btn(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
void hover_fl_btn(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
void init_map_selector(myrunner_t *myh);
void init_screen_play(myrunner_t *myh);
void display_game(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
void animate_sprite(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
void character_jumping(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
void character_check_jumping(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
int my_put_nbr(int nb);
void parralax_effect_midground(myrunner_t *myh, sfRenderWindow *window, sfEvent event);
void parralax_effect_foreground(myrunner_t *myh, sfRenderWindow *window, sfEvent event);
void init_obstacles (myrunner_t *myh, sfRenderWindow *window, sfEvent event);
void manage_obstacles (myrunner_t *myh, sfRenderWindow *window, sfEvent event);
int spawn_random_obstacles (myrunner_t *myh);
void moving_obstacles (myrunner_t *myh, sfSprite *sprite);
void reset_obstacles_position (myrunner_t *myh);
void set_obstacles_position(myrunner_t *myh, sfSprite *sprite);
void hit_obstacles (myrunner_t *myh, sfRenderWindow *window, sfEvent event);
void init_gameover_style(myrunner_t *myh);
void gameover_menu (myrunner_t *myh, sfRenderWindow *window, sfEvent event);
int my_getnbr(char const *str);
void dispatch_my_main_func(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
void dispatch_my_second_func(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
void dispatch_my_third_func(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
int init_my_assets(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
void help_disp();
void init_settings_two (myrunner_t *myh);
void init_my_rec (myrunner_t *myh);
void init_my_music(myrunner_t *myh);
void play_music(myrunner_t *myh, sfRenderWindow* window, sfEvent event);
#endif /* !RUNNER_H_ */
