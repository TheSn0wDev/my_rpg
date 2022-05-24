/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** texture_collector.c
*/

#include "../../includes/csfml_garbage_collector.h"

void add_texture_to_texture_collector_t(void *texture)
{
    texture_collector_t *node = malloc(sizeof(texture_collector_t));
    texture_collector_t **head = get_texture_collector();
    texture_collector_t *temp = *head;

    node->next = NULL;
    node->texture = texture;
    if (*head == NULL) {
        *head = node;
        return;
    }
    for (; temp->next; temp = temp->next);
    temp->next = node;
}

void destroy_texture_to_texture_collector_t(void)
{
    texture_collector_t **head = get_texture_collector();
    texture_collector_t *temp;
    texture_collector_t *list = *head;

    if (list == NULL)
        return;
    for (; list; list = temp) {
        temp = list->next;
        sfTexture_destroy(list->texture);
        free(list);
    }
}

sfTexture *create_texture(const char *file, const sfIntRect *area)
{
    sfTexture *texture = sfTexture_createFromFile(file, area);

    add_texture_to_texture_collector_t(texture);
    return (texture);
}

texture_collector_t **get_texture_collector(void)
{
    static texture_collector_t *texture_collector = NULL;

    return (&texture_collector);
}
