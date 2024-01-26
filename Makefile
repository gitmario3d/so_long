# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 10:33:13 by dparada           #+#    #+#              #
#    Updated: 2024/01/26 08:57:05 by malena-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
USER = malena-b
MLX42 = ./MLX42
LIBFT = ./my_libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src/
OBJ_DIR = obj/

DEF_COLOR	= \033[0;39m
MAGENTA		= \033[0;35m
YELLOW		= \033[0;33m
GREEN		= \033[0;32m
WHITE		= \033[0;37m
RESET		= \033[0m
GRAY		= \033[0;90m
BLUE		= \033[0;34m
CYAN		= \033[0;37m
RED			= \033[0;31m
BOLD		= \033[1m

SRC_FILES = main checkmap utils flood_fill setmap load_img player_move free_fts

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME):	compiling	$(OBJ)
	@echo
	@echo "$(YELLOW)COMPILING LIBFT:$(RESET)"
	@make all -C $(LIBFT)
	@echo
	@echo "$(YELLOW)COMPILING MLX42:$(RESET)"
	@make -C $(MLX42)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
	@echo
	@echo "$(GREEN)COMPLETE!$(RESET)"
	@echo

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(MAGENTA)COMPILING...		$(BLUE)$(notdir $<)$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

compiling:
	@echo "$(YELLOW)COMPILING SO_LONG FILES:$(RESET)"

clean:
	@rm -frf $(OBJ_DIR)
	@make clean -C $(MLX42)
	@echo "$(YELLOW)MLX42 clean:		$(GREEN)[COMPLETED]$(EC)"
	@make clean -C $(LIBFT)

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@make fclean -C $(MLX42)
	@make fclean -C $(LIBFT)
	@echo "$(YELLOW)So_long fclean: 	$(GREEN)[COMPLETED]$(EC)"
	@echo

re: fclean all
	@echo "$(YELLOW)SO_LONG: $(GREEN)[RECOMPILED]$(RESET)"

norm:
	@echo "Norminette of so_long files: "
	@norminette $(SRC_DIR)
	@echo
	@echo "Norminette of libft files: "
	@norminette $(LIBFT)
	@echo
						
.PHONY: all clean fclean re norm compiling

