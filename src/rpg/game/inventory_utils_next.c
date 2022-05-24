/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game
*/

#include "rpg.h"
#include "struct.h"

char **read_file_inv(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buff;
    char **array = NULL;
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
    array = my_str_to_word_array(buff, "\n");
    return (array);
}

void add_item_next(add_item_t *add, int n, int item, all_t *a)
{
    if (add->inventory[add->j] == NULL)
        return;
    write(add->fd, my_strcat(a->main_menu->nickname, ":"),
    my_strlen(a->main_menu->nickname) + 1);
    for (int i = 1; add->data[i]; i++) {
        if (n + 1 == i)
            write(add->fd, my_itoa(item), 1);
        else
            write(add->fd, add->data[i], my_strlen(add->data[i]));
        if (i / 2 != a->inventory.items_size)
            write(add->fd, ":", 1);
    }
    a->inventory.items = load_items(a);
}

void init_add(add_item_t *add, all_t *a)
{
    add->fd = open("data/players/inventory.txt", O_RDWR);
    add->j = 0;
    add->inventory = read_file_inv("data/players/inventory.txt");
    add->data = NULL;
    add->copy = my_malloc(sizeof(char) * (my_strlen(a->main_menu->nickname)
    + 21));
}

void change_item(add_item_t *add, all_t *a)
{
    for (int i = 0; add->inventory[i]; i++) {
        add->data = my_str_to_word_array(add->inventory[i], ":");
        if (my_strcmp(add->data[0], a->main_menu->nickname) != 0)
            write(add->fd, my_strcat(add->inventory[i], "\n"),
            my_strlen(add->inventory[i]) + 1);
        else
            my_strncpy(add->copy, add->inventory[i],
            my_strlen(add->inventory[i]));
    }
    for (; add->inventory[add->j]; add->j++) {
        add->data = my_str_to_word_array(add->inventory[add->j], ":");
        if (my_strcmp(add->data[0], a->main_menu->nickname) == 0)
            break;
    }
}

void add_item(int item, int n, all_t *a)
{
    add_item_t add;

    if (my_strcmp(a->main_menu->nickname, "") == 0)
        a->main_menu->nickname = "default";
    init_add(&add, a);
    change_item(&add, a);
    add_item_next(&add, n, item, a);
    if (my_strcmp(a->main_menu->nickname, "default") == 0) {
        a->main_menu->nickname = my_malloc(sizeof(char) * 10);
        memset(a->main_menu->nickname, '\0', 9);
    }
}