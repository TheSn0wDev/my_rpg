/*
** EPITECH PROJECT, 2020
** My_RPG
** File description:
** attacks.c
*/

#include <rpg.h>
#include "../combat.h"

void init_icon_variables(attack_stats_t *attack, char **stats)
{
    attack->clock = create_clock();
    if (stats[12]) {
        attack->icon.t = create_texture(stats[12], NULL);
        attack->icon.s = create_sprite();
        attack->icon.font = create_font("assets/combat/font.TTF");
        attack->icon.text = create_text();
        sfText_setCharacterSize(attack->icon.text, 32);
        sfText_setFillColor(attack->icon.text, sfBlack);
        sfText_setFont(attack->icon.text, attack->icon.font);
        sfSprite_setTexture(attack->icon.s, attack->icon.t, sfTrue);
    } else {
        attack->icon.t = NULL;
        attack->icon.s = NULL;
        attack->icon.font = NULL;
        attack->icon.text = NULL;
    }
}

void create_attack(attack_stats_t *attack, char *info, stat_t *my_stats)
{
    char **stats = my_str_to_word_array(info, " ");
    int rect_x = my_getnbr(stats[7]);
    int rect_y = my_getnbr(stats[8]);

    attack->attack = my_getnbr(stats[1]) + my_stats->attack;
    attack->defense = my_getnbr(stats[2]) + my_stats->defense;
    attack->range = my_getnbr(stats[3]);
    attack->cool = my_getnbr(stats[4]);
    attack->speed = my_getnbr(stats[5]) + my_stats->speed / 5;
    attack->offset.x = my_getnbr(stats[9]);
    attack->offset.y = my_getnbr(stats[10]);
    attack->nb_anim = my_getnbr(stats[11]);
    attack->rect = (sfIntRect){0, 0, rect_x, rect_y};
    init_icon_variables(attack, stats);
    if (my_strcmp(stats[6], "NULL") == 0)
        attack->t = sfTexture_create(1, 1);
    else
        attack->t = create_texture(stats[6], NULL);
}

int shift_rect(attack_t **attacks, attack_t *attack, int i)
{
    attack_stats_t *stats = &attack->stats;

    if (get_seconds(attack->clock) < 0.1)
        return (0);
    if (attack->state == IDLE) {
        if (stats->rect.left >= stats->nb_anim * stats->rect.width)
            stats->rect.left = 0;
        else
            stats->rect.left += stats->rect.width;
    }
    if (attack->state == DESTROY) {
        if (stats->rect.left >= stats->nb_anim * stats->rect.width) {
            destroy_attack(attacks, i);
            return (1);
        } else
            stats->rect.left += stats->rect.width;
    }
    sfSprite_setTextureRect(attack->s, stats->rect);
    sfClock_restart(attack->clock);
    return (0);
}

void update_attack(all_t *a, enemy_t *enemy, attack_t *temp)
{
    int damage = temp->stats.attack - enemy->p->stat.defense;

    if (damage < 0)
        damage = 0;
    if (hit_enemy(enemy, temp)) {
        play_sfx(a, a->sfx.hit);
        if (enemy->p->stat.hp <= damage)
            enemy->p->stat.hp = 0;
        else
            enemy->p->stat.hp -= damage;
        temp->state = DESTROY;
        temp->stats.rect.top += temp->stats.rect.height;
        return;
    }
    if (fabs(temp->pos.x - temp->max_pos.x) <= abs(temp->stats.speed)) {
        temp->state = DESTROY;
        temp->stats.rect.top += temp->stats.rect.height;
        return;
    }
    temp->pos.x += temp->stats.speed;
}

void update_attacks(all_t *a, enemy_t *enemy, attack_t **attacks)
{
    attack_t *temp = (*attacks);

    for (int i = 0; temp; temp = temp->next, i++) {
        sfSprite_setPosition(temp->s, temp->pos);
        if (shift_rect(attacks, temp, i))
            return (update_attacks(a, enemy, attacks));
        if (temp->state != DESTROY)
            update_attack(a, enemy, temp);
    }
}