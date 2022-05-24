/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** dialogue.c
*/

#include "rpg.h"
#include "struct.h"

void init_dialogue(all_t *a)
{
    a->text.t = create_texture("assets/dialogue/box.png", NULL);
    a->text.s = create_sprite();
    sfSprite_setTexture(a->text.s, a->text.t, sfTrue);
    sfSprite_setPosition(a->text.s, (sfVector2f){90, 800});
    a->in_dialogue = false;
    a->text.index = 0;
    a->text.nb_visible = 0;
}

void start_dialogue(all_t *a, char *txt)
{
    if (a->in_dialogue == true)
        return;
    a->in_dialogue = true;
    a->text.index = 0;
    a->text.nb_visible = 0;
    a->text.clock = create_clock();
    a->text.content = read_arr_file(txt);
    a->text.font = create_font("assets/font.TTF");
    a->text.text = create_text();
    sfText_setFont(a->text.text, a->text.font);
    sfText_setColor(a->text.text, sfBlack);
    sfText_setCharacterSize(a->text.text, 24);
    a->text.pos = (sfVector2f){150, 850};
    sfText_setPosition(a->text.text, a->text.pos);
}

void update_dialogue(all_t *a)
{
    if (a->text.nb_visible == my_strlen(a->text.content[a->text.index]))
        return;
    if (get_seconds(a->text.clock) > 0.01) {
        a->text.nb_visible += 1;
        sfClock_restart(a->text.clock);
    }
}

int my_strlen_array(char **array)
{
    int len = 0;

    for (; array[len]; len++);
    return (len);
}

void check_interaction(all_t *a)
{
    char **content = a->text.content;
    char *text = NULL;

    if (a->in_dialogue == false || content == NULL)
        return;
    play_sfx(a, a->sfx.dialogue);
    text = a->text.content[a->text.index];
    if (a->text.nb_visible == my_strlen(text)) {
        a->text.index += 1;
        a->text.nb_visible = 0;
        if (a->text.content[a->text.index] == NULL)
            a->in_dialogue = false;
    } else {
        a->text.nb_visible = my_strlen(text);
    }
}