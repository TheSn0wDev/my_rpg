/*
** EPITECH PROJECT, 2020
** Particles
** File description:
** particle.c
*/

#include "rpg.h"
#include "struct.h"

void init_particles(particles_t *particles, sfColor color)
{
    particles->clock = create_clock();
    particles->rect = create_rectangle();
    particles->circle = create_circle();
    particles->speed = 15;
    particles->color = color;
    sfCircleShape_setFillColor(particles->circle, particles->color);
    sfRectangleShape_setFillColor(particles->rect, particles->color);
    for (int i = 0; i < 1000; i++)
        particles->particle[i].living = false;
}

void init_particle(particle_t *particle, sfVector2f pos, int type)
{
    particle->living = true;
    particle->pos = pos;
    if (type == 1)
        particle->size = (sfVector2f){2, rand() % 30 + 8};
    else
        particle->size = (sfVector2f){2, rand() % 6 + 3};
    particle->pos.y -= particle->size.y;
}

void display_particles(all_t *a, particles_t *particles)
{
    particle_t particle;

    for (int i = 0; i < 1000; i++) {
        particle = particles->particle[i];
        if (particle.living == true && a->particles.weather == 1) {
            sfRectangleShape_setPosition(particles->rect, particle.pos);
            sfRectangleShape_setSize(particles->rect, particle.size);
            sfRenderWindow_drawRectangleShape(a->window, particles->rect, NULL);
        }
        if (particle.living == true && a->particles.weather == 2) {
            sfCircleShape_setPosition(particles->circle, particle.pos);
            sfCircleShape_setRadius(particles->circle, particle.size.y);
            sfRenderWindow_drawCircleShape(a->window, particles->circle, NULL);
        }
    }
}

void update_particle(particles_t *particles, particle_t *particle)
{
    if (particle->living == true) {
        particle->pos.y += particles->speed;
        if (particle->pos.y >= 1080) {
            particle->living = false;
        }
    }
}

void add_particles(particles_t *particles, int particle_num, int type)
{
    sfVector2f new_pos = {0, 0};
    int inits = 0;

    for (int i = 0; inits < particle_num && i < 1000; i++) {
        if (particles->particle[i].living == false) {
            new_pos.x = rand() % 1920;
            inits++;
            init_particle(&particles->particle[i], new_pos, type);
        }
    }
}