##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC		=	gcc

SRCS	=	./src/main.c	\
			./src/rpg/rpg.c	\
			./src/error/error.c	\
			./src/output/print_help.c	\
			./src/render_window/init_window.c	\
			./src/rpg/init/init_rpg.c	\
			./src/rpg/menu/init_menu.c	\
			./src/rpg/menu/menu.c	\
			./src/rpg/menu/create_menu_sprites.c	\
			./src/rpg/menu/menu_objects.c	\
			./src/rpg/menu/events/handle_menu_buttons.c	\
			./src/rpg/menu/events/handle_menu_events.c	\
			./src/rpg/menu/events/handle_initplayer_events.c	\
			./src/rpg/menu/player_show.c	\
			./src/rpg/settings/events/sliders_utilities.c	\
			./src/rpg/menu/handle_parallax.c	\
			./src/rpg/settings/settings.c	\
			./src/rpg/settings/init_settings.c	\
			./src/rpg/settings/get_fps.c	\
			./src/rpg/settings/events/handle_settings_events.c	\
			./src/rpg/settings/events/launch_event_buttons.c	\
			./src/rpg/settings/events/handle_settings_buttons.c	\
			./src/rpg/settings/events/handle_video_settings.c	\
			./src/rpg/settings/events/handle_volumes_settings.c	\
			./src/rpg/settings/create_settings_sprites.c	\
			./src/rpg/settings/events/keybinds.c	\
			./src/rpg/combat/destroy_combat.c	\
			./src/rpg/combat/create_enemy.c	\
			./src/rpg/combat/manipulate_enemy.c	\
			./src/rpg/combat/gauge.c	\
			./src/rpg/combat/handle_combat.c	\
			./src/rpg/combat/init_combat.c	\
			./src/rpg/combat/update_combat.c	\
			./src/rpg/combat/analyse_combat_events.c	\
			./src/rpg/combat/enemy_ai.c	\
			./src/rpg/combat/check_collisions.c	\
			./src/rpg/combat/combat_movement.c	\
			./src/rpg/combat/essentials.c	\
			./src/rpg/game/map/init_map.c	\
			./src/rpg/game/map/push_map.c	\
			./src/rpg/game/mobs_spawns/init_mob.c	\
			./src/rpg/game/mobs_spawns/move_monster_randomly.c	\
			./src/rpg/game/mobs_spawns/mob_colisions.c	\
			./src/rpg/game/mobs_spawns/create_special_mobs.c	\
			./src/rpg/game/mobs_spawns/mob_animation.c	\
			./src/rpg/game/mobs_spawns/mobs_movements.c	\
			./src/rpg/game/mobs_spawns/spawn_mobs.c	\
			./src/rpg/game/mobs_spawns/mobs_object.c	\
			./src/rpg/game/mobs_spawns/linked_list.c	\
			./src/rpg/game/pause_game/init_pause_game.c	\
			./src/rpg/game/pause_game/pause_game.c	\
			./src/rpg/game/pause_game/events/pause_game_events.c	\
			./src/rpg/game/pause_game/events/buttons_events.c	\
			./src/rpg/game/inventory.c	\
			./src/rpg/game/inventory_utils.c	\
			./src/rpg/game/inventory_utils_next.c	\
			./src/rpg/game/inventory_draw.c	\
			./src/rpg/game/inventory_init.c	\
			./src/rpg/game/inventory_init_next.c	\
			./src/rpg/game/player/set_player_pos.c	\
			./src/rpg/game/player/init_player.c	\
			./src/rpg/game/player/collision.c	\
			./src/rpg/game/init_game.c	\
			./src/rpg/game/display_game.c	\
			./src/rpg/game/handle_game.c	\
			./src/rpg/game/events/game_events.c	\
			./src/rpg/game/events/inventory_events.c	\
			./src/rpg/game/events/transition_map.c	\
			./src/rpg/combat/attacks/manipulate_attacks.c	\
			./src/rpg/combat/attacks/attacks.c	\
			./src/rpg/combat/attacks/display_cooldowns.c	\
			./src/rpg/combat/combat_end/combat_end.c	\
			./src/rpg/combat/combat_end/game_over.c	\
			./src/rpg/combat/combat_end/level_up.c	\
			./src/rpg/combat/combat_end/print_win_stats.c	\
			./src/rpg/menu/cinematic/cinematic.c	\
			./src/rpg/menu/cinematic/init.c	\
			./src/rpg/menu/cinematic/cinemativ_movement.c	\
			./src/rpg/menu/cinematic/cin_utility.c	\
			./src/rpg/menu/cinematic/cin_end.c	\
			./src/rpg/game/dialogue/dialogue.c	\
			./src/rpg/game/dialogue/print_dialogue.c	\
			./src/rpg/game/change_zone.c	\
			./src/rpg/game/quest/npc/init_npc.c	\
			./src/rpg/game/quest/npc/npc_in_range.c	\
			./src/rpg/game/quest/npc/lauch_right_dialogue.c	\
			./src/rpg/game/quest/npc/npc_object.c	\
			./src/rpg/game/quest/npc/create_interaction_button.c	\
			./src/rpg/game/quest/init_quest.c	\
			./src/rpg/game/quest/player_file_utils.c	\
			./src/rpg/game/quest/rm_from_data_files.c	\
			./src/rpg/game/draw_dungeon.c	\
			./src/rpg/game/draw_fospace.c	\
			./src/rpg/game/draw_spawn.c	\
			./src/rpg/game/draw_npc.c	\
			./src/rpg/game/quest/npc/p_npc_interaction.c	\
			./src/rpg/game/quest/change_map.c	\
			./src/rpg/game/quest/quest_ui.c	\
			./src/rpg/game/quest/init_q_ui.c	\
			./src/rpg/save/save_player.c	\
			./src/rpg/game/events/drop_item_on_slot.c	\
			./src/rpg/game/events/manipulate_particles.c	\
			./src/rpg/game/events/show_particles.c	\
			./src/rpg/game/events/unequip_events.c	\
			./src/rpg/game/player/init_stats.c	\
			./src/rpg/game/init_inventory_two.c	\
			./src/rpg/menu/events/continue_button.c	\
			./src/rpg/essentials_two.c	\
			./src/rpg/init/init_rpg_two.c	\
			./src/rpg/game/quest/handle_quest_and_pos.c	\
			./src/rpg/game/quest/load_quest_and_pos_two.c	\
			./src/rpg/game/player/equipement_stat_update.c	\
			./src/rpg/menu/how_to_play.c	\
			./src/rpg/game/end_game/init_end_game.c	\
			./src/rpg/game/end_game/end_loop.c	\
			./src/rpg/game/end_game/events/end_game_events.c	\

