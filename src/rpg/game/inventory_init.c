/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game
*/

#include "rpg.h"
#include "struct.h"

void init_player_inv(char *nickname, all_t *a)
{
    int fd = open("data/players/inventory.txt", O_WRONLY);
    char **inventory = read_file_inv("data/players/inventory.txt");

    if (inventory == NULL) {
        write(fd, nickname, my_strlen(nickname));
        write(fd, ":9:0:9:0:9:0:9:0:9:0", 20);
        close(fd);
        return;
    }
    for (int i = 0; inventory[i]; i++) {
        a->inventory.data = my_str_to_word_array(inventory[i], ":");
        if (my_strcmp(a->inventory.data[0], "default") != 0)
            write(fd, my_strcat(inventory[i], "\n"),
            my_strlen(inventory[i]) + 1);
    }
    write(fd, nickname, my_strlen(nickname));
    write(fd, ":9:0:9:0:9:0:9:0:9:0", 20);
    close(fd);
}

inv_item_t *load_items(all_t *a)
{
    char **inventory = read_file_inv("data/players/inventory.txt");
    int i = 0;

    if (inventory == NULL) {
        init_player_inv(a->main_menu->nickname, a);
        return (load_items(a));
    }
    for (; inventory[i]; i++) {
        a->inventory.data = my_str_to_word_array(inventory[i], ":");
        if ((my_strcmp(a->inventory.data[0], a->main_menu->nickname) == 0) ||
        (my_strcmp(a->inventory.data[0], "default") == 0 &&
        my_strcmp(a->main_menu->nickname, "") == 0))
            break;
    }
    if (inventory[i] == NULL) {
        init_player_inv(a->main_menu->nickname, a);
        return (load_items(a));
    }
    return (load_inv(inventory[i], a->inventory.data, a));
}

void init_inventory_stats(all_t *a)
{
    sfColor color = {81, 90, 90, 255};

    a->inventory.stats.font = create_font("assets/fonts/diablo_h.ttf");
    a->inventory.stats.text = create_text();
    sfText_setFont(a->inventory.stats.text, a->inventory.stats.font);
    sfText_setColor(a->inventory.stats.text, color);
    sfText_setCharacterSize(a->inventory.stats.text, 16);
}

void init_inventory(all_t *a)
{
    menu_object_t inventory = {0, 0, {0.7, 0.7},
    {1470, 262}, 0, 0, {0, 0, 638, 735}, 0};

    init_menu_object(&inventory, "assets/inventory/inventory.png");
    a->inventory.sprite = inventory;
    a->inventory.show = false;
    init_inventory_stats(a);
    if (my_strcmp(a->main_menu->nickname, "") == 0)
        init_player_inv("default", a);
    a->inventory.items = load_items(a);
    init_xp_bar(a);
}