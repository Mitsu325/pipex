# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 21:09:44 by pmitsuko          #+#    #+#              #
#    Updated: 2022/02/19 20:53:44 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
SRC			=	src
OBJ			=	obj
SUB_SRC		=	error process utils
SUB_UTILS	=	put str

SRC_FILE	=	main.c utils.c find_exec_path.c
ERR_FILE	=	error_handler.c
PROC_FILE	=	child_process.c parent_process.c run_cmd.c
PUT_FILE	=	putchar_fd.c putstr_fd.c
STR_FILE	=	split.c strchr.c strjoin.c strlen.c strnstr.c substr.c

FILES		=	$(foreach file, $(SRC_FILE), $(SRC)/$(file))
FILES		+=	$(foreach file, $(ERR_FILE), $(SRC)/error/$(file))
FILES		+=	$(foreach file, $(PROC_FILE), $(SRC)/process/$(file))
FILES		+=	$(foreach file, $(PUT_FILE), $(SRC)/utils/put/$(file))
FILES		+=	$(foreach file, $(STR_FILE), $(SRC)/utils/str/$(file))

OBJ_DIR		=	$(foreach dir, $(SUB_SRC), $(addprefix $(OBJ)/, $(dir)))
OBJ_UTIL_D	=	$(foreach dir, $(SUB_UTILS), $(addprefix $(OBJ)/utils/, $(dir)))
OBJS		=	$(subst $(SRC), $(OBJ), $(FILES:.c=.o))

HEADER		=	-I includes -I $(LIBFT_DIR)/includes/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g 

RM			=	rm -rf

$(OBJ)/%.o:		$(SRC)/%.c
				@mkdir -p $(OBJ) $(OBJ_DIR) $(OBJ_UTIL_D)
				@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all:			$(NAME)
				@echo "\n\e[96m----------------------------------------"
				@echo "-------------- MAKE PIPEX --------------"
				@echo "----------------------------------------\n\e[0m"

$(NAME):		$(OBJS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				@$(RM) $(OBJS)
				@$(RM) $(OBJ)

fclean:			clean
				@$(RM) $(NAME)
				@echo "\n\e[95m----------------------------------------"
				@echo "------------- CLEANING DONE ------------"
				@echo "----------------------------------------\n\e[0m"

re:				fclean all

memory:			
				@valgrind ./pipex test "ls -l" "wc -l" test_my_output
memoryfull:		
				@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./pipex test "ls -l" "wc -l" test_my_output

relog:
				@$(RM) valgrind-out.txt

obj:
				@echo $(OBJ_UTIL_D)

.PHONY:			all clean fclean re memory memoryfull relog obj
