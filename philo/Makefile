# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 14:52:50 by gde-la-r          #+#    #+#              #
#    Updated: 2025/05/15 14:52:51 by gde-la-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
FLAGS = -Wall -Wextra -Werror -pthread -g

SRCS_DIR = ./srcs
INCLUDES = ./includes/

SRC= $(SRCS_DIR)/main.c \
	 $(SRCS_DIR)/chars.c \
	 $(SRCS_DIR)/parsing.c \
	 $(SRCS_DIR)/exit.c \

OBJS = $(SRC:.c=.o)

#Colors
RED    = \033[38;5;196m
GREEN  = \033[38;5;46m
BLUE   = \033[38;5;33m
ORANGE = \033[38;5;208m
NC     = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation completed!$(NC)"

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@

clean: $(OBJS)
	@rm -rf $(OBJS)
	@clear
	@echo "$(RED)Object files removed!$(NC)"

fclean: $(NAME) $(OBJS)
	@rm -rf $(OBJS) $(NAME)
	@clear
	@echo "$(RED)Object files & $(NAME) removed!$(NC)"

re:
	@rm -rf $(OBJS) $(NAME)
	@make all
	@clear
	@echo "$(GREEN)Rebuild completed!$(NC)"

PHONY: all clean fclean re
