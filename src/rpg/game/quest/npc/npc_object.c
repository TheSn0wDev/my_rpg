/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** npc_object
*/

#include "rpg.h"
#include "struct.h"

void init_npc_object(npc_obj_t *object, char *filepath)
{
    sfVector2u width_height = {0, 0};

    object->clock = create_clock();
    object->texture = create_texture(filepath, NULL);
    object->s = create_sprite();
    sfSprite_setTexture(object->s, object->texture, sfTrue);
    object->width = width_height.x;
    object->height = width_height.y;
    object->rect.left = (object->rect.left == 0) ? 0 : object->rect.left;
    object->rect.top = (object->rect.top == 0) ? 0 : object->rect.top;
    sfSprite_setTextureRect(object->s, object->rect);
    sfSprite_setScale(object->s, object->scale);
    sfSprite_setPosition(object->s, object->pos);
}

void create_npc(sfVector2f pos, all_t *a, npc_obj_t *character)
{
    int w = get_maze_width(a->map.txtmap);
    int h = get_maze_height(a->map.txtmap);

    sfVector2f mapp = (sfVector2f)
    {pos.x * (a->map.map_dim.x / w),
    pos.y * (a->map.map_dim.y / h)};
    character->pos = mapp;
    sfSprite_setPosition(character->s, pos);
    a->npc[0].obj[a->npc->index] = *character;
    a->npc[0].npc_nb++;
}

void add_npc(all_t *a, npc_obj_t *npc, char *name, int i)
{
    init_npc_object(npc, name);
    a->npc[0].npc_arr[i] = *npc;
}

void create_my_npc_arr_next(all_t *a)
{
    npc_obj_t oldidk = {0, 0, {1.8, 1.8}, {1
    , (1)}, 0, 0, {10, 5, 43, 55}, 0, true, TO_DO
    , OLDIDK};
    npc_obj_t skeleton = {0, 0, {3, 3}, {1
    , (1)}, 0, 0, {15, 66, 30, 35}, 0, false, TO_DO
    , SKELETON};

    add_npc(a, &oldidk, "assets/npc/oldidk.png", 3);
    add_npc(a, &skeleton, "assets/npc/skeleton.png", 4);
}

npc_obj_t *create_my_npc_arr(all_t *a)
{
    npc_obj_t questmaster = {0, 0, {0.5, 0.5}, {1
    , (1)}, 0, 0, {0, 0, 127, 182}, 0, true, TO_DO
    , QUESTMASTER};
    npc_obj_t spawnnpc = {0, 0, {0.18, 0.18}, {1
    , (1)}, 0, 0, {0, 0, 528, 528}, 0, true, TO_DO
    , SPAWNNPC};
    npc_obj_t forgeron = {0, 0, {0.18, 0.18}, {1
    , (1)}, 0, 0, {0, 0, 512, 512}, 0, true, TO_DO
    , FORGERON};

    a->npc[0].npc_arr = my_malloc(sizeof(npc_obj_t) * 5);
    add_npc(a, &questmaster, "assets/npc/rouxcool.png", 0);
    add_npc(a, &spawnnpc, "assets/npc/spawnnpc.png", 1);
    add_npc(a, &forgeron, "assets/npc/forgeron.png", 2);
    create_my_npc_arr_next(a);
    return (a->npc[0].npc_arr);
}