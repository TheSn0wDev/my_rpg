/*
** EPITECH PROJECT, 2021
** csfml_garbage_collector.h
** File description:
** for garbage_collector function
*/

#ifndef CSFML_GARBAGE_COLLECTOR_H_
#define CSFML_GARBAGE_COLLECTOR_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// sfTexture Garbage Collector

typedef struct texture_collector_s texture_collector_t;

struct texture_collector_s
{
    sfTexture *texture;
    struct texture_collector_s *next;
};

sfTexture *create_texture(const char *file, const sfIntRect *area);
texture_collector_t **get_texture_collector(void);
void destroy_texture_to_texture_collector_t(void);

// sfSprite Garbage Collector

typedef struct sprite_collector_s sprite_collector_t;

struct sprite_collector_s
{
    sfSprite *sprite;
    struct sprite_collector_s *next;
};

sfSprite *create_sprite(void);
sprite_collector_t **get_sprite_collector(void);
void destroy_sprite_to_sprite_collector_t(void);

// sfClock Garbage Collector

typedef struct clock_collector_s clock_collector_t;

struct clock_collector_s
{
    sfClock *clock;
    struct clock_collector_s *next;
};

sfClock *create_clock(void);
clock_collector_t **get_clock_collector(void);
void destroy_clock_to_clock_collector_t(void);

// sfRectangleShape Garbage Collector

typedef struct rectangle_collector_s rectangle_collector_t;

struct rectangle_collector_s
{
    sfRectangleShape *rectangle;
    struct rectangle_collector_s *next;
};

sfRectangleShape *create_rectangle(void);
rectangle_collector_t **get_rectangle_collector(void);
void destroy_rectangle_to_rectangle_collector_t(void);

// sfCircleShape Garbage Collector

typedef struct circle_collector_s circle_collector_t;

struct circle_collector_s
{
    sfCircleShape *circle;
    struct circle_collector_s *next;
};

sfCircleShape *create_circle(void);
circle_collector_t **get_circle_collector(void);
void destroy_circle_to_circle_collector_t(void);

// sfText Garbage Collector

typedef struct text_collector_s text_collector_t;

struct text_collector_s
{
    sfText *text;
    struct text_collector_s *next;
};

sfText *create_text(void);
text_collector_t **get_text_collector(void);
void destroy_text_to_text_collector_t(void);

// sfMusic Garbage Collector

typedef struct music_collector_s music_collector_t;

struct music_collector_s
{
    sfMusic *music;
    struct music_collector_s *next;
};

sfMusic *create_music(const char *filename);
music_collector_t **get_music_collector(void);
void destroy_music_to_music_collector_t(void);

// sfFont Garbage Collector

typedef struct font_collector_s font_collector_t;

struct font_collector_s
{
    sfFont *font;
    struct font_collector_s *next;
};

sfFont *create_font(const char *filename);
font_collector_t **get_font_collector(void);
void destroy_font_to_font_collector_t(void);

#endif
