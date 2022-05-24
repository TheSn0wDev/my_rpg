/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init
*/

#include "rpg.h"
#include "struct.h"

void create_cinematic_assets_two(all_t *a)
{
    menu_object_t first = {0, 0, {1, 1},
    {0, 0}, 0, 0, {0, 0, 1920, 1080}, 0};
    init_menu_object(&first, "assets/cinematic/bandes.png");
    menu_object_t title = {0, 0, {1, 1},
    {0, 0}, 0, 0, {0, 0, 1920, 1080}, 0};

    init_menu_object(&title, "assets/cinematic/title_screen.jpg");
    a->cin[0].obj[14] = first;
    a->cin[0].obj[15] = title;
    a->cin->trans = create_rectangle();
    sfRectangleShape_setSize(a->cin->trans, (sfVector2f){1920, 1080});
    a->cin->color = sfColor_fromRGBA(0, 0, 0, 0);
    sfRectangleShape_setFillColor(a->cin->trans, a->cin->color);
    a->cin->transition = false;
    a->cin[0].obj[4].scale = (sfVector2f){1.20, 1.20};
    sfSprite_setScale(a->cin[0].obj[4].s, (sfVector2f){1.20, 1.20});
    a->cin[0].obj[10].scale = (sfVector2f){1.20, 1.20};
    sfSprite_setOrigin(a->cin[0].obj[12].s, (sfVector2f){960, 540});
    sfSprite_setScale(a->cin[0].obj[12].s, (sfVector2f){1.40, 1.40});
    a->cin[0].obj[12].scale = (sfVector2f){1.40, 1.40};
}

void create_cinematic_assets(all_t *a)
{
    menu_object_t first;

    a->cin[0].clock = create_clock();
    a->cin->monolog = create_music("assets/musics/cinematic.ogg");
    sfMusic_setVolume(a->cin->monolog, 50);
    sfMusic_play(a->cin->monolog);
    a->cin[0].obj = my_malloc(sizeof(menu_object_t) * 16);
    for (int i = 0; i < 14; i++) {
        first = (menu_object_t){0, 0, {1, 1},
        {960, 540}, 0, 0, {0, 0, 1920, 1080}, 0};
        init_menu_object(&first,
        my_strcat(my_strcat("assets/cinematic/", my_itoa(i + 1)), ".jpg"));
        a->cin[0].obj[i] = first;
        sfSprite_setOrigin(a->cin[0].obj[i].s, (sfVector2f){960, 540});
    }
    a->cin->end = false;
    a->cin->start_mus = false;
    create_cinematic_assets_two(a);
}