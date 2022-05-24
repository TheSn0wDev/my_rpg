/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** dialogue.c
*/

#include "rpg.h"
#include "struct.h"

void print_text(all_t *a, int line, int min_i, int max_i)
{
    char *text = a->text.content[a->text.index];
    char temp = text[max_i];
    sfVector2f pos = a->text.pos;

    pos.y += line * 45;
    if (min_i > a->text.nb_visible)
        return;
    if (max_i > a->text.nb_visible) {
        temp = text[a->text.nb_visible];
        max_i = a->text.nb_visible;
    }
    text[max_i] = 0;
    sfText_setPosition(a->text.text, pos);
    sfText_setString(a->text.text, &text[min_i]);
    sfRenderWindow_drawText(a->window, a->text.text, NULL);
    text[max_i] = temp;
}

void adjust_text(all_t *a, char *text)
{
    char **words = my_str_to_word_array(text, " ");
    int nb_characters = 0;
    int min_i = 0;
    int line = 0;

    for (int i = 0; words[i]; i++) {
        if (i != 0)
            nb_characters += 1;
        if ((nb_characters + my_strlen(words[i])) * 18 > 1800) {
            print_text(a, line, min_i, nb_characters + min_i);
            min_i = nb_characters + min_i;
            line += 1;
            nb_characters = 0;
        }
        nb_characters += my_strlen(words[i]);
    }
    print_text(a, line, min_i, nb_characters + min_i);
}

void draw_dialogue(all_t *a)
{
    char *text = a->text.content[a->text.index];

    sfRenderWindow_drawSprite(a->window, a->text.s, NULL);
    if (my_strlen(text) * 18 > 1800)
        adjust_text(a, text);
    else
        print_text(a, 0, 0, a->text.nb_visible);
}