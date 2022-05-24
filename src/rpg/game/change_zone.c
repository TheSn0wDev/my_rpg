/*
** EPITECH PROJECT, 2020
** workspace (Workspace)
** File description:
** change_zone.c
*/

#include "rpg.h"
#include "struct.h"

void reloard_minimap(all_t *a, char *fp)
{
    sfTexture *texture = create_texture(fp, NULL);

    sfSprite_setTexture(a->map.mini_map->s, texture, sfTrue);
}

void handle_zones_two(all_t *a, char **map, char **txt)
{
    sfIntRect pos2[4] = {{a->map.map->rect.left, 0, a->player->obj->pos.x,
    700}, {300, 0, 800, 100}, {0, 0, 250, 100}, {0, 0, 0, 0}};

    if (is_colliding(a, sfKeyUp) == 8) {
        a->map.world--;
        reload_map(a, map[a->map.world], txt[a->map.world]);
        reloard_map_player_pos(a, pos2[a->map.world]);
        reloard_minimap(a, map[a->map.world]);
        make_transition_between_maps(a);
    }
}

void handle_zones(all_t *a)
{
    char *map[4] = {"assets/maps/small_castle_map.png",
    "assets/maps/fopenspace.png", "assets/maps/DUNGEON.png",
    "assets/maps/boss.png"};
    char *txt[4] = {"src/rpg/game/map/test.txt", "src/rpg/game/map/fos.txt",
    "src/rpg/game/map/dungeon.txt", "src/rpg/game/map/dungeon_boss.txt"};
    sfIntRect pos[4] = {{500, 1500, 500, 500}, {a->map.map->rect.left, 1248,
    a->player->obj->pos.x, 1000}, {400, 1300, 800, 700}, {0, 1600, 250, 500}};

    if (is_colliding(a, sfKeyUp) == 9
    && ((a->map.world == SPAWN && a->npc[0].npc_arr[FORGERON].quest == false)
    || (a->map.world == FOPSPACE && a->npc[0].obj[OLDIDK].quest == true) ||
    a->map.world == DUNGEON)) {
        a->map.world++;
        reload_map(a, map[a->map.world], txt[a->map.world]);
        reloard_map_player_pos(a, pos[a->map.world]);
        reloard_minimap(a, map[a->map.world]);
        make_transition_between_maps(a);
        return;
    }
    handle_zones_two(a, map, txt);
}

bool player_going_back(all_t *a)
{
    static float time = 0;

    if (get_seconds(a->npc->go_back) > 0.01) {
        a->player->obj->pos.y += 1;
        sfSprite_setPosition(a->player->obj->s, a->player->obj->pos);
        change_player_rect(a, 2);
        sfClock_restart(a->npc->go_back);
        time += 0.01;
    }
    if (time >= 1) {
        time = 0;
        return (false);
    }
    return (true);
}

void handle_zone_changements(all_t *a)
{
    static bool backing = false;

    if (is_colliding(a, sfKeyUp) == 9 && a->npc[0].npc_arr[FORGERON].quest) {
        if (!backing)
            backing = !backing;
        forgeron_interact(a);
    }
    if (is_colliding(a, sfKeyUp) == 9 && a->map.world == FOPSPACE
    && a->npc[0].obj[OLDIDK].quest == false) {
        if (!backing)
            backing = !backing;
        questmaster_interact(a);
    }
    if (backing)
        backing = player_going_back(a);
    a->npc->ex = false;
    handle_zones(a);
}