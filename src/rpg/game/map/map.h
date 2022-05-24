/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** map
*/

#ifndef MAP
#define MAP

#include "struct.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/JoystickIdentification.h>

map_obj_t *create_map(char *filepath, sfIntRect rect,
sfVector2f pos, sfVector2f scale);
int push_map(all_t *a, sfKeyCode code);
char **get_txt_map(char *filepath);
void reloard_minimap(all_t *a, char *fp);

#endif /* !MAP */