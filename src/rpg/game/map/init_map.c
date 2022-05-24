/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init map
*/

#include "rpg.h"
#include "struct.h"

map_obj_t *create_map(char *filepath, sfIntRect rect,
sfVector2f pos, sfVector2f scale)
{
    map_obj_t *object = my_malloc(sizeof(map_obj_t));

    object->pos = pos;
    object->rect = rect;
    object->scale = scale;
    object->t = create_texture(filepath, NULL);
    object->s = create_sprite();
    sfSprite_setTexture(object->s, object->t, sfTrue);
    sfSprite_setTextureRect(object->s, object->rect);
    sfSprite_setPosition(object->s, object->pos);
    sfSprite_setScale(object->s, object->scale);
    return (object);
}

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buff;
    int bytes_nb = get_file_bytes_nb(filepath);

    if (fd < 0)
        return (NULL);
    if (bytes_nb == 0)
        return (NULL);
    buff = my_malloc(bytes_nb + 1);
    if (buff == NULL)
        return (NULL);
    buff[bytes_nb] = 0;
    if (read(fd, buff, bytes_nb) < 0)
        return (NULL);
    return (buff);
}

char **get_txt_map(char *filepath)
{
    char **arr = my_str_to_word_array(read_file(filepath), "\n");
    return (arr);
}