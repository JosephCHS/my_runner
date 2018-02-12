/*
** EPITECH PROJECT, 2018
** print the usage
** File description:
** Made by Joseph Chartois
*/

#include "my.h"

int	print_the_usage(int ac, char **av, char **env)
{
	if (no_env(env) == 84) {
		return (84);
	}
	if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
		my_putstr("\nFinite runner created with CSFML.\n\nUSAGE\n\t");
		my_putstr("./my runner map.txt\n\tdon't change the name of");
		my_putstr(" the map, your game will not start");
		my_putstr("\n\tput your map.txt at the root in ./map/");
		my_putstr("\n");
		my_putstr("\tuse the number 1 to create has many ganondorf");
		my_putstr(" has you want");
		my_putstr("\n\texemple of map.txt: 1  1  1 1 1\n\tif no map");
		my_putstr(".txt is loaded, the inf mode will start");
		my_putstr("\n\n\nOPTIONS\n -i\t\tlaunch");
		my_putstr(" the game in infinity and random mode.\n");
		my_putstr(" -h\t\tprint the usage and quit.\n\n");
		my_putstr("USER INTERACTIONS\n SPACE_KEY\tjump.\n");
		my_putstr(" ECHAP_KEY\tquit the game.\n\n");
		return (0);
	}
	return (84);
}