OBJS	=	$(SRCS:.c=.o)
TARGET	=	my_rpg

LIB_FLAGS		=	-lm -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
LIB_PATH		=	lib/my
INCLUDE_PATH	=	includes
CFLAGS			=	-W -Wall -Wextra -I$(INCLUDE_PATH)

all:	$(TARGET)

$(TARGET):	$(OBJS)
		@ make -C $(LIB_PATH) --silent
		@ $(CC) $(OBJS) -L./$(LIB_PATH) $(LIB_FLAGS) -o $@
		@ echo "\033[1;32m[+]\t\033[1;34m$(TARGET)\033[0m"

tests_run: fclean
		@ make -C $(LIB_PATH) --silent
		@ $(CC) $(SRCS2) -L$(LIB_PATH) $(LIB_FLAGS) -Iincludes --coverage -lcriterion -o unit_tests
		./unit_tests
		gcovr --exclude="tests"

clean:
		@ make clean -C $(LIB_PATH) --silent
		@ $(RM) $(OBJS)
		@ $(RM) *.gcda
		@ $(RM) *.gcno

fclean:	clean
		@ make fclean -C $(LIB_PATH) --silent
		@ $(RM) $(TARGET)
		@ $(RM) unit_tests
		@ echo "\033[1;32m[+]\t\033[1;34mProject cleaned\033[0m"

re: fclean all