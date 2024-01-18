# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 08:41:33 by malena-b          #+#    #+#              #
#    Updated: 2024/01/17 12:06:19 by malena-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = obj/

SOURCE = ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit \
		ft_isprint ft_memchr ft_memcpy ft_memmove ft_memset ft_strchr \
		ft_strlcat ft_strlcpy ft_strlen ft_strncmp ft_strnstr ft_strrchr \
		ft_tolower ft_toupper ft_memcmp ft_calloc ft_strdup ft_putchar_fd \
		ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_striteri ft_strmapi ft_itoa \
		ft_split ft_substr ft_strjoin ft_strtrim
BONUS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone \
		ft_lstclear ft_lstiter ft_lstmap
GNL = get_next_line get_next_line_utils get_next_line_bonus
PRINTF = ft_printchar ft_printdecimal ft_printf ft_printhex ft_printstr ft_printunsint

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
EC=\033[0m

OBJECTS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SOURCE)))
BOBJECTS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(BONUS)))
GNLOBJECTS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(GNL)))
PRINTFOBJECTS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(PRINTF)))

OBJF = .cache_exists

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	@echo "$(BLUE)Libft/Base_code:   	$(GREEN)[COMPILED]$(EC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME) bonus gnl ptf

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -frf $(OBJ_DIR)
	@echo "$(YELLOW)Libft clean:		$(GREEN)[COMPLETED]$(EC)"

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@echo "$(YELLOW)Libft fclean:		$(GREEN)[COMPLETED]$(EC)"

re: fclean all

bonus: $(BOBJECTS)
	@ar rcs $(NAME) $(BOBJECTS)
	@echo "$(BLUE)Libft/Bonus:       	$(GREEN)[COMPILED]$(EC)"

gnl: $(GNLOBJECTS)
	@ar rcs $(NAME) $(GNLOBJECTS)
	@echo "$(BLUE)Libft/Get_next_line:	$(GREEN)[COMPILED]$(EC)"

ptf: $(PRINTFOBJECTS)
	@ar rcs $(NAME) $(PRINTFOBJECTS)
	@echo "$(BLUE)Libft/Printf:       	$(GREEN)[COMPILED]$(EC)"

.PHONY: all clean fclean re bonus gnl ptf