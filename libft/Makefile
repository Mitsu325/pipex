# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:27:52 by patricia          #+#    #+#              #
#    Updated: 2022/02/14 01:33:19 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
SRC			= src
OBJ			= obj
SUB_DIR		= put

PUT_F		= ft_putchar_fd.c ft_putstr_fd.c

FILES		= $(foreach file, $(PUT_F), $(SRC)/put/$(file))

OBJ_DIR		= $(foreach dir, $(SUB_DIR), $(addprefix $(OBJ)/, $(dir)))
OBJS		= $(subst $(SRC), $(OBJ), $(FILES:.c=.o))

HEADER		= -I includes

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

$(OBJ)/%.o:	$(SRC)/%.c
			@mkdir -p $(OBJ) $(OBJ_DIR)
			@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)
			@ranlib $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) -r $(OBJ)

re:			fclean all

.PHONY:		all clean fclean re
