/*
** EPITECH PROJECT, 2018
** game file gestion
** File description:
** made by Joseph Chartois
*/

#include "my.h"

void	game_player1(t_glob *glob, char *av)
{
	t_game1 *game1_l = set_game(glob);
	sfIntRect p1_rect_run = {0, 0, 111, 144};
	sfIntRect en_rect = {0, 0, 320, 258};

	check_map(game1_l, av);
	while (glob->phase == 2) {
		sfRenderWindow_clear(glob->window, sfBlack);
		draw_sprite_game(glob, game1_l);
		gestion_move_parallax(game1_l);
		which_phase_player(game1_l, &p1_rect_run, glob);
		if (gestion_move_ennemy(game1_l, &en_rect) == 1)
			re_set_struct(glob);
		sfRenderWindow_display(glob->window);
		score_clock(glob);
		life_gestion(glob, game1_l);
		event_game(glob);
	}
	music_stop(game1_l);
	game_destroy(game1_l);
}

void	event_game(t_glob *glob)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(glob->window, &event)) {
		if ((event.type == sfEvtKeyPressed &&
		event.key.code == sfKeyEscape) ||
		event.type == sfEvtClosed) {
			glob->phase = 0;
		}
		if ((event.type == sfEvtKeyPressed &&
		event.key.code == sfKeySpace) && glob->p1_phase == 0) {
			glob->p1_phase = 1;
		}
	}
}

void	draw_sprite_game(t_glob *glob, t_game1 *game1_l)
{
	sfRenderWindow_drawSprite(glob->window, game1_l->game_bg1_s, NULL);
	sfRenderWindow_drawSprite(glob->window, game1_l->game_bg2_s, NULL);
	sfRenderWindow_drawSprite(glob->window, game1_l->game_bg3_s, NULL);
	sfRenderWindow_drawSprite(glob->window, game1_l->game_p1_s, NULL);
	sfRenderWindow_drawSprite(glob->window, game1_l->game_en_s, NULL);
	sfRenderWindow_drawSprite(glob->window, game1_l->game_hp_s, NULL);
	sfRenderWindow_drawText(glob->window, game1_l->txt_game_s1, NULL);
	sfRenderWindow_drawText(glob->window, game1_l->txt_game_s2, NULL);
	sfRenderWindow_drawText(glob->window, game1_l->txt_game_l1, NULL);
	sfRenderWindow_drawText(glob->window, game1_l->txt_game_l2, NULL);
}

t_game1	*set_game(t_glob *glob)
{
	t_game1 *game1_l = malloc(sizeof(t_game1));
	sfIntRect rect = {0, 0, 1440, 720};

	game1_l->map_en = -1;
	game1_l = set_game_texture(game1_l);
	set_game_text(game1_l);
	sfSprite_setTexture(game1_l->game_bg1_s, game1_l->game_bg1_t, sfTrue);
	sfSprite_setTextureRect(game1_l->game_bg1_s, rect);
	sfTexture_setRepeated(game1_l->game_bg1_t, sfTrue);
	sfSprite_setTexture(game1_l->game_bg2_s, game1_l->game_bg2_t, sfTrue);
	sfSprite_setTextureRect(game1_l->game_bg2_s, rect);
	sfTexture_setRepeated(game1_l->game_bg2_t, sfTrue);
	sfSprite_setTexture(game1_l->game_bg3_s, game1_l->game_bg3_t, sfTrue);
	sfSprite_setTextureRect(game1_l->game_bg3_s, rect);
	sfTexture_setRepeated(game1_l->game_bg3_t, sfTrue);
	sfSprite_setTexture(game1_l->game_p1_s, game1_l->game_p1_t, sfTrue);
	sfSprite_setTexture(game1_l->game_en_s, game1_l->game_en_t, sfTrue);
	set_struct_game1(game1_l, glob);
	sfSprite_setTexture(game1_l->game_hp_s, game1_l->game_hp_t, sfTrue);
	return (game1_l);
}

t_game1	*set_game_texture(t_game1 *game1_l)
{
	game1_l->game_bg1_t =
		sfTexture_createFromFile("./png/game_bg1.png", NULL);
	game1_l->game_bg2_t =
		sfTexture_createFromFile("./png/game_bg2.png", NULL);
	game1_l->game_bg3_t =
		sfTexture_createFromFile("./png/game_bg3.png", NULL);
	game1_l->game_p1_t =
		sfTexture_createFromFile("./png/player1_run.png", NULL);
	game1_l->game_en_t =
		sfTexture_createFromFile("./png/enemy.png", NULL);
	game1_l->game_sound =
		sfMusic_createFromFile("./music/game_sound.wav");
	game1_l->game_s_l = sfMusic_createFromFile("./music/game_s_l.wav");
	game1_l->game_hp_t = sfTexture_createFromFile("./png/hp.png", NULL);
	game1_l->game_hp_s = sfSprite_create();
	game1_l->game_bg1_s = sfSprite_create();
	game1_l->game_bg2_s = sfSprite_create();
	game1_l->game_bg3_s = sfSprite_create();
	game1_l->game_p1_s = sfSprite_create();
	game1_l->game_en_s = sfSprite_create();
	return (game1_l);
}
