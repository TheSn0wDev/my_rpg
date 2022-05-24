/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** end
*/

#include "rpg.h"
#include "struct.h"

void init_end(all_t *a)
{
    sfMusic_stop(a->cin[0].monolog);
    a->main_menu->menu_music = create_music("assets/musics/heavens_song.ogg");
    sfMusic_setLoop(a->main_menu->menu_music, sfTrue);
    sfMusic_setVolume(a->main_menu->menu_music, 50);
    sfMusic_play(a->main_menu->menu_music);
}

void display_end(all_t *a)
{
    if (a->cin->start_mus == true) {
        init_end(a);
        a->cin->start_mus = false;
    }
    sfRenderWindow_drawSprite(a->window, a->cin[0].obj[15].s, NULL);
}