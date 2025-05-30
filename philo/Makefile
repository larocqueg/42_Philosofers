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

SRCS= $(SRCS_DIR)/main.c \
	  $(SRCS_DIR)/ft_atoll.c \
	  $(SRCS_DIR)/pthread_helpers.c \
	  $(SRCS_DIR)/get_time.c \
	  $(SRCS_DIR)/state.c \
	  $(SRCS_DIR)/routine.c \
	  $(SRCS_DIR)/actions.c \
	  $(SRCS_DIR)/monitor.c \
	  $(SRCS_DIR)/getters_setters.c \
	  $(SRCS_DIR)/init_forks.c \
	  $(SRCS_DIR)/free_philo.c \
	  $(SRCS_DIR)/input_handler.c \
	  $(SRCS_DIR)/forks.c \



OBJS = $(SRCS:.c=.o)

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
