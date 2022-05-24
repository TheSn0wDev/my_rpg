/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** menu_object
*/

#include "rpg.h"
#include "struct.h"

void init_text_object(text_object_t *t, char *f, char *string)
{
    t->font = create_font(f);
    t->text = create_text();
    sfText_setFont(t->text, t->font);
    sfText_setColor(t->text, t->color);
    sfText_setPosition(t->text, t->pos);
    sfText_setCharacterSize(t->text, t->size);
    sfText_setString(t->text, string);
}

sfText *create_texts(const char *f, float size, sfVector2f pos, sfColor color)
{
    sfFont *fonts = create_font(f);
    sfText *txt = create_text();

    sfText_setFont(txt, fonts);
    sfText_setColor(txt, color);
    sfText_setPosition(txt, pos);
    sfText_setCharacterSize(txt, size);
    return (txt);
}

void init_menu_object(menu_object_t *object, char *filepath)
{
    sfVector2u width_height = {0, 0};

    object->clock = create_clock();
    object->texture = create_texture(filepath, NULL);
    object->s = create_sprite();
    sfSprite_setTexture(object->s, object->texture, sfTrue);
    object->width = width_height.x;
    object->height = width_height.y;
    object->rect.left = (object->rect.left == 0) ? 0 : object->rect.left;
    object->rect.top = (object->rect.top == 0) ? 0 : object->rect.top;
    sfSprite_setTextureRect(object->s, object->rect);
    sfSprite_setScale(object->s, object->scale);
    sfSprite_setPosition(object->s, object->pos);
}