# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 14:29:05 by mfusil            #+#    #+#              #
#    Updated: 2023/05/30 18:59:19 by mfusil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

LIBFT = Libft/libft.a

CFLAG = -g3 -Wall -Wextra -Werror 

ifeq ($(shell test -d /Users/$$USER/.brew/opt/glfw/lib && echo yes),yes)
	LDFLAGS = ../MLX42/libmlx42.a -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib"
else
	LDFLAGS = ../MLX42/libmlx42.a -lglfw -L "/goinfre/$$USER/.brew/opt/glfw/lib"
endif


SRCS = game/main.c\
	   game/init_struct.c\
	   game/print_pixel_in_minimap.c\
	   game/is_a_wall.c\
	   game/render_3d.c\
	   game/color_pixel.c\
	   game/draw.c\
	   game/move.c\
	   game/free_struct_parse.c\
	   game/print_floor_cellar.c\
	   game/verif_in_map.c\
	   game/init_struct_2.c

UTILS = utils/ft_strcmp.c\
		utils/print_tab.c\
		utils/replace_caract.c\
		utils/stock_map.c\
		utils/print_pixel.c\
		utils/different_type_of_line.c\
		utils/ft_strcpy.c\
		utils/get_file.c

PARSING = parsing/pasing_sprite_rgb/start_parsing.c	\
				parsing/pasing_sprite_rgb/check_file.c		\
				parsing/pasing_sprite_rgb/sprite_utils.c	\
				parsing/parsing_map/check_map.c				\
				parsing/parsing_map/check_map2.c			\
				parsing/parsing_map/check_player.c			\
				parsing/parsing_map/check_texture.c			\
				parsing/parsing_map/check_close.c			\
				parsing/parsing_map/map_utils.c				\

FREE = free_fonction/free_tab.c

ALL_SRCS = $(SRCS)\
		   $(UTILS)\
		   $(PARSING)\
		   $(FREE)

OBJS = $(ALL_SRCS:.c=.o)

RE_LIBFT = @make -C Libft


all : $(NAME)

g : 
	./$(NAME) maps/map.cub


n : all
		norminette

.c.o:
	gcc  $(CFLAG) -I "/goinfre/$$USER/.brew/opt/glfw/include" -o $@ -c $<

$(NAME) : $(OBJS)
		$(RE_LIBFT)
		gcc $(CFLAG) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS)
		@echo "$(GREEN)$(BOLD)$(NAME) executable Created"

clean :
		@rm -rf $(OBJS)
		@make clean -C Libft
		@echo "$(GREEN)$(BOLD)$(NAME) objects removed"

fclean : clean
		@rm -rf $(NAME)
		@make fclean -C Libft
		@echo "$(GREEN)$(BOLD)$(NAME) executable removed"

re : fclean all

#----------------------COLORS----------------------
GREEN=\x1b[32m
BOLD=\033[1m
