/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** npc init
*/

#include "rpg.h"
#include "struct.h"

int is_lowalpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int get_npc_nb(char **txtmap)
{
    int count = 0;

    for (int i = 0; txtmap[i]; i++)
        for (int j = 0; txtmap[i][j]; j++)
            count += is_lowalpha(txtmap[i][j]) ? 1 : 0;
    return (count);
}

bool first_init(all_t *a)
{
    a->npc->go_back = create_clock();
    a->npc[0].npc_arr = create_my_npc_arr(a);
    a->npc[0].index = 0;
    a->npc[0].npc_nb = 0;
    a->npc[0].obj = my_malloc(sizeof(npc_obj_t) * (5));
    memset(a->npc[0].obj, '\0', 5);
    return (true);
}

void can_create_npc(all_t *a, int i, int j, char **fp)
{
    if (is_lowalpha(a->map.txtmap[i][j])) {
        a->npc[0].fp = fp[a->map.txtmap[i][j] - 97];
        create_npc((sfVector2f){j, i}, a,
        &a->npc[0].npc_arr[a->map.txtmap[i][j] - 97]);
        a->npc[0].index++;
    }
}

void init_npc(all_t *a, bool init)
{
    char *fp[5] = {"assets/npc/rouxcool.png",
    "assets/npc/spawnnpc.png", "assets/npc/forgeron.png",
    "assets/npc/oldidk.png", "assets/npc/skeleton.png"};

    if (init == false)
        init = first_init(a);
    for (int i = 0; a->map.txtmap[i]; i++)
        for (int j = 0; a->npc[0].index < 5 && a->map.txtmap[i][j]; j++)
            can_create_npc(a, i, j, fp);
    if (a->map.quest_todo < OLDGUY_QUEST)
        a->npc[0].npc_arr[FORGERON].quest = true;
}