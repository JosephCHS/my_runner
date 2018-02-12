/*
** EPITECH PROJECT, 2018
** init array for error gestion
** File description:
** Made by Joseph Chartois
*/

#include "my.h"

char	**init_array_wrong_av1(void)
{
	char **array_wrong_av1 = malloc(sizeof(char *) * 4);

	array_wrong_av1[0] = "-i";
	array_wrong_av1[1] = "-h";
	array_wrong_av1[2] = "map.txt";
	return (array_wrong_av1);
}

char	**init_array_path(void)
{
	char **array_path = malloc(sizeof(char *) * 11);

	array_path[0] = "./music/game_sound.wav";
	array_path[1] = "./music/menu_sound.wav";
	array_path[2] = "./png/enemy.png";
	array_path[3] = "./png/game_bg1.png";
	array_path[4] = "./png/game_bg2.png";
	array_path[5] = "./png/game_bg3.png";
	array_path[6] = "./png/player1_run.png";
	array_path[7] = "./png/menu_bg.png";
	array_path[8] = "./music/game_s_l.wav";
	array_path[9] = "./png/hp.png";
	array_path[10] = "./font/font.ttf";
	return (array_path);
}
