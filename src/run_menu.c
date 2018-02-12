/*
** EPITECH PROJECT, 2018
** menu of my runner
** File description:
** Made by Joseph C.
*/

#include "my.h"

void	menu(t_glob *glob)
{
	t_menu *menu_l = set_menu();

	sfMusic_play(menu_l->menu_sound);
	sfMusic_setLoop(menu_l->menu_sound, sfTrue);
	while ((glob->phase) == 1) {
		sfRenderWindow_clear(glob->window, sfBlack);
		sfRenderWindow_drawSprite(glob->window,
					menu_l->menu_s_background, NULL);
		sfRenderWindow_display(glob->window);
		event_menu(glob);
	}
	sfMusic_stop(menu_l->menu_sound);
	menu_destroy(menu_l);
	free(menu_l);
}

void	event_menu(t_glob *glob)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(glob->window, &event)) {
		if (event.type == sfEvtKeyPressed &&
		event.key.code == (sfKeyLeft)) {
			glob->phase = 2;
		}
		if ((event.type == sfEvtKeyPressed &&
		event.key.code == sfKeyEscape) ||
		event.type == sfEvtClosed) {
			glob->phase = 0;
		}
	}
}

t_menu	*set_menu()
{
	t_menu *menu_l = malloc(sizeof(t_menu));
	sfVector2f bg_menu = {0.75, 0.666666};

	menu_l->menu_t_background =
		sfTexture_createFromFile("./png/menu_bg.png", NULL);
	menu_l->menu_sound = sfMusic_createFromFile("./music/menu_sound.wav");
	menu_l->menu_s_background = sfSprite_create();
	sfSprite_setTexture(menu_l->menu_s_background,
			menu_l->menu_t_background, sfTrue);
	sfSprite_scale(menu_l->menu_s_background, bg_menu);
	return (menu_l);
}
