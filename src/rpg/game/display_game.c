/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** display game sprites
*/

#include "rpg.h"
#include "struct.h"

void display_xp_bar(all_t *a)
{
    float xp_pourcentage = ((float){a->player->obj->stat.exp} /
    (float){a->player->obj->stat.max_exp}) * 100;
    float xp_size = (235 * xp_pourcentage) / 100;

    if (xp_pourcentage > 0) {
        sfRectangleShape_setSize(a->inventory.xp_bar,
        (sfVector2f){(int){xp_size}, 27});
    }
    sfRenderWindow_drawRectangleShape(a->window, a->inventory.xp_bar, NULL);
    sfRenderWindow_drawSprite(a->window, a->map.xp_bar.s, NULL);
    sfRenderWindow_drawText(a->window, a->player->lvl, NULL);
}

void display_ui(all_t *a)
{
    handle_quests_display(a);
    handle_location_display(a);
    sfRenderWindow_drawSprite(a->window, a->map.mini_map->s, NULL);
    sfRenderWindow_drawSprite(a->window, a->map.quest_ui.s, NULL);
    sfRenderWindow_drawText(a->window, a->map.quest, NULL);
    sfRenderWindow_drawText(a->window, a->map.location, NULL);
    sfRenderWindow_drawText(a->window, a->map.pseudo, NULL);
    sfText_setString(a->map.pseudo, a->main_menu->nickname);
    display_xp_bar(a);
    draw_inventory(a);
}

void display_game(all_t *a)
{
    if (a->in_dialogue == false)
        a->player->blocked = false;
    sfRenderWindow_drawSprite(a ->window, a->map.map->s, NULL);
    display_npc(a);
    if (a->map.world == FOPSPACE)
        must_draw_before_player_fospace(a);
    if (a->map.world == DUNGEON)
        must_draw_before_player_dungeon(a);
    if (a->map.world == BOSS)
        must_draw_before_player_dungeon_boss(a);
    sfRenderWindow_drawSprite(a->window, a->player->obj->s, NULL);
    if (a->player->blocked == true)
        sfRenderWindow_drawSprite(a->window, a->npc->dotex->s, NULL);
    if (a->map.world == SPAWN)
        must_draw_after_player_spawn(a);
    display_weather(a);
    npc_button(a);
    display_ui(a);
}