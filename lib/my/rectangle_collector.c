/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** rectangle_collector.c
*/

#include "../../includes/csfml_garbage_collector.h"

void add_rectangle_to_rectangle_collector_t(void *rectangle)
{
    rectangle_collector_t *node = malloc(sizeof(rectangle_collector_t));
    rectangle_collector_t **head = get_rectangle_collector();
    rectangle_collector_t *temp = *head;

    node->next = NULL;
    node->rectangle = rectangle;
    if (*head == NULL) {
        *head = node;
        return;
    }
    for (; temp->next; temp = temp->next);
    temp->next = node;
}

void destroy_rectangle_to_rectangle_collector_t(void)
{
    rectangle_collector_t **head = get_rectangle_collector();
    rectangle_collector_t *temp;
    rectangle_collector_t *list = *head;

    if (list == NULL)
        return;
    for (; list; list = temp) {
        temp = list->next;
        sfRectangleShape_destroy(list->rectangle);
        free(list);
    }
}

sfRectangleShape *create_rectangle(void)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    add_rectangle_to_rectangle_collector_t(rectangle);
    return (rectangle);
}

rectangle_collector_t **get_rectangle_collector(void)
{
    static rectangle_collector_t *rectangle_collector = NULL;

    return (&rectangle_collector);
}