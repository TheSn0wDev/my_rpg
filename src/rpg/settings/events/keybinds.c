/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** handling of keybinds
*/

#include "struct.h"
#include "rpg.h"
#include "events.h"
#include "../settings.h"

bool is_sprite_hovered(menu_object_t sprite, sfVector2i mouse);

void create_command_txts_two(all_t *a, int n)
{
    int index = n + 1;
    sfColor color =  sfColor_fromRGBA(46, 64, 83, 255);
    text_object_t mr = {0, 0, {1000, 450}, 19, color, 0};
    text_object_t i = {0, 0, {1000, 550}, 19, color, 0};
    text_object_t oi = {0, 0, {1000, 650}, 19, color, 0};

    init_text_object(&mr, "assets/fonts/diablo_h.ttf", "Move Right");
    a->settings[1].keytxt[index + 3] = mr;
    init_text_object(&i, "assets/fonts/diablo_h.ttf", "Interact");
    a->settings[1].keytxt[index + 4] = i;
    init_text_object(&oi, "assets/fonts/diablo_h.ttf", "Open inventory");
    a->settings[1].keytxt[index + 5] = oi;
    init_text_object(&oi, "assets/fonts/diablo_h.ttf", "Special attack one");
    a->settings[1].keytxt[index + 6] = oi;
    init_text_object(&oi, "assets/fonts/diablo_h.ttf", "Special attack two");
    a->settings[1].keytxt[index + 7] = oi;
    init_text_object(&oi, "assets/fonts/diablo_h.ttf", "Special attack three");
    a->settings[1].keytxt[index + 8] = oi;
}

void create_command_txts(all_t *a, int n)
{
    int index = n + 1;
    int j = 0;
    sfColor color =  sfColor_fromRGBA(46, 64, 83, 255);
    text_object_t mf = {0, 0, {1000, 250}, 19, color, 0};
    text_object_t ml = {0, 0, {1000, 305}, 19, color, 0};
    text_object_t mb = {0, 0, {1000, 350}, 19, color, 0};

    init_text_object(&mf, "assets/fonts/diablo_h.ttf", "Move Forward");
    a->settings[1].keytxt[index] = mf;
    init_text_object(&ml, "assets/fonts/diablo_h.ttf", "Move left");
    a->settings[1].keytxt[index + 1] = ml;
    init_text_object(&mb, "assets/fonts/diablo_h.ttf", "Move Backward");
    a->settings[1].keytxt[index + 2] = mb;
    create_command_txts_two(a, n);
    for (int i = 0; i <= n; i++) {
        sfText_setPosition(a->settings[1].keytxt[index + j].text,
        (sfVector2f){a->settings[1].keytxt[i].pos.x - 550,
        a->settings[1].keytxt[i].pos.y});
        j += 1;
    }
}

void create_keybinds_sprites(all_t *a, int n,
menu_object_t keybinds,  text_object_t keybinds_txt)
{
    char *c = my_malloc(sizeof(char) * 2);

    for (int index = 0; index <= n; index++) {
        init_menu_object(&keybinds, "assets/settings/keybindings.png");
        a->settings[1].keygui[index] = keybinds;
        a->settings[1].keygui[index].pos.y += ((109 * 0.5) * index);
        sfSprite_setPosition(a->settings[1].keygui[index].s,
        a->settings[1].keygui[index].pos);
        c[0] = a->key_arr[index];
        c[1] = '\0';
        init_text_object(&keybinds_txt, "assets/fonts/diablo_h.ttf", c);
        a->settings[1].keytxt[index] = keybinds_txt;
        a->settings[1].keytxt[index].pos.y += ((109 * 0.5) * index) + 6;
        sfText_setPosition(a->settings[1].keytxt[index].text,
        a->settings[1].keytxt[index].pos);
        a->settings[1].keytxt[index].key = index;
    }
    create_command_txts(a, n);
}

int keybindings_buttons(all_t *a,
menu_object_t sprite, sfEvent event, sfVector2i mouse)
{
    static bool pressed = false;

    if (is_sprite_hovered(sprite, mouse))
        sfSprite_setTextureRect(sprite.s,
        (sfIntRect){0, 84, 465, 84});
    else {
        sfSprite_setTextureRect(sprite.s,
        (sfIntRect){0, 0, 465, 84});
        pressed = false;
    }
    if (pressed == true || (is_sprite_hovered(sprite, mouse) &&
    sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setTextureRect(sprite.s, (sfIntRect){0, 84 * 2, 465, 84});
        pressed = true;
        play_sfx(a, a->sfx.click);
    }
    if (is_sprite_hovered(sprite, mouse))
        if (event.type == sfEvtMouseButtonReleased)
            return (1);
    return (-1);
}