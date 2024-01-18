# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_Unix.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 21:36:38 by W2Wizard          #+#    #+#              #
#    Updated: 2023/12/27 09:38:14 by malena-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
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

#//= Make Rules =//#
$(NAME): $(OBJS)
	@ar rc $@ $^

%.o: %.c $(HDRS)
	@echo "$(MAGENTA)COMPILING...		$(BLUE)$(notdir $<)$(RESET)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

# Convert shaders to .c files
$(SRC_DIR)/mlx_%_shader.c: $(SHADER_DIR)/default.%
	@echo "$(MAGENTA)SHADER TO C:		$(BLUE)$< -> $(GREEN)$@$(RESET)"
	@bash tools/compile_shader.sh $< > $@

clean:
	@rm -f $(OBJS) $(SHDR)

fclean: clean
	@rm -f $(NAME)
