# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 20:54:40 by thjonell          #+#    #+#              #
#    Updated: 2020/12/11 20:59:01 by thjonell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
MLX_NAME	= mlx
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
SRCS_LIST	= main.c map_validate.c texture_parse.c world_parse.c \
			get_next_line.c get_next_line_utils.c
MLX_SRCS_L	= mlx.c
SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_LIST))
LIB_FT		= -L$(LIB_DIR) -lft
LIB_MLX		= -L$(LIB_DIR) -lmlx -framework OpenGL -framework Appkit
OBJ_LIST 	= $(patsubst %.c, %.o, $(SRCS_LIST))
OBJ_MLX_L	= $(patsubst %.c, %.o, $(MLX_SRCS_L))
OBJ_MLX		= $(addprefix $(OBJ_DIR)/, $(OBJ_MLX_L))
OBJ 		= $(addprefix $(OBJ_DIR)/, $(OBJ_LIST))
INC_DIR		= includes
LIB_DIR		= libraries
SRCS_DIR	= source
OBJ_DIR		= objects
BIN_DIR		= binary
ENDF		= \033[0m
BOLD		= \033[1m
BOLDGREEN	= \033[1;32m
BOLDWHITE	= \033[1;30m
BOLDRED		= \033[1;31m
BOLDYELLOW	= \033[1;33m
BOLDBLUE	= \033[1;34m
BOLDPURPLE	= \033[1;35m
BOLDTUR		= \033[1;36m
all:		$(NAME)
mlx:		$(OBJ_MLX) | $(BIN_DIR)
			$(CC) $(OBJ_MLX) $(LIB_MLX) -o $(BIN_DIR)/$(MLX_NAME)
$(NAME):	hello | $(OBJ)
			@printf "$(BOLDGREEN)object files sucсessfully created or all of them up-to-date\n$(ENDF)"
			@sleep 1
			@printf "$(BOLDBLUE)creating $(NAME)"
			@sleep 1
			@printf "$(BOLDBLUE).$(ENDF)"
			@sleep 1
			@printf "$(BOLDBLUE).$(ENDF)"
			@sleep 1
			@printf "$(BOLDBLUE).\n$(ENDF)"
			@$(CC) $(OBJ) $(LIB_FT) -o $(BIN_DIR)/$(NAME)
			@printf "$(BOLDGREEN)the $(NAME) sucсessfully created in \"$(BIN_DIR)\" directory! have fun ;)\n$(ENDF)"
$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
$(OBJ_DIR):
			@mkdir -p $@
$(BIN_DIR):
			@mkdir -p $@
hello:		$(BIN_DIR)
			@printf "$(BOLDTUR)h$(BOLDPURPLE)e$(BOLDBLUE)l$(BOLDYELLOW)l$(BOLDRED)o $(BOLDWHITE)@$(BOLDGREEN)u$(BOLDTUR)s$(BOLDPURPLE)e$(BOLDBLUE)r$(BOLDYELLOW)n$(BOLDRED)a$(BOLDWHITE)m$(BOLDGREEN)e$(BOLDTUR)!\n$(ENDF)"
			@sleep 1
			@printf "$(BOLD)creating objects...\n$(ENDF)"
			@sleep 1
clean:
			@$(RM) $(OBJ_DIR)
			@printf "$(BOLDRED)all object files were successfully deleted, boss\n$(ENDF)"
fclean:		clean
			@$(RM) $(BIN_DIR)
			@sleep 1
			@printf "$(BOLDRED)and the $(NAME) too\n$(ENDF)"
			@sleep 1
			@printf "$(BOLDGREEN)cleaning finished!\n$(ENDF)"
			@sleep 1
re:			fclean all
.PHONY:		all clean fclean re