# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 17:38:22 by dmorgil           #+#    #+#              #
#    Updated: 2019/02/24 16:35:20 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=21sh
HEADER=includes/21sh.h
SRCS_DIR=./sources/
OBJS_DIR=./objects/
LIBFT_DIR=./libft
COMMANDS_DIR=commands/
SRCS_COMMANDS=\
	ft_cd.c		ft_echo.c		ft_env.c\
	ft_hash.c	ft_setenv.c		ft_unsetenv.c

SRCS_WITHOUT_DIR=\
	autocompletion.c\
	divide_commands.c\
	environment.c\
	handle_signals.c\
	input.c\
	main.c\
	make_string.c\
	spec_split.c\
	replace_tilde.c

SOURCES=$(SRCS_WITHOUT_DIR)\
	$(addprefix $(COMMANDS_DIR),$(SRCS_COMMANDS))

SRCS=$(addprefix $(SRCS_DIR),$(SOURCES))
OBJS=$(addprefix $(OBJS_DIR),$(SOURCES:.c=.o))
OBJS_CLEAN=$(strip $(foreach f,$(OBJS),$(wildcard $(f))))
NAME_CLEAN=$(strip $(NAME))
LIBFT_A=$(LIBFT_DIR)/libft.a
INCLUDES:=-I includes -I $(LIBFT_DIR)/includes
FLAGS=-Wall -Wextra -Werror

RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
NC=\033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS_DIR):
	@echo "$(BLUE)Compiling $(NAME_CLEAN) objects files...$(NC)"
	@mkdir -p $(OBJS_DIR)$(COMMANDS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@gcc $(INCLUDES) $(FLAGS) -c $< -o $@

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_A) $(OBJS_DIR) $(OBJS)
	@echo "$(BLUE)Compiling executable...$(NC)"
	@gcc $(OBJS) $(LIBFT_A) $(INCLUDES) $(FLAGS) -o $(NAME) -lreadline
	@echo "$(GREEN)Bin $(NAME) is ready to use!$(NC)"

clean:
ifneq ($(OBJS_CLEAN),)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)$(NAME_CLEAN) objects files removed.$(NC)"
else
	@echo "$(RED)$(NAME_CLEAN) objects already cleaned$(NC)"
endif

fclean: clean
ifneq ($(NAME_CLEAN),)
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@echo "$(RED)Bin $(NAME_CLEAN) removed.$(NC)"
else
	@echo "$(RED)Objects and bin $(NAME_CLEAN) already cleaned$(NC)"
endif

test:
	gcc $(FLAGS) -g $(SRCS) -o $(NAME) $(INCLUDES) $(LIBFT_A) -lreadline

re: fclean all
