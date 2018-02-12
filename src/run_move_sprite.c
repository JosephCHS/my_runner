/*
** EPITECH PROJECT, 2018
** movement sprite
** File description:
** Made by Joseph Chartois
*/

#include "my.h"

void	gestion_move_player1(t_game1 *game1_l, sfIntRect *p1_rect_run)
{
	sfTime time;
	float seconds;
	sfVector2f p1_setsprite = {-5, 535};

	time = sfClock_getElapsedTime(game1_l->game_clock);
	seconds = time.microseconds / 1000000.0;
	sfSprite_setTextureRect(game1_l->game_p1_s, *p1_rect_run);
	sfSprite_setPosition(game1_l->game_p1_s, p1_setsprite);
	if (seconds >= 0.13) {
		move_game_player1(p1_rect_run);
	}
}

void	move_game_player1(sfIntRect *p1_rect_run)
{
	if (p1_rect_run->left == 555) {
		p1_rect_run->left = 0;
	} else {
		p1_rect_run->left = p1_rect_run->left + 111;
	}
}

void	gestion_move_parallax(t_game1 *game1_l)
{
	static sfIntRect	para_rect_1 = {0, 0, 1440, 720};
	static sfIntRect	para_rect_2 = {0, 0, 1440, 720};
	static sfIntRect	para_rect_3 = {0, 0, 1440, 720};

	para_rect_1.left = para_rect_1.left + 1 * game1_l->speed_phase;
	sfSprite_setTextureRect(game1_l->game_bg1_s, para_rect_1);
	para_rect_2.left = para_rect_2.left + 2 * game1_l->speed_phase;
	sfSprite_setTextureRect(game1_l->game_bg2_s, para_rect_2);
	para_rect_3.left = para_rect_3.left + 3 * game1_l->speed_phase;
	sfSprite_setTextureRect(game1_l->game_bg3_s, para_rect_3);
}
