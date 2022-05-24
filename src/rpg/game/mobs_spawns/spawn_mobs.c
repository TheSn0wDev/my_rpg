/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** spawn_mobs
*/

#include "mobs.h"
#include "struct.h"
#include "rpg.h"

int check_maps_mobs_spawns(all_t *a, int y, int x, int srate)
{
    if (a->map.txtmap[y][x] == '3') {
        return (rand_nbr(0, (int) 1000000 / srate));
    }
    return (-1);
}

int check_mobs_on_map(all_t *a, int *xc, int *yc, int srate)
{
    int status = 0;
    int x = *xc;
    int y = *yc;

    for (x = 0; a->map.txtmap[y][x]; x++) {
        status = check_maps_mobs_spawns(a, y, x, srate);
        if (status == 1) {
            *xc = x;
            *yc = y;
            return (status);
        }
    }
    *xc = x;
    *yc = y;
    return (status);
}

void set_mob_pos(all_t *a, mobs_object_t *mob)
{
    sfVector2f pos;

    pos.x = mob->pos.x - a->map.map->rect.left;
    pos.y = mob->pos.y - a->map.map->rect.top;
    sfSprite_setPosition(mob->sprite, pos);
}

void get_mob_action(all_t *a, bool cooldown, mobs_lists_t *temp)
{
    if (cooldown == false && check_for_colision(a, temp->mobs) == 1) {
        a->mobs[0].combat_mob = temp->mobs;
        a->scene = COMBAT;
        temp->mobs.status = -1;
        a->mobs->mb_nb -= 1;
        cooldown = true;
        return;
    }
    if (get_seconds(a->mobs->combat_cooldown) > 1) {
        sfClock_restart(a->mobs->combat_cooldown);
        cooldown = false;
    }
    if (cooldown == false && a->in_dialogue == false)
        mobs_movements(a, &temp->mobs);
}

void handle_mobs(all_t *a)
{
    mobs_lists_t *temp = a->mobs[0].mb_list;
    static bool cooldown = false;

    while (temp != NULL && temp->next != NULL) {
        if (temp->mobs.status != -1) {
            set_mob_pos(a, &temp->mobs);
            get_mob_action(a, cooldown, temp);
            sfRenderWindow_drawSprite(a->window, temp->mobs.sprite, NULL);
        }
        temp = temp->next;
    }
}