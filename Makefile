# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/23 16:47:13 by gmerrell          #+#    #+#              #
#    Updated: 2020/01/29 17:18:25 by vdaemoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft
LIBFT_INCLUDES = libft/includes
SRCS = ./srcs/ch_file.c \
	   ./srcs/fillit.c \
	   ./srcs/helper_solver.c \
	   ./srcs/lst_create.c \
	   ./srcs/solver.c
OBJS = $(SRCS:%.c=%.o)
INCLUDES = includes

all: $(NAME)

$(NAME) : $(OBJS)
		make -C $(LIBFT)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lft
%.o: %.c
		$(CC) $(FLAGS) -I $(LIBFT_INCLUDES) -I $(INCLUDES) -o $@ -c $<

clean :
		/bin/rm -f $(OBJS)
		make -C $(LIBFT) clean

fclean : clean
		/bin/rm -f $(NAME)
		make -C $(LIBFT) fclean

re : fclean all
