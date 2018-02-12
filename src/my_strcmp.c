/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** Made by Joseph Chartois
*/

int	my_strcmp(char const *str1, char const *str2)
{
	int idx = 0;
	int dif = 0;

	while (str1[idx] != '\0' && str2[idx] != '\0') {
		dif = str1[idx] - str2[idx];
		if (dif == 0) {
			idx++;
		} else {
			return (dif);
		}
	}
	return (0);
}
