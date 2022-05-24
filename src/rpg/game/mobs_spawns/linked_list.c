/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** linked_list
*/

#include "struct.h"
#include "rpg.h"
#include <stdlib.h>

void int_list_push_front(mobs_lists_t **list, mobs_object_t mobs)
{
    mobs_lists_t *node = my_malloc(sizeof(*node));

    node->mobs = mobs;
    node->next = *list;
    *list = node;
}

void pop_front(mobs_lists_t **list)
{
    *list = (*list)->next;
}

void int_list_push_back(mobs_lists_t **list, mobs_object_t mobs)
{
    mobs_lists_t *node = *list;

    if (node == NULL)
        int_list_push_front(list, mobs);
    else
        int_list_push_back(&node->next, mobs);
}

void int_list_destroy(mobs_lists_t **list)
{
    mobs_lists_t *node = *list;

    while (node != NULL) {
        node = (*list)->next;
        (*list) = node;
    }
    *list = NULL;
}

void int_list_pop_back(mobs_lists_t **list)
{
    mobs_lists_t *new = *list;
    mobs_object_t temp;
    (void) temp;

    if (list == NULL)
        return;
    if ((*list)->next == NULL) {
        temp = new->mobs;
        *list = NULL;
    } else {
        while (new->next->next != NULL)
            new = new->next;
        temp = new->next->mobs;
        new->next = NULL;
    }
}