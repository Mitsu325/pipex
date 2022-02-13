# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 21:09:44 by pmitsuko          #+#    #+#              #
#    Updated: 2022/02/13 21:39:43 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
SRC		=	src
OBJ		=	obj

FILES	=	$(SRC)/main.c

OBJ_DIR	=	$(foreach dir, $(SUB_DIR), $(addprefix $(OBJ)/, $(dir)))
OBJS	=	$(subst $(SRC), $(OBJ), $(FILES:.c=.o))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

RM		=	/bin/rm -rf
NORM	=	norminette

$(OBJ)/%.o:	$(SRC)/%.c
			@mkdir -p $(OBJ) $(OBJ_DIR)
			@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)
			@echo "\n\e[96m----------------------------------------"
			@echo "\e[96m--------------- MAKE PIPEX ---------------"
			@echo "\e[96m----------------------------------------\n"

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)
			@echo "\n\e[95m----------------------------------------"
			@echo "\e[95m------------- CLEANING DONE ------------"
			@echo "\e[95m----------------------------------------\n"

re:			fclean all

.PHONY:		all clean fclean re
