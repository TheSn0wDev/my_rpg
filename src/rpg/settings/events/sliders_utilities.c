/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** sliders_utilities
*/

#include "rpg.h"
#include "events.h"
#include "struct.h"
#include "../settings.h"

void create_sliders_percent(all_t *a)
{
    sfColor color =  sfColor_fromRGBA(220, 118, 51, 255);
    text_object_t sfxpercent = {0, 0, {1061, 404}, 19, color, 0};
    text_object_t musicpercent = {0, 0, {1061, 530}, 19, color, 0};

    a->settings[1].sliderstxt = my_malloc(sizeof(text_object_t) * (3));
    init_text_object(&sfxpercent, "assets/fonts/diablo_h.ttf", "");
    init_text_object(&musicpercent, "assets/fonts/diablo_h.ttf", "");
    a->settings[1].sliderstxt[1] = sfxpercent;
    a->settings[1].sliderstxt[2] = musicpercent;
    sfText_setString(a->settings[1].sliderstxt[1].text, my_itoa(calc_sfx(a)));
    sfText_setString(a->settings[1].sliderstxt[2].text,
    my_itoa(calc_volume(a)));
}

int calc_volume(all_t *a)
{
    sfVector2f sprite_pos =
    sfSprite_getPosition(a->settings[0].interface[14].s);
    int value_two = 1048 - 770;
    int value_one = 1048 - sprite_pos.x - value_two;
    int ret = 0;

    if (a->settings->enable_music == false)
        return (0);
    if (value_one < 0)
        value_one = value_one * -1;
    ret = value_one * 100 / value_two;
    if (ret >= 100)
        ret = 100;
    if (ret < 1)
        ret = 0;
    sfText_setString(a->settings[1].sliderstxt[1].text, my_itoa(ret));
    set_music_volumes(a, ret);
    return (ret);
}

int calc_sfx(all_t *a)
{
    sfVector2f sprite_pos =
    sfSprite_getPosition(a->settings[0].interface[13].s);
    int value_two = 1048 - 770;
    int value_one = 1048 - sprite_pos.x - value_two;
    int ret = 0;

    if (a->settings->enable_sfx == false)
        return (0);
    if (value_one < 0)
        value_one = value_one * -1;
    ret = value_one * 100 / value_two;
    if (ret >= 100)
        ret = 100;
    if (ret < 1)
        ret = 0;
    sfText_setString(a->settings[1].sliderstxt[2].text, my_itoa(ret));
    set_sfx_volumes(a, ret);
    return (ret);
}