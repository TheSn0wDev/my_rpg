/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

void init_minimap_and_location(all_t *a)
{
    sfColor color = sfColor_fromRGBA(228, 228, 228, 155);

    a->map.mini_map = create_map("assets/maps/small_castle_map.png",
    (sfIntRect){0, 0, 2328, 2328}, (sfVector2f){1445, 40},
    (sfVector2f){0.05, 0.05});
    a->map.location = create_texts("assets/fonts/diablo_h.ttf", 34,
    (sfVector2f){1510, 202}, color);
    sfText_setString(a->map.location, "VILLAGE");
}

void init_ui(all_t *a)
{
    menu_object_t quest_ui = {0, 0, {1.4, 1.4},
    {1392, -20}, 0, 0, {0, 0, 377, 202}, 0};
    init_menu_object(&quest_ui, "assets/ui/questmap_ui.png");
    a->map.quest_ui = quest_ui;
    menu_object_t xp_bar = {0, 0, {3, 3},
    {770, 1010}, 0, 0, {0, 0, 143, 18}, 0};
    init_menu_object(&xp_bar, "assets/ui/xp_bar.png");
    a->map.xp_bar = xp_bar;
}

void init_pseudo_text(all_t *a)
{
    sfColor color = sfColor_fromRGBA(222, 161, 55, 255);

    a->map.pseudo = create_texts("assets/fonts/diablo_h.ttf", 24,
    (sfVector2f){1610, 22}, color);
    sfText_setString(a->map.pseudo, a->main_menu->nickname);
}

void init_quest(all_t *a)
{
    sfColor color = sfColor_fromRGBA(228, 228, 228, 155);

    a->map.quest = create_texts("assets/fonts/diablo_h.ttf", 24,
    (sfVector2f){1610, 72}, color);
    sfText_setString(a->map.quest, "Talk to the\nvillage chief.");
    a->player->lvl = create_texts("assets/fonts/diablo_h.ttf", 40,
    (sfVector2f){900, 970}, color);
    sfText_setString(a->player->lvl,
    my_strcat("LEVEL: ", my_itoa(a->player->obj->stat.level)));
    a->map.xp_progress = create_rectangle();
}

void init_quest_ui(all_t *a)
{
    init_ui(a);
    init_minimap_and_location(a);
    init_pseudo_text(a);
    a->map.quest_todo = CHIEF_QUEST;
    init_quest(a);
}