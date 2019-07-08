##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of my project lemin
##

ROOT			=	.

MAIN 			= 	main

NAME			=	lem_in

INCLUDE			= 	include

CC				= 	gcc

RM 				= 	rm

TYPE 			=	.c

SRC_DIR			=	$(addprefix $(ROOT)/, src)

BUILD			=	$(ROOT)/obj

SRC_PREFIX 		= 	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

SRC				= 	$(addsuffix $(TYPE), $(SRC_PREFIX))

OBJS			=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(SRC))

ALGO			=	dijkstra

SRC_FILES		=	my_calloc			\
					my_strcalloc		\
					error				\
					my_get_nbr			\
					my_strlen			\
					my_strdup			\
					get_input			\
					my_putstr			\
					my_strcat			\
					get_nextreturn		\
					my_strncmp			\
					clear_input			\
					create_room 		\
					create_room_2 		\
					my_put_nbr			\
					is_link				\
					is_room				\
					my_strcmp			\
					error_link			\
					display_map			\
					check_coord			\
					get_distance		\
					get_path			\
					my_nbr_to_str		\
					simulation			\
					is_this_str 		\
					create_links		\
					create_links_tools 	\
					my_macro		 	\
					$(ALGO)/init_algo	\
					$(ALGO)/set_algo	\
					$(ALGO)/move_ant	\
					$(MAIN)

WARN			=	-W -Wall -Wpedantic $(WERROR)

WERROR			= 	-Werror

CFLAGS			=	-I $(ROOT)/$(INCLUDE) $(WARN) -g3

DEBUG 			= 	@


#COLORS

GREEN 			=	\e[1;32m
WHITE			=	\e[0m
ORANGE			=	\e[1;33m
RED				=	\e[1;31m
BLUE			=	\e[1;34m
YELLOW			=	\e[1;93m


all:				$(NAME)

$(NAME):			echo_start $(BUILD)/$(NAME)
					$(DEBUG)cp $(BUILD)/$(NAME) $(ROOT)
					$(DEBUG)printf "$(ORANGE)Successful to copy binary into root directory.\n$(WHITE)"

$(BUILD)/$(NAME):	$(OBJS)
					$(DEBUG)printf "$(ORANGE)Compile sources.$(WHITE)\n"
					$(DEBUG)$(CC) -o $(BUILD)/$(NAME) $(OBJS)
					$(DEBUG)printf "$(ORANGE)Start link obj and libraries.$(WHITE)\n"

$(BUILD)/%.o:		$(SRC_DIR)/%.c
					$(DEBUG)printf "$(ORANGE)Compiling$(WHITE)[$(YELLOW)$(notdir $<)$(WHITE)]$(RED)->$(WHITE)[$(YELLOW)$(notdir $@)$(WHITE)]\n"
					$(DEBUG)$(CC) -o $@ -c $< $(CFLAGS)

echo_start:	
					$(DEBUG)mkdir -p $(BUILD)
					$(DEBUG)mkdir -p $(BUILD)/$(ALGO)
					$(DEBUG)printf "$(RED)Start the compilation:\n$(WHITE)"

clean:
					$(DEBUG)$(RM) -rf $(OBJS)
					$(DEBUG)$(RM) -rf $(BUILD)
					$(DEBUG)$(RM) -rf $(BUILD)/$(ALGO)
					$(DEBUG)printf "$(ORANGE)Delete object files.$(WHITE)\n"

fclean:	clean
					$(DEBUG)$(RM) -f $(BUILD)/$(NAME)
					$(DEBUG)$(RM) -f $(ROOT)/$(NAME)
					$(DEBUG)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

re:					fclean
					$(DEBUG)make --no-print-directory all

.PHONY: clean fclean all re echo_start
