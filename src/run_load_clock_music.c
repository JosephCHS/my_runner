/*
** EPITECH PROJECT, 2018
** load music and clock for the game
** File description:
** Made by Joseph Chartois
*/

#include "my.h"

void	load_clock_music(t_game1 *game1_l)
{
	game1_l->game_clock = sfClock_create();
	sfMusic_play(game1_l->game_sound);
	sfMusic_setLoop(game1_l->game_sound, sfTrue);
}
