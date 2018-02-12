/*
** EPITECH PROJECT, 2018
** my_runner main file
** File description:
** Made by Joseph C.
*/

#include "my.h"

int	main(int ac, char **av, char **env)
{
	if (print_the_usage(ac, av, env) == 0) {
		return (0);
	}
	if (check_error(ac, av, env) == 84) {
		return (84);
	}
	launcher_of_phase(av[1]);
	return (0);
}
