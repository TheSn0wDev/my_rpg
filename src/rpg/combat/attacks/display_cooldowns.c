/*
** EPITECH PROJECT, 2020
** My_RPG
** File description:
** display_cooldowns.c
*/

#include <rpg.h>
#include "../combat.h"

void set_attack_key(all_t *a, attack_stats_t *attack, int i)
{
    sfVector2f text_pos = sfText_getPosition(attack->icon.text);
    char key[2];

    key[0] = a->key_arr[6 + i] - 32;
    key[1] = 0;
    sfText_setString(attack->icon.text, key);
    text_pos.x += 15;
    sfText_setPosition(attack->icon.text, text_pos);
}

void set_attack_cooldown(attack_stats_t *attack, float cool)
{
    char *str = float_to_str(cool, 1);

    sfText_setString(attack->icon.text, str);
}

void update_cooldowns(all_t *a, enemy_t *enemy)
{
    sfVector2f icon_pos = {1620, 150};
    sfVector2f text_pos = {1632, 180};
    float cool = 0;

    for (int i = enemy->nb_attacks - 1; i >= 0; i--) {
        sfSprite_setPosition(enemy->attacks[i].icon.s, icon_pos);
        sfText_setPosition(enemy->attacks[i].icon.text, text_pos);
        icon_pos.x -= 100;
        text_pos.x -= 100;
        cool = enemy->attacks[i].cool - get_seconds(enemy->attacks[i].clock);
        if (round_float(cool, 1) <= 0)
            set_attack_key(a, &enemy->attacks[i], i);
        else
            set_attack_cooldown(&enemy->attacks[i], cool);
    }
}

void display_cooldowns(sfRenderWindow *window, enemy_t *enemy)
{
    for (int i = enemy->nb_attacks - 1; i >= 0; i--) {
        sfRenderWindow_drawSprite(window, enemy->attacks[i].icon.s, NULL);
        sfRenderWindow_drawText(window, enemy->attacks[i].icon.text, NULL);
    }
}