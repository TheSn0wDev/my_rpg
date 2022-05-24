/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** events
*/

#ifndef EVENTS_H_
#define EVENTS_H_

#include "struct.h"
#include "rpg.h"

void handle_pausegame_events(all_t *a);
void handle_pause_buttons(all_t *a, sfEvent event);

#endif /* !EVENTS_H_ */
