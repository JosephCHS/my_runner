/*
** EPITECH PROJECT, 2018
** check_error.c
** File description:
** Made by Joseph Chartois
*/

#include "my.h"

int	check_error(int ac, char **av, char **env)
{
	if (no_env(env) == 84) {
		my_err_putstr("Error: no env\nRetry with -h\n");
		return (84);
	}
	if (ac != 2 || wrong_av1(av[1]) == 84) {
		my_err_putstr("Error: wrong argument\nRetry with -h\n");
		return (84);
	}
	if (check_missing_files() == 84) {
		my_err_putstr("Error: missing file(s)\nRetry with -h\n");
		return (84);
	}
	return (0);
}

int	wrong_av1(char *av)
{
	char **array_wrong_av1 = NULL;
	int idx = 0;

	array_wrong_av1 = init_array_wrong_av1();
	while (idx != 3) {
		if (my_strcmp(av, array_wrong_av1[idx]) == 0) {
			free(array_wrong_av1);
			return (0);
		}
		idx++;
	}
	free(array_wrong_av1);
	return (84);
}

int	check_missing_files(void)
{
	int idx = 0;
	int fd = 0;
	char **array_path = NULL;

	array_path = init_array_path();
	while (idx != 11) {
		fd = open(array_path[idx], O_RDONLY);
		if (fd == -1) {
			free(array_path);
			return (84);
		}
		idx++;
	}
	free(array_path);
	return (0);
}

int	no_env(char **env)
{
	int cnt = 0;

	while (env[cnt] != NULL) {
		if (env[cnt][0] == 'T' && env[cnt][1] == 'E' &&
		env[cnt][2] == 'R' && env[cnt][3] == 'M' &&
		env[cnt][4] == '=' && env[cnt][5] != '\0') {
			return (0);
		}
		cnt++;
	}
	return (84);
}
