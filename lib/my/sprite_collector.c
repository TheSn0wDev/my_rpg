/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** sprite_collector.c
*/

#include "../../includes/csfml_garbage_collector.h"

void add_sprite_to_sprite_collector_t(void *sprite)
{
    sprite_collector_t *node = malloc(sizeof(sprite_collector_t));
    sprite_collector_t **head = get_sprite_collector();
    sprite_collector_t *temp = *head;

    node->next = NULL;
    node->sprite = sprite;
    if (*head == NULL) {
        *head = node;
        return;
    }
    for (; temp->next; temp = temp->next);
    temp->next = node;
}

void destroy_sprite_to_sprite_collector_t(void)
{
    sprite_collector_t **head = get_sprite_collector();
    sprite_collector_t *temp;
    sprite_collector_t *list = *head;

    if (list == NULL)
        return;
    for (; list; list = temp) {
        temp = list->next;
        sfSprite_destroy(list->sprite);
        free(list);
    }
}

sfSprite *create_sprite(void)
{
    sfSprite *sprite = sfSprite_create();

    add_sprite_to_sprite_collector_t(sprite);
    return (sprite);
}

sprite_collector_t **get_sprite_collector(void)
{
    static sprite_collector_t *sprite_collector = NULL;

    return (&sprite_collector);
}
