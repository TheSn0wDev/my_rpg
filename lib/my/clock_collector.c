/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** clock_collector.c
*/

#include "../../includes/csfml_garbage_collector.h"

void add_clock_to_clock_collector_t(void *clock)
{
    clock_collector_t *node = malloc(sizeof(clock_collector_t));
    clock_collector_t **head = get_clock_collector();
    clock_collector_t *temp = *head;

    node->next = NULL;
    node->clock = clock;
    if (*head == NULL) {
        *head = node;
        return;
    }
    for (; temp->next; temp = temp->next);
    temp->next = node;
}

void destroy_clock_to_clock_collector_t(void)
{
    clock_collector_t **head = get_clock_collector();
    clock_collector_t *temp;
    clock_collector_t *list = *head;

    if (list == NULL)
        return;
    for (; list; list = temp) {
        temp = list->next;
        sfClock_destroy(list->clock);
        free(list);
    }
}

sfClock *create_clock(void)
{
    sfClock *clock = sfClock_create();

    add_clock_to_clock_collector_t(clock);
    return (clock);
}

clock_collector_t **get_clock_collector(void)
{
    static clock_collector_t *clock_collector = NULL;

    return (&clock_collector);
}
