/*
** EPITECH PROJECT, 2018
** life gestion
** File description:
** Made by Joseph Chartois
*/

#include "my.h"

void	life_gestion(t_glob *glob, t_game1 *game1_l)
{
	char *score = display_score(glob);
	char *life = display_life(glob);

	sfText_setString(game1_l->txt_game_s2, score);
	sfText_setString(game1_l->txt_game_l2, life);
	if (glob->no_oneshot == 0 && glob->p1_phase == 0 &&
	game1_l->en_setsprite.x >= - 155 && game1_l->en_setsprite.x <= 105) {
		glob->life--;
		glob->no_oneshot++;
		sfMusic_play(game1_l->game_s_l);
	}
	if (game1_l->en_setsprite.x < -155)
		glob->no_oneshot = 0;
	reset_value(glob, game1_l);
	life_fall(glob, game1_l);
	free(life);
	free(score);
}

void	reset_value(t_glob *glob, t_game1 *game1_l)
{
	if (glob->life == 48) {
		glob->phase = 1;
		my_putstr("====== GAME OVER ======\nScore : ");
		my_put_nbr(glob->score);
		my_putstr("\n\n");
		glob->life = 53;
		glob->score = 0;
		glob->no_oneshot = 0;
		glob->score_step = 100;
		glob->hp_phase = 0;
		game1_l->speed_phase = 1;
		game1_l->map_en = -1;
	}
}

void	life_fall(t_glob *glob, t_game1 *game1_l)
{
	sfSprite_setPosition(game1_l->game_hp_s, game1_l->life_setsprite);
	if (glob->score > glob->score_step && glob->hp_phase == 0) {
		game1_l->life_setsprite.y = game1_l->life_setsprite.y + 6;
	}
	reset_life_fall(glob, game1_l);
}

void	reset_life_fall(t_glob *glob, t_game1 *game1_l)
{
	if (game1_l->life_setsprite.y > 600)
		glob->hp_phase = 1;
	if (glob->hp_phase == 1) {
		glob->life++;
		game1_l->life_setsprite.y = -100;
		glob->score_step = glob->score_step + 100;
		glob->hp_phase = 0;
		game1_l->speed_phase++;
	}
}
