/*
** EPITECH PROJECT, 2018
** ennemy ganondorf
** File description:
** made by Joseph Chartois
*/

#include "my.h"

int	gestion_move_ennemy(t_game1 *game1_l, sfIntRect *en_rect)
{
	sfTime time;
	float seconds;

	time = sfClock_getElapsedTime(game1_l->game_clock);
	seconds = time.microseconds / 1000000.0;
	sfSprite_setTextureRect(game1_l->game_en_s, *en_rect);
	sfSprite_setPosition(game1_l->game_en_s, game1_l->en_setsprite);
	if (seconds >= 0.13) {
		move_game_ennemy(en_rect);
		sfClock_restart(game1_l->game_clock);
	}
	game1_l->en_setsprite.x = game1_l->en_setsprite.x -
		(3 * game1_l->speed_phase);
	if (reset_en_pos(game1_l) == 1)
		return (1);
	return (0);
}

void	move_game_ennemy(sfIntRect *en_rect)
{
	if (en_rect->left == 1920) {
	en_rect->left = 0;
	} else {
	en_rect->left = en_rect->left + 320;
	}
}

int	reset_en_pos(t_game1 *game1_l)
{
	int set_en_x = 0;

	if (game1_l->en_setsprite.x < -200) {
		if (use_map(game1_l) == 1) {
			return (1);
		}
		while (set_en_x < 1480) {
			set_en_x = rand() % 4000;
		}
		game1_l->en_setsprite.x =
			game1_l->en_setsprite.x + set_en_x;
	}
	return (0);
}
