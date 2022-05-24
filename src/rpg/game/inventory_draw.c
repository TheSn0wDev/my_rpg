/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game
*/

#include "rpg.h"
#include "struct.h"

void draw_items(all_t *a)
{
    for (int i = 0; i < a->inventory.items_size; i++)
        sfRenderWindow_drawSprite(a->window, a->inventory.items[i].s,
        NULL);
}

void draw_stat_info(all_t *a, char *stat, int value, int line)
{
    sfVector2f pos = {1525, 420};

    pos.y += 50 * line;
    sfText_setPosition(a->inventory.stats.text, pos);
    sfText_setString(a->inventory.stats.text, stat);
    sfRenderWindow_drawText(a->window, a->inventory.stats.text, NULL);
    pos.x += 90;
    sfText_setPosition(a->inventory.stats.text, pos);
    sfText_setString(a->inventory.stats.text, to_str(value));
    sfRenderWindow_drawText(a->window, a->inventory.stats.text, NULL);
}

void draw_stats(all_t *a)
{
    stat_t stats = a->player->obj->stat;

    draw_stat_info(a, "Level", stats.level, 0);
    draw_stat_info(a, "Attack", stats.attack, 1);
    draw_stat_info(a, "Defense", stats.defense, 2);
    draw_stat_info(a, "Health", stats.hp, 3);
    draw_stat_info(a, "Speed", (int)stats.speed, 4);
    draw_stat_info(a, "Gold", stats.gold, 5);
}

void draw_inventory(all_t *a)
{
    if (!a->inventory.show)
        return;
    sfRenderWindow_drawSprite(a->window, a->inventory.sprite.s, NULL);
    draw_stats(a);
    if (a->inventory.items == NULL)
        return;
    for (int i = 0; i < a->inventory.items_size; i++)
        if (a->inventory.items[i].drawable)
            sfRenderWindow_drawSprite(a->window, a->inventory.items[i].s,
            NULL);
}