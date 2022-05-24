/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** movements
*/

#include "rpg.h"
#include "struct.h"

void move_five(all_t *a, int to_display)
{
    if (to_display == 11) {
        sfSprite_setOrigin(a->cin[0].obj[to_display].s,
        (sfVector2f){1000, 600});
        a->cin[0].obj[to_display].scale.x += 0.0001;
        a->cin[0].obj[to_display].scale.y += 0.0001;
    }
    if (to_display == 12) {
        sfSprite_rotate(a->cin[0].obj[to_display].s, 0.01);
        a->cin[0].obj[to_display].scale.x -= 0.0005;
        a->cin[0].obj[to_display].scale.y -= 0.0005;
        a->cin[0].obj[to_display].rect.top += 0.1;
    }
    if (to_display == 13) {
        sfSprite_rotate(a->cin[0].obj[to_display].s, 0.001);
        a->cin[0].obj[to_display].scale.x += 0.0005;
        a->cin[0].obj[to_display].scale.y += 0.0005;
    }
}

void move_four(all_t *a, int to_display)
{
    if (to_display == 7) {
        a->cin[0].obj[to_display].scale.x += 0.001;
        a->cin[0].obj[to_display].scale.y += 0.001;
        sfSprite_rotate(a->cin[0].obj[to_display].s, 0.01);
    }
    if (to_display == 8) {
        sfSprite_setPosition(a->cin[0].obj[to_display].s,
        (sfVector2f){1100, 600});
        sfSprite_setOrigin(a->cin[0].obj[to_display].s,
        (sfVector2f){1100, 600});
        sfSprite_rotate(a->cin[0].obj[to_display].s, -0.01);
        a->cin[0].obj[to_display].scale.x += 0.001;
        a->cin[0].obj[to_display].scale.y += 0.001;
    }
    if (to_display == 9) {
        sfSprite_rotate(a->cin[0].obj[to_display].s, 0.01);
        a->cin[0].obj[to_display].scale.x += 0.001;
        a->cin[0].obj[to_display].scale.y += 0.001;
    }
    move_five(a, to_display);
}

void move_three(all_t *a, int to_display)
{
    if (to_display == 3) {
        sfSprite_setOrigin(a->cin[0].obj[to_display].s,
        (sfVector2f){900, 550});
        a->cin[0].obj[to_display].scale.x += 0.001;
        a->cin[0].obj[to_display].scale.y += 0.001;
    }
    if (to_display == 4) {
        sfSprite_setOrigin(a->cin[0].obj[to_display].s,
        (sfVector2f){900, 550});
        a->cin[0].obj[to_display].scale.x -= 0.001;
        a->cin[0].obj[to_display].scale.y -= 0.001;
        sfSprite_setScale(a->cin[0].obj[to_display].s,
        a->cin[0].obj[to_display].scale);
    }
    if (to_display == 6) {
        a->cin[0].obj[to_display].scale.x += 0.001;
        a->cin[0].obj[to_display].scale.y += 0.001;
    }
    move_four(a, to_display);
}

void move_two(all_t *a, int to_display)
{
    if (to_display == 3) {
        sfSprite_setOrigin(a->cin[0].obj[to_display].s,
        (sfVector2f){900, 550});
        a->cin[0].obj[to_display].scale.x += 0.001;
        a->cin[0].obj[to_display].scale.y += 0.001;
    }
    if (to_display == 4) {
        sfSprite_setOrigin(a->cin[0].obj[to_display].s,
        (sfVector2f){900, 550});
        a->cin[0].obj[to_display].scale.x -= 0.00001;
        a->cin[0].obj[to_display].scale.y -= 0.00001;
        sfSprite_setScale(a->cin[0].obj[to_display].s,
        a->cin[0].obj[to_display].scale);
    }
    if (to_display == 6) {
        a->cin[0].obj[to_display].scale.x += 0.005;
        a->cin[0].obj[to_display].scale.y += 0.005;
    }
    move_three(a, to_display);
}

void move_one(all_t *a, int to_display)
{
    if (to_display == 0 && a->cin[0].obj[to_display].rect.top < 1100) {
        a->cin[0].obj[to_display].rect.top += 5;
    }
    if (to_display == 0 && a->cin[0].obj[to_display].rect.top >= 1100) {
        a->cin[0].obj[to_display].scale.x += 0.001;
        a->cin[0].obj[to_display].scale.y += 0.001;
    }
    if (to_display == 1) {
        sfSprite_setOrigin(a->cin[0].obj[to_display].s,
        (sfVector2f){960, 500});
        a->cin[0].obj[to_display].scale.x += 0.001;
        a->cin[0].obj[to_display].scale.y += 0.001;
    }
    if (to_display == 2) {
        sfSprite_setOrigin(a->cin[0].obj[to_display].s,
        (sfVector2f){960, 500});
        a->cin[0].obj[to_display].scale.x += 0.001;
        a->cin[0].obj[to_display].scale.y += 0.001;
    }
    move_two(a, to_display);
}