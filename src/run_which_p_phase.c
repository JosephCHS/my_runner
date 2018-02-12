/*
** EPITECH PROJECT, 2018
** which player phase jump or run
** File description:
** Made by Joseph Chartois
*/

#include "my.h"

void	which_phase_player(t_game1 *game1_l, sfIntRect *p1_rect_run,
			t_glob * glob)
{
	if (glob->p1_phase == 0) {
		gestion_move_player1(game1_l, p1_rect_run);
	} else {
		jump_player1(game1_l, glob, p1_rect_run);
	}
}
