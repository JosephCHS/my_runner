/*
** EPITECH PROJECT, 2018
** map gestion
** File description:
** Made by Joseph Chartois
*/

#include "my.h"

void	check_map(t_game1 *game1_l, char *av)
{
	if ((av[0] == 'm' && av[1] == 'a' &&
	av[2] == 'p' && av[3] == '.' && av[4] == 't' &&
	av[5] == 'x' && av[6] == 't')) {
		game1_l->map_en = 0;
		map_gestion(game1_l);
	}
}

void	map_gestion(t_game1 *game1_l)
{
	FILE *stream = fopen("./map/map.txt", "r");
	char *buf = NULL;
	ssize_t check_getline = 0;
	size_t nb_n = 0;
	int idx = 0;

	if (stream == NULL) {
		return;
	}
	check_getline = getline(&buf, &nb_n, stream);
	while (idx < check_getline) {
		if (buf[idx] == '1') {
			game1_l->map_en++;
		}
		idx++;
	}
}

int	use_map(t_game1 *game1_l)
{
	if (game1_l->map_en != -1) {
		game1_l->map_en--;
	}
	if (game1_l->map_en == 0) {
		my_putstr("\nVICTORY, you have reached the end of this map !");
		my_putstr("\nBut the game is over, you can play again !\n\n");
		return (1);
	}
	return (0);
}
