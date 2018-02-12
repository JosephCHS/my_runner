/*
** EPITECH PROJECT, 2018
** set_struct_game1
** File description:
** Made by Joseph Chartois
*/

#include "my.h"

void	set_struct_game1(t_game1 *game1_l, t_glob *glob)
{
	glob->p1_phase = 0;
	game1_l->speed_phase = 1;
	game1_l->en_setsprite.x = 1100;
	game1_l->en_setsprite.y = 424;
	game1_l->life_setsprite.x = 10;
	game1_l->life_setsprite.y = -100;
	game1_l->p1_ss_jump.x = -5;
	game1_l->p1_ss_jump.y = 535;
	game1_l->up_to_down = 0;
	load_clock_music(game1_l);
}

void	re_set_struct(t_glob *glob)
{
	glob->phase = 1;
	glob->score = 0;
	glob->life = 53;
	glob->p1_phase = 0;
}
