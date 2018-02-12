/*
** EPITECH PROJECT, 2018
** global for runner
** File description:
** Made by Joseph C.
*/

#include "my.h"

void	set_global(t_glob *glob)
{
	sfVideoMode mode = {1440, 720, 32};

	glob->score_clock = sfClock_create();
	glob->score = 0;
	glob->score_step = 100;
	glob->no_oneshot = 0;
	glob->life = 53;
	glob->phase = 1;
	glob->hp_phase = 0;
	glob->window = sfRenderWindow_create(mode, "Runner", sfClose, NULL);
	sfRenderWindow_setFramerateLimit(glob->window, 60);
	sfRenderWindow_setMouseCursorVisible(glob->window, sfFalse);
}
