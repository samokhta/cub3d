# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 09:56:12 by sravizza          #+#    #+#              #
#    Updated: 2025/11/14 12:13:19 by sravizza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##								DIRECTORIES									  ##
MLX_DIR		= mlx_linux
LIBFT_DIR	= libft
SRC_DIR		= src
OBJ_DIR		= obj
INCL_DIR	= incl
PARS_DIR	= parsing
WIN_DIR		= window
RAY_DIR		= raycasting

################################################################################
##								  SOURCES									  ##

SRC_MAIN	= main_cub3d.c	utils.c init.c

SRC_PARS	= parsing.c param.c utils_pars.c test.c utils_lst.c map.c floodfill.c

SRC_WIN		= window_init.c

SRC_RAY		= raycasting.c	dda.c init_ray.c

SRC			= $(SRC_MAIN)													   \
			  $(addprefix $(PARS_DIR)/, $(SRC_PARS))						   \
			  $(addprefix $(WIN_DIR)/, $(SRC_WIN))							   \
			  $(addprefix $(RAY_DIR)/, $(SRC_RAY))							   

LIBFT_LIB	= $(LIBFT_DIR)/libft.a
MLX_LIB		= $(MLX_DIR)/libmlx.a


################################################################################
##								 ARGUMENTS									  ##


NAME	= cub3d
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I$(INCL_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)
LFLAGS	= -L$(MLX_DIR) -L$(LIBFT_DIR) -lmlx -lXext -lX11 -lm -lft
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
RM		= rm -f
AR		= ar -rcs


################################################################################
##								   RULES									  ##

$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | create_obj_dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PARS_DIR)/%.c | create_obj_dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(WIN_DIR)/%.c | create_obj_dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(RAY_DIR)/%.c | create_obj_dirs
	$(CC) $(CFLAGS) -c $< -o $@

create_obj_dirs:
	mkdir -p	$(OBJ_DIR)/$(PARS_DIR) $(OBJ_DIR)/$(WIN_DIR) $(OBJ_DIR)/$(RAY_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR) > /dev/null
	echo "libft compiled"

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR) > /dev/null
	echo "mlx compiled"

	
################################################################################
##								   COMMANDS									  ##

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	echo $(NAME) "obj removed"
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	echo $(NAME) "removed"
	$(MAKE) -C $(LIBFT_DIR) fclean

re: clean all

debug: CFLAGS += -g
debug: re
	echo $(NAME) "compiled in debug mode"

valgrind: CFLAGS += -g
valgrind: re
	$(VALGRIND) $(VFLAGS) $(VSUPP) ./$(NAME)

.SILENT:

.PHONY: all clean fclean re debug