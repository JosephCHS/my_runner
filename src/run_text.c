/*
** EPITECH PROJECT, 2018
** set text
** File description:
** made by Joseph Chartois
*/

#include "my.h"

void	set_game_text(t_game1 *game1_l)
{
	sfVector2f txt_position_s1 = {1200, 0};
	sfVector2f txt_position_s2 = {1320, 0};
	sfVector2f txt_position_l1 = {0, 0};
	sfVector2f txt_position_l2 = {90, 0};

	game1_l->font_game = sfFont_createFromFile("./font/font.ttf");
	game1_l->txt_game_s1 = sfText_create();
	game1_l->txt_game_s2 = sfText_create();
	game1_l->txt_game_l1 = sfText_create();
	game1_l->txt_game_l2 = sfText_create();
	sfText_setPosition(game1_l->txt_game_s1, txt_position_s1);
	sfText_setPosition(game1_l->txt_game_s2, txt_position_s2);
	sfText_setPosition(game1_l->txt_game_l1, txt_position_l1);
	sfText_setPosition(game1_l->txt_game_l2, txt_position_l2);
	sfText_setFont(game1_l->txt_game_s1, game1_l->font_game);
	sfText_setFont(game1_l->txt_game_s2, game1_l->font_game);
	sfText_setFont(game1_l->txt_game_l1, game1_l->font_game);
	sfText_setFont(game1_l->txt_game_l2, game1_l->font_game);
	sfText_setString(game1_l->txt_game_s1, "SCORE :");
	sfText_setString(game1_l->txt_game_l1, "LIFE :");
}

char	*display_score(t_glob *glob)
{
	char *score = NULL;
	int size = 0;
	int nb = glob->score;

	while (nb != 0) {
		nb = nb / 10;
		size++;
	}
	nb = glob->score;
	score = malloc(sizeof(char) * (size + 1));
	score[size] = '\0';
	size--;
	while (size != -1) {
		score[size] = (nb % 10) + 48;
		nb = nb / 10;
		size--;
	}
	return (score);
}

char	*display_life(t_glob *glob)
{
	char *life = NULL;
	int size = 0;
	int nb = (glob->life) - 48;

	while (nb != 0) {
		nb = nb / 10;
		size++;
	}
	nb = (glob->life) - 48;
	life = malloc(sizeof(char) * (size + 1));
	life[size] = '\0';
	size--;
	while (size != -1) {
		life[size] = (nb % 10) + 48;
		nb = nb / 10;
		size--;
	}
	return (life);
}
