/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** events
*/

#ifndef EVENTS_H_
#define EVENTS_H_

void handle_menu_events(all_t *a);
bool nicknamebar_over(all_t *a, sfVector2i mouse);
void handle_menu_buttons(all_t *a, sfEvent event);
void arrow_button(all_t *a, sfEvent event, sfVector2i mouse);
bool is_sprite_hovered(menu_object_t sprite, sfVector2i mouse);
char *nickname_bar_event(all_t *a, sfEvent event, sfVector2i mouse);

#endif /* !EVENTS_H_ */