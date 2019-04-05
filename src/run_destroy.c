/*
** EPITECH PROJECT, 2018
** destroy
** File description:
** Made by Joseph C.
*/

#include "my.h"

void	menu_destroy(t_menu *menu_l)
{
	sfMusic_destroy(menu_l->menu_sound);
	sfTexture_destroy(menu_l->menu_t_background);
	sfSprite_destroy(menu_l->menu_s_background);
}

void	game_destroy(t_game1 *game1_l)
{
	sfSprite_destroy(game1_l->game_bg1_s);
	sfSprite_destroy(game1_l->game_bg2_s);
	sfSprite_destroy(game1_l->game_bg3_s);
	sfSprite_destroy(game1_l->game_p1_s);
	sfSprite_destroy(game1_l->game_en_s);
	sfSprite_destroy(game1_l->game_hp_s);
	sfTexture_destroy(game1_l->game_bg1_t);
	sfTexture_destroy(game1_l->game_bg2_t);
	sfTexture_destroy(game1_l->game_bg3_t);
	sfTexture_destroy(game1_l->game_p1_t);
	sfTexture_destroy(game1_l->game_en_t);
	sfTexture_destroy(game1_l->game_hp_t);
	sfMusic_destroy(game1_l->game_sound);
	sfMusic_destroy(game1_l->game_s_l);
	game_destroy2(game1_l);
}

void	game_destroy2(t_game1 *game1_l)
{
	sfText_destroy(game1_l->txt_game_s1);
	sfText_destroy(game1_l->txt_game_s2);
	sfText_destroy(game1_l->txt_game_l1);
	sfText_destroy(game1_l->txt_game_l2);
	sfFont_destroy(game1_l->font_game);
	sfClock_destroy(game1_l->game_clock);
	free(game1_l);
}

void	music_stop(t_game1 *game1_l)
{
	sfMusic_stop(game1_l->game_sound);
	sfMusic_stop(game1_l->game_s_l);
}
