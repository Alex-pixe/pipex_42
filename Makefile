# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 19:40:05 by cbridget          #+#    #+#              #
#    Updated: 2022/01/13 14:38:14 by cbridget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEAD = hdrs/pipex.h

SRC = pipex.c check_files.c check_commands.c

OBJ = $(addprefix obj/,$(SRC:.c=.o))

BUILD_FOLDER := $(shell mkdir -p obj)

FLAGS = -Wall -Werror -Wextra

CC = cc

.PHONY : all clean fclean bonus re LIB

all : LIB $(NAME)

LIB :
	@$(MAKE) bonus -C libft

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

obj/%.o : src/%.c $(HEAD) Makefile
	$(CC) $(FLAGS) -I hdrs -I libft -c $< -o $@

bonus : all

clean :
	rm -rf obj
	$(MAKE) clean -C libft

fclean :
	rm -rf obj
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re : fclean all
