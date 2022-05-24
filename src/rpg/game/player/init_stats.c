/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

sfText *init_stat_text(sfVector2f pos, float size, sfColor color, char *str)
{
    sfText *text = create_texts("assets/fonts/diablo_h.ttf", size, pos, color);
    sfText_setString(text, str);
    return (text);
}

void init_player_displaying_stats(player_t *player)
{
    sfColor color = sfColor_fromRGBA(211, 161, 6, 255);
    sfVector2f txt_pos[8] = {{1600, 500}, {1600, 600}, {1600, 650}, {1600,
    700}, {1600, 750}, {1600, 800}, {1600, 850}, {1600, 900}};
    char *arr[8] = { my_itoa(player->obj->stat.level),
    my_itoa(player->obj->stat.attack), my_itoa(player->obj->stat.speed),
    my_itoa(player->obj->stat.gold), my_itoa(player->obj->stat.hp),
    my_itoa(player->obj->stat.attack), my_itoa(player->obj->stat.defense),
    my_itoa(player->obj->stat.level) };

    player->stats = my_malloc(sizeof(sfText *) * 8);
    for (int i = 0; i < 8; i++) {
        player->stats[i] = init_stat_text(txt_pos[i], 12, color, arr[i]);
    }
}