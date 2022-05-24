/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** garbage_collector.c
*/

#include "../../includes/garbage_collector.h"
#include "../../includes/csfml_garbage_collector.h"

void __attribute__((destructor))call_after_main(void)
{
    destroy_texture_to_texture_collector_t();
    destroy_sprite_to_sprite_collector_t();
    destroy_clock_to_clock_collector_t();
    destroy_text_to_text_collector_t();
    destroy_music_to_music_collector_t();
    destroy_font_to_font_collector_t();
    destroy_rectangle_to_rectangle_collector_t();
    destroy_ptr_to_garbage_collector_t();
}

void add_ptr_to_garbage_collector_t(void *ptr)
{
    garbage_collector_t *node = malloc(sizeof(garbage_collector_t));
    garbage_collector_t **head = get_garbage_collector();
    garbage_collector_t *temp = *head;

    node->next = NULL;
    node->ptr = ptr;
    if (*head == NULL) {
        *head = node;
        return;
    }
    for (; temp->next; temp = temp->next);
    temp->next = node;
}

void destroy_ptr_to_garbage_collector_t(void)
{
    garbage_collector_t **head = get_garbage_collector();
    garbage_collector_t *temp;
    garbage_collector_t *list = *head;

    if (list == NULL)
        return;
    for (; list; list = temp) {
        temp = list->next;
        free(list->ptr);
        free(list);
    }
}

void *my_malloc(size_t size)
{
    void *ptr = malloc(size);

    add_ptr_to_garbage_collector_t(ptr);
    return (ptr);
}

garbage_collector_t **get_garbage_collector(void)
{
    static garbage_collector_t *garbage_collector = NULL;

    return (&garbage_collector);
}
