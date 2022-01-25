# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 19:40:05 by cbridget          #+#    #+#              #
#    Updated: 2022/01/25 12:11:19 by cbridget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEAD = hdrs/pipex.h

HEAD_B = hdrs/pipex_bonus.h

SRC = pipex.c check_files.c check_commands.c exc_cmd.c

SRC_B = pipex_bonus.c check_files_bonus.c check_commands_bonus.c exc_cmd_bonus.c\
here_doc_bonus.c here_doc2_bonus.c here_doc3_bonus.c check_commands2_bonus.c\
exc_cmd2_bonus.c

OBJ = $(addprefix obj/,$(SRC:.c=.o))

BUILD_FOLDER := $(shell mkdir -p obj)

FLAGS = -Wall -Werror -Wextra -g3

CC = cc

.PHONY : all clean fclean bonus re LIB

all : LIB $(NAME)

LIB :
	@$(MAKE) bonus -C libft

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

obj/%.o : src/%.c $(HEAD) Makefile
	$(CC) $(FLAGS) -I hdrs -I libft -c $< -o $@

bonus :
	$(LIB)
	@make HEAD="$(HEAD_B)" SRC="$(SRC_B)"

clean :
	rm -rf obj
	$(MAKE) clean -C libft

fclean :
	rm -rf obj
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re : fclean all
