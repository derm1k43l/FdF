# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 14:17:17 by mrusu             #+#    #+#              #
#    Updated: 2024/04/05 10:34:29 by mrusu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILER
CC = cc

# FLAGS FOR COMPILATION
FLAGS = -Wall -Wextra -Werror -g -Ofast -Wunreachable-code # -fsanitize=address

# LIBRARY NAME
LIBFT = libft.a
LIBFT_DIR = libft

# MLX LIBRARY
MLX_DIR = mlx42
MLX_FLAGS = ./MLX42/build/libmlx42.a -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit
MLX_INC = -I$(MLX_DIR)

# FdF DIRECTORIES
SRC_DIR = srcs
INC_DIR = inc
OBJ_DIR = obj

# FdF EXECUTABLE NAME
NAME = fdf

# HEADER FILE
HEADER = $(INC_DIR)/fdf.h

# LIST OF SOURCE FILES
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/read.c $(SRC_DIR)/hooks.c $(SRC_DIR)/draw.c $(SRC_DIR)/utils.c \
		$(SRC_DIR)/color.c
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# COLORS
GREEN = \033[0;32m
NC = \033[0m

# ALL RULE
# RULES TO MAKE EXECUTABLE AND LIBFT AND MLX
all: mlx $(LIBFT) $(NAME)
	@echo "$(GREEN)FdF build successful$(NC)"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -I$(INC_DIR) $(MLX_INC) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

# RULES FOR CREATING OBJECT FILES
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I$(INC_DIR) $(MLX_INC) -c $< -o $@

# LIBFT RULES
$(LIBFT):
	@make -C $(LIBFT_DIR)

# MLX TARGET
mlx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	else \
		echo "Directory $(MLX_DIR) already exists."; \
	fi
	@cd $(MLX_DIR) && cmake -B build && cmake --build build -j4

# RULES TO CLEAN EVERYTHING
clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)FdF cleaned$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)FdF fcleaned$(NC)"

# RULES FOR RECOMPILATION
re: fclean all

.PHONY: all clean fclean re