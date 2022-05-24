/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** init_window
*/

#include "rpg.h"

sfRenderWindow *create_window(sfUint32 style, sfImage *logo)
{
    sfRenderWindow *window;
    const sfVideoMode *mode = sfVideoMode_getFullscreenModes(0);
    char *name = "My RPG";

    window = sfRenderWindow_create(*mode, name, style, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, 140, 140, sfImage_getPixelsPtr(logo));
    return (window);
}