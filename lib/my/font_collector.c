/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** font_collector.c
*/

#include "../../includes/csfml_garbage_collector.h"

void add_font_to_font_collector_t(void *font)
{
    font_collector_t *node = malloc(sizeof(font_collector_t));
    font_collector_t **head = get_font_collector();
    font_collector_t *temp = *head;

    node->next = NULL;
    node->font = font;
    if (*head == NULL) {
        *head = node;
        return;
    }
    for (; temp->next; temp = temp->next);
    temp->next = node;
}

void destroy_font_to_font_collector_t(void)
{
    font_collector_t **head = get_font_collector();
    font_collector_t *temp;
    font_collector_t *list = *head;

    if (list == NULL)
        return;
    for (; list; list = temp) {
        temp = list->next;
        sfFont_destroy(list->font);
        free(list);
    }
}

sfFont *create_font(const char *file)
{
    sfFont *font = sfFont_createFromFile(file);

    add_font_to_font_collector_t(font);
    return (font);
}

font_collector_t **get_font_collector(void)
{
    static font_collector_t *font_collector = NULL;

    return (&font_collector);
}
