/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** circle_collector.c
*/

#include "../../includes/csfml_garbage_collector.h"

void add_circle_to_circle_collector_t(void *circle)
{
    circle_collector_t *node = malloc(sizeof(circle_collector_t));
    circle_collector_t **head = get_circle_collector();
    circle_collector_t *temp = *head;

    node->next = NULL;
    node->circle = circle;
    if (*head == NULL) {
        *head = node;
        return;
    }
    for (; temp->next; temp = temp->next);
    temp->next = node;
}

void destroy_circle_to_circle_collector_t(void)
{
    circle_collector_t **head = get_circle_collector();
    circle_collector_t *temp;
    circle_collector_t *list = *head;

    if (list == NULL)
        return;
    for (; list; list = temp) {
        temp = list->next;
        sfCircleShape_destroy(list->circle);
        free(list);
    }
}

sfCircleShape *create_circle(void)
{
    sfCircleShape *circle = sfCircleShape_create();

    add_circle_to_circle_collector_t(circle);
    return (circle);
}

circle_collector_t **get_circle_collector(void)
{
    static circle_collector_t *circle_collector = NULL;

    return (&circle_collector);
}