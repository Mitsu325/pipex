# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 21:09:44 by pmitsuko          #+#    #+#              #
#    Updated: 2022/02/14 01:33:12 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
SRC			=	src
OBJ			=	obj

SRC_FILE	=	main.c error_handler.c

FILES		=	$(foreach file, $(SRC_FILE), $(SRC)/$(file))

OBJS		=	$(subst $(SRC), $(OBJ), $(FILES:.c=.o))

LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_DIR	=	libft/
LIB_FLAGS	=	-L $(LIBFT_DIR) -lft -L /usr/local/lib
HEADER		=	-I includes -I $(LIBFT_DIR)/includes/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

RM			=	rm -rf

$(OBJ)/%.o:		$(SRC)/%.c
				@mkdir -p $(OBJ)
				@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all:			$(NAME)
				@echo "\n\e[96m----------------------------------------"
				@echo "-------------- MAKE PIPEX --------------"
				@echo "----------------------------------------\n\e[0m"

$(LIBFT):
				@make --no-print-directory -C $(LIBFT_DIR)

$(NAME):		$(OBJS) $(LIBFT)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_FLAGS)

clean:
				@make clean --no-print-directory -C $(LIBFT_DIR)
				@$(RM) $(OBJS)
				@$(RM) $(OBJ)

fclean:			clean
				@make fclean --no-print-directory -C $(LIBFT_DIR)
				@$(RM) $(NAME)
				@echo "\n\e[95m----------------------------------------"
				@echo "------------- CLEANING DONE ------------"
				@echo "----------------------------------------\n\e[0m"

re:				fclean all

.PHONY:			all clean fclean re
