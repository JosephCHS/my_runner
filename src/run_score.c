/*
** EPITECH PROJECT, 2018
** score
** File description:
** made by Joseph Chartois
*/

#include "my.h"

void	score_clock(t_glob *glob)
{
	sfTime time;
	float seconds;

	time = sfClock_getElapsedTime(glob->score_clock);
	seconds = time.microseconds / 1000000.0;
	if (seconds >= 0.6) {
		glob->score = glob->score + 4;
		sfClock_restart(glob->score_clock);
	}
}
