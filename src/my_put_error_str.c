/*
** EPITECH PROJECT, 2018
** error putstr
** File description:
** Made by Joseph Chartois
*/

#include "my.h"

void	my_err_putchar(char c)
{
	write(2, &c, 1);
}

void	my_err_putstr(char *str)
{
	int idx = 0;

	while (str[idx] != '\0') {
		my_err_putchar(str[idx]);
		idx++;
	}
}
