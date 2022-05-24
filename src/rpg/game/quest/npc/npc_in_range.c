/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** npc_in_range
*/

#include "rpg.h"
#include "struct.h"

sfVector2f get_player_pos_npc(all_t *a)
{
    sfVector2f p_pos = {(a->player->obj->pos.x + a->map.map->rect.left),
    (a->player->obj->pos.y + a->map.map->rect.top)};

    return (p_pos);
}

sfVector2f get_player_posl_npc(all_t *a)
{
    sfVector2f p_pos = get_player_pos_npc(a);
    sfVector2f p_posl = {p_pos.x + (a->player->obj->rect.width *
    a->player->obj->scale.x), p_pos.y + (a->player->obj->rect.height *
    a->player->obj->scale.y)};

    return (p_posl);
}

int continue_in_case_wrong_map(all_t *a, int i)
{
    if (a->map.world != SPAWN && (
    a->npc[0].obj[i].id == QUESTMASTER
    || a->npc[0].obj[i].id == SPAWNNPC
    || a->npc[0].obj[i].id == FORGERON))
        return (1);
    if ((a->map.world != FOPSPACE && (a->npc[0].obj[i].id == SKELETON ||
    a->npc[0].obj[i].id == OLDIDK))) {
        return (1);
    }
    return (-1);
}

int is_npc_in_range(all_t *a)
{
    sfVector2f p_pos = get_player_pos_npc(a);
    sfVector2f p_posl = get_player_posl_npc(a);
    sfVector2f n_pos = {0, 0};
    sfVector2f n_posl = {0, 0};

    for (int i = 0; i < a->npc->npc_nb; i++) {
        if (continue_in_case_wrong_map(a, i) == 1)
            continue;
        n_pos = (sfVector2f) {a->npc[0].npc_arr[i].pos.x,
        a->npc[0].npc_arr[i].pos.y};
        n_posl = (sfVector2f) {n_pos.x + (a->npc[0].obj[i].rect.width *
        a->npc[0].npc_arr[i].scale.x), n_pos.y +
        (a->npc[0].npc_arr[i].rect.height * a->npc[0].npc_arr[i].scale.y)};
        if (n_pos.x - 25 <= p_posl.x && p_pos.x <= 25 + n_posl.x
        && n_pos.y - 25 <= p_posl.y && p_pos.y <= 25 + n_posl.y) {
            return (a->npc[0].npc_arr[i].id);
        }
    }
    return (-1);
}

void handle_interaction_button(all_t *a, int id)
{
    char *c;

    if (!a->in_dialogue) {
        c = my_malloc(sizeof(char) * 2);
        c[0] = a->key_arr[4];
        c[1] = '\0';
        sfSprite_setPosition(a->npc->interact_button[0].s, (sfVector2f)
        {a->npc[0].npc_arr[id].pos.x + 40 - a->map.map->rect.left,
        a->npc[0].npc_arr[id].pos.y - 50 - a->map.map->rect.top});
        sfText_setPosition(a->npc[0].interact_key, (sfVector2f)
        {a->npc[0].npc_arr[id].pos.x + 50 - a->map.map->rect.left,
        a->npc[0].npc_arr[id].pos.y - 55 - a->map.map->rect.top});
        sfText_setString(a->npc[0].interact_key, c);
        return;
    }
}