/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** npc
*/

#ifndef NPC_H_
#define NPC_H_

#include "struct.h"

int is_npc_in_range(all_t *a);
void check_npc_interaction(all_t *a);
void questmaster(all_t *a);
void forgeron(all_t *a);
void oldidk(all_t *a);
void skeleton(all_t *a);
void spawnnpc(all_t *a);
void init_npc_object(npc_obj_t *object, char *filepath);
void create_npc(sfVector2f pos, all_t *a, npc_obj_t *character);
npc_obj_t *create_my_npc_arr(all_t *a);
void create_interaction_button_sprite(all_t *a);
void questmaster_interact(all_t *a);
void handle_interaction_button(all_t *a, int id);
void forgeron_interact(all_t *a);
void reloard_map_player_pos(all_t *a, sfIntRect pos);
void reload_map(all_t *a, char *mappath, char *txtpath);
void init_npc(all_t *a, bool init);

#endif /* !NPC_H_ */