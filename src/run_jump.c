/*
** EPITECH PROJECT, 2018
** jump player1
** File description:
** Made by Joseph Chartois
*/

#include "my.h"

void	jump_player1(t_game1 *game1_l, t_glob *glob, sfIntRect *p1_rect_run)
{
	jump_player1_1(game1_l, p1_rect_run);
	jump_player1_2(game1_l, p1_rect_run);
	jump_player1_3(game1_l, glob, p1_rect_run);
}

void	jump_player1_1(t_game1 *game1_l, sfIntRect *p1_rect_run)
{
	if (game1_l->up_to_down == 0 && game1_l->p1_ss_jump.y <= 535) {
		p1_rect_run->left = 666;
		sfSprite_setTextureRect(game1_l->game_p1_s, *p1_rect_run);
		sfSprite_setPosition(game1_l->game_p1_s, game1_l->p1_ss_jump);
		game1_l->p1_ss_jump.y =
			game1_l->p1_ss_jump.y - 4 * game1_l->speed_phase;
	}
}

void	jump_player1_2(t_game1 *game1_l, sfIntRect *p1_rect_run)
{
	if (game1_l->up_to_down == 0 && game1_l->p1_ss_jump.y <= 450) {
		game1_l->up_to_down = 1;
	}
	if (game1_l->up_to_down == 1 && game1_l->p1_ss_jump.y >= 200) {
		p1_rect_run->left = 777;
		sfSprite_setTextureRect(game1_l->game_p1_s, *p1_rect_run);
		sfSprite_setPosition(game1_l->game_p1_s, game1_l->p1_ss_jump);
		game1_l->p1_ss_jump.y =
			game1_l->p1_ss_jump.y - 4 * game1_l->speed_phase;
	}
}

void	jump_player1_3(t_game1 *game1_l, t_glob *glob, sfIntRect *p1_rect_run)
{
	if (game1_l->p1_ss_jump.y <= 200 && game1_l->up_to_down == 1) {
		game1_l->up_to_down = 2;
	}
	if (game1_l->up_to_down == 2 && game1_l->p1_ss_jump.y < 535) {
		p1_rect_run->left = 888;
		sfSprite_setTextureRect(game1_l->game_p1_s, *p1_rect_run);
		sfSprite_setPosition(game1_l->game_p1_s, game1_l->p1_ss_jump);
		game1_l->p1_ss_jump.y =
			game1_l->p1_ss_jump.y + 4 * (game1_l->speed_phase + 1);
	}
	if (game1_l->up_to_down == 2 && game1_l->p1_ss_jump.y >= 535) {
		glob->p1_phase = 0;
		game1_l->up_to_down = 0;
		p1_rect_run->left = 0;
		game1_l->p1_ss_jump.y = 535;
	}
}
