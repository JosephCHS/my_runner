/*
** EPITECH PROJECT, 2018
** launcher_phase
** File description:
** Made by Joseph C.
*/

#include "my.h"

void	launcher_of_phase(char *av)
{
	t_glob *glob = malloc(sizeof(t_glob));

	set_global(glob);
	while (sfRenderWindow_isOpen(glob->window)) {
		switch (glob->phase) {
		case 1:
			menu(glob);
			break;
		case 2:
			game_player1(glob, av);
			break;
		default:
			sfRenderWindow_close(glob->window);
		}
	}
	sfRenderWindow_destroy(glob->window);
	free(glob);
}
