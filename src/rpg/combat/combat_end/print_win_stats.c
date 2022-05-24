/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** print_win_stats.c
*/

#include <rpg.h>

sfText *create_stats_text(sfColor color, sfFont *font, int dim)
{
    sfText *text = create_text();

    sfText_setFillColor(text, color);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, dim);
    return (text);
}

void init_text_stats(char *stat, sfText **text, int old_stat, int new_stat)
{
    char *old_str = to_str(old_stat);
    char *new_str = to_str(new_stat);

    sfText_setString(text[0], stat);
    sfText_setString(text[1], old_str);
    sfText_setString(text[2], "-");
    sfText_setString(text[3], new_str);
}

void init_text_pos_stats(sfText **text, int row)
{
    sfVector2f pos = {650, 250};

    pos.y += row * 50;
    sfText_setPosition(text[0], pos);
    pos.x = 1064;
    sfText_setPosition(text[1], pos);
    pos.x = 1164;
    sfText_setPosition(text[2], pos);
    pos.x += 64;
    sfText_setPosition(text[3], pos);
}

void init_level_up_texts(sfText **text, stat_t *old_stats, stat_t *stats)
{
    init_text_stats("Level Up!", &text[8], old_stats->level, stats->level);
    init_text_pos_stats(&text[8], 3);
    init_text_stats("Health", &text[12], old_stats->hp, stats->hp);
    init_text_pos_stats(&text[12], 5);
    init_text_stats("Attack", &text[16], old_stats->attack, stats->attack);
    init_text_pos_stats(&text[16], 6);
    init_text_stats("Defense", &text[20], old_stats->defense, stats->defense);
    init_text_pos_stats(&text[20], 7);
    init_text_stats("Speed", &text[24], old_stats->speed, stats->speed);
    init_text_pos_stats(&text[24], 8);
}

void init_texts(all_t *a, sfText **text, stat_t *old_stats)
{
    stat_t new_stats = a->player->obj->stat;
    sfFont *font = a->text.font;

    for (int i = 0; i < 28; i++)
        text[i] = create_stats_text(sfWhite, font, 32);
    init_text_stats("Experience", text, old_stats->exp, new_stats.exp);
    init_text_pos_stats(text, 0);
    init_text_stats("Gold", &text[4], old_stats->gold, new_stats.gold);
    init_text_pos_stats(&text[4], 1);
    if (old_stats->level != new_stats.level)
        init_level_up_texts(text, old_stats, &new_stats);
}