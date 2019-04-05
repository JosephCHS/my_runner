/*
** EPITECH PROJECT, 2017
** header
** File description:
** made by Joseph C.
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_menu
{
	sfTexture *menu_t_background;
	sfSprite *menu_s_background;
	sfMusic *menu_sound;
}t_menu;

typedef struct s_game1
{
	sfTexture *game_bg1_t;
	sfTexture *game_bg2_t;
	sfTexture *game_bg3_t;
	sfTexture *game_p1_t;
	sfTexture *game_en_t;
	sfTexture *game_hp_t;
	sfSprite *game_bg1_s;
	sfSprite *game_bg2_s;
	sfSprite *game_bg3_s;
	sfSprite *game_p1_s;
	sfSprite *game_en_s;
	sfSprite *game_hp_s;
	sfMusic *game_sound;
	sfMusic *game_s_l;
	sfClock *game_clock;
	sfVector2f en_setsprite;
	sfVector2f life_setsprite;
	sfVector2f p1_ss_jump;
	int up_to_down;
	int map_en;
	int speed_phase;
	sfText *txt_game_s1;
	sfText *txt_game_s2;
	sfText *txt_game_l1;
	sfText *txt_game_l2;
	sfFont *font_game;
}t_game1;

typedef struct s_variable_global
{
	sfClock *score_clock;
	int score;
	int score_step;
	int no_oneshot;
	int life;
	int phase;
	int p1_phase;
	int hp_phase;
	sfRenderWindow *window;
}t_glob;

//run_launcher.c
void	launcher_of_phase(char *);
void	glob_destroy(t_glob *);
//run_menu.c
void	menu(t_glob *);
void	event_menu(t_glob *);
t_menu	*set_menu();
//run_global.c
void	set_global(t_glob *);
//run_game.c
void	game_player1(t_glob *, char *);
void	event_game(t_glob *);
void	draw_sprite_game(t_glob *, t_game1 *);
t_game1	*set_game(t_glob *);
t_game1	*set_game_texture(t_game1 *);
//run_help.c
int		print_the_usage(int, char **, char **);
//my_putstr.c
void	my_putchar(char);
void	my_putstr(char *);
//run_check_error.c
int		check_error(int, char **, char **);
int		wrong_av1(char *);
int		check_missing_files(void);
int		no_env(char **);
//my_strcmp.c
int		my_strcmp(char const *, char const *);
//run_init_array.c
char	**init_array_wrong_av1(void);
char	**init_array_path(void);
//run_destroy.c
void	menu_destroy(t_menu *);
void	game_destroy(t_game1 *);
void	game_destroy2(t_game1 *);
void	music_stop(t_game1 *);
//run_move_sprite.c
void	gestion_move_player1(t_game1 *, sfIntRect *);
void	move_game_player1(sfIntRect *);
void	gestion_move_parallax(t_game1 *);
//run_load_clock_music.c
void	load_clock_music(t_game1 *);
//run_ennemy.c
int		gestion_move_ennemy(t_game1 *, sfIntRect *);
void	move_game_ennemy(sfIntRect *);
int		reset_en_pos(t_game1 *);
//run_set_struct.c
void	set_struct_game1(t_game1 *, t_glob *);
void	re_set_struct(t_glob *);
//run_which_p_phase.c
void	which_phase_player(t_game1 *, sfIntRect *, t_glob *);
//run_jump.c
void	jump_player1(t_game1 *, t_glob *, sfIntRect *);
void	jump_player1_1(t_game1 *, sfIntRect *);
void	jump_player1_2(t_game1 *, sfIntRect *);
void	jump_player1_3(t_game1 *, t_glob *, sfIntRect *);
//run_life.c
void	life_gestion(t_glob *, t_game1 *);
void	reset_value(t_glob *, t_game1 *);
void	life_fall(t_glob *, t_game1 *);
void	reset_life_fall(t_glob *, t_game1 *);
//run_score.c
void	score_clock(t_glob *);
//my_put_nbr.c
void	my_put_nbr(int);
//run_map.c
void	check_map(t_game1 *, char *);
void	map_gestion(t_game1 *);
int		use_map(t_game1 *);
//my_put_error_str.c
void	my_err_putchar(char);
void	my_err_putstr(char *);
//run_text.c
void	set_game_text(t_game1 *);
char	*display_score(t_glob *);
char	*display_life(t_glob *);

#endif	/* MY_H_ */
