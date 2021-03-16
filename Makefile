# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 20:54:40 by thjonell          #+#    #+#              #
#    Updated: 2021/03/16 18:31:55 by thjonell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
MLX_NAME	= mlx
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
SRCS_LIST	= main.c map_validate.c elem_parse.c data_parsing.c \
			get_next_line.c get_next_line_utils.c render.c render_walls.c \
			key_on_off.c mlx_utils.c movement.c render_walls_utils.c \
			render_walls_utils2.c rotation.c render_sprite.c texture_init.c \
			sprite_player_init.c render_sprite_utils.c init_utils.c \
			render_minimap.c validate.c double_id_check.c elem_parse_utils.c
SRCS_BONUS	= main_bonus.c map_validate.c elem_parse.c data_parsing.c \
			get_next_line.c get_next_line_utils.c render_bonus.c render_walls.c \
			key_on_off.c mlx_utils.c movement_bonus.c render_walls_utils.c \
			render_walls_utils2.c rotation.c render_sprite.c texture_init.c \
			sprite_player_init.c render_sprite_utils.c init_utils.c \
			render_minimap.c validate.c double_id_check.c elem_parse_utils.c
SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_LIST))
LIB_FT		= -Llibft -lft
LIB_MLX		= -lmlx libmlx.dylib -framework OpenGL -framework Appkit
OBJ_LIST 	= $(patsubst %.c, %.o, $(SRCS_LIST))
OBJ_LIST_B 	= $(patsubst %.c, %.o, $(SRCS_BONUS))
OBJ 		= $(addprefix $(OBJ_DIR)/, $(OBJ_LIST))
OBJ_BONUS	= $(addprefix $(OBJ_DIR)/, $(OBJ_LIST_B))
INC_DIR		= includes
SRCS_DIR	= source
OBJ_DIR		= objects
all:		$(NAME)
$(NAME):	$(OBJ)
			#cd libft && make bonus
			#cd mlx && make
			#cp mlx/libmlx.dylib libmlx.dylib
			$(CC) $(CFLAGS) $(OBJ) $(LIB_FT) $(LIB_MLX) -o $(NAME)
bonus:		$(OBJ_BONUS)
			$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB_FT) $(LIB_MLX) -o $(NAME)
$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
$(OBJ_DIR):
			mkdir -p $@
clean:
			#cd libft && make clean
			#cd mlx && make clean
			$(RM) $(OBJ_DIR)
fclean:		clean
			#cd libft && make fclean
			#cd mlx && make clean
			$(RM) $(NAME)
re:			fclean all
.PHONY:		all clean fclean re