/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** Made by Joseph Chartois
*/

#include "my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	int idx = 0;

	while (str[idx] != '\0') {
		my_putchar(str[idx]);
		idx++;
	}
}
