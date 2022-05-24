/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init player obj
*/

#include "rpg.h"
#include "struct.h"

player_obj_t *init_player(char *filepath, sfIntRect rect,
sfVector2f pos, sfVector2f scale)
{
    player_obj_t *object = my_malloc(sizeof(player_obj_t));

    object->clock = create_clock();
    object->pos = pos;
    object->rect = rect;
    object->scale = scale;
    object->velocity = (sfVector2f){0, 0};
    object->t = create_texture(filepath, NULL);
    object->s = create_sprite();
    sfSprite_setTexture(object->s, object->t, sfTrue);
    sfSprite_setTextureRect(object->s, object->rect);
    sfSprite_setPosition(object->s, object->pos);
    sfSprite_setScale(object->s, object->scale);
    sfSprite_setOrigin(object->s, (sfVector2f){80, 67});
    return (object);
}

void init_game_player(player_obj_t *object, sfIntRect rect, sfVector2f scale)
{
    object->rect = rect;
    object->scale = scale;
    object->velocity = (sfVector2f){0, 0};
    sfSprite_setTextureRect(object->s, object->rect);
    sfSprite_setScale(object->s, object->scale);
    sfSprite_setOrigin(object->s, (sfVector2f){80, 67});
}