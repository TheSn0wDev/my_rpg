/*
** EPITECH PROJECT, 2020
** My_RPG
** File description:
** manipulate_attacks.c
*/

#include <rpg.h>

void destroy_attacks(attack_t **attack)
{
    attack_t *temp;
    attack_t *my_list = *attack;

    if (*attack == NULL)
        return;
    for (; my_list->next; my_list = temp)
        temp = my_list->next;
}

void destroy_attack(attack_t **attack, int index)
{
    attack_t *temp = *attack;
    attack_t *next = NULL;

    if (*attack == NULL)
        return;
    if (index == 0) {
        (*attack) = (*attack)->next;
        return;
    }
    for (int i = 0; i < index - 1 && temp; temp = temp->next, i++);
    next = temp->next->next;
    temp->next = next;
}

void push_back_attack(attack_t **attack, attack_stats_t *stats, sfVector2f pos)
{
    attack_t *new_attack = my_malloc(sizeof(attack_t));
    attack_t *temp = *attack;

    new_attack->stats = *stats;
    new_attack->pos = pos;
    new_attack->max_pos.x = pos.x;
    new_attack->max_pos.y = pos.y;
    new_attack->next = NULL;
    if ((*attack) == NULL)
        (*attack) = new_attack;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_attack;
}

void push_front_attack(attack_t **attack, attack_stats_t *stats, enemy_t *play)
{
    attack_t *new_attack = my_malloc(sizeof(attack_t));
    sfVector2f pos = play->p->pos;
    int dir = 1;

    new_attack->stats = *stats;
    if (play->side == LEFT)
        dir = -1;
    new_attack->stats.speed *= dir;
    pos.x += stats->offset.x;
    pos.y += stats->offset.y;
    new_attack->pos = pos;
    new_attack->max_pos.x = pos.x + (new_attack->stats.range * dir);
    new_attack->max_pos.y = pos.y;
    new_attack->state = IDLE;
    new_attack->clock = create_clock();
    new_attack->s = create_sprite();
    sfSprite_setTexture(new_attack->s, stats->t, sfFalse);
    sfSprite_setTextureRect(new_attack->s, new_attack->stats.rect);
    new_attack->next = (*attack);
    (*attack) = new_attack;
}