/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** music_collector.c
*/

#include "../../includes/csfml_garbage_collector.h"

void add_music_to_music_collector_t(void *music)
{
    music_collector_t *node = malloc(sizeof(music_collector_t));
    music_collector_t **head = get_music_collector();
    music_collector_t *temp = *head;

    node->next = NULL;
    node->music = music;
    if (*head == NULL) {
        *head = node;
        return;
    }
    for (; temp->next; temp = temp->next);
    temp->next = node;
}

void destroy_music_to_music_collector_t(void)
{
    music_collector_t **head = get_music_collector();
    music_collector_t *temp;
    music_collector_t *list = *head;

    if (list == NULL)
        return;
    for (; list; list = temp) {
        temp = list->next;
        sfMusic_stop(list->music);
        sfMusic_destroy(list->music);
        free(list);
    }
}

sfMusic *create_music(const char *file)
{
    sfMusic *music = sfMusic_createFromFile(file);

    add_music_to_music_collector_t(music);
    return (music);
}

music_collector_t **get_music_collector(void)
{
    static music_collector_t *music_collector = NULL;

    return (&music_collector);
}
