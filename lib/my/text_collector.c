/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** text_collector.c
*/

#include "../../includes/csfml_garbage_collector.h"

void add_text_to_text_collector_t(void *text)
{
    text_collector_t *node = malloc(sizeof(text_collector_t));
    text_collector_t **head = get_text_collector();
    text_collector_t *temp = *head;

    node->next = NULL;
    node->text = text;
    if (*head == NULL) {
        *head = node;
        return;
    }
    for (; temp->next; temp = temp->next);
    temp->next = node;
}

void destroy_text_to_text_collector_t(void)
{
    text_collector_t **head = get_text_collector();
    text_collector_t *temp;
    text_collector_t *list = *head;

    if (list == NULL)
        return;
    for (; list; list = temp) {
        temp = list->next;
        sfText_destroy(list->text);
        free(list);
    }
}

sfText *create_text(void)
{
    sfText *text = sfText_create();

    add_text_to_text_collector_t(text);
    return (text);
}

text_collector_t **get_text_collector(void)
{
    static text_collector_t *text_collector = NULL;

    return (&text_collector);
}
