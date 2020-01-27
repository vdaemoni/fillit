# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmerrell <gmerrell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/23 16:47:13 by gmerrell          #+#    #+#              #
#    Updated: 2020/01/26 14:10:12 by vdaemoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBFT = libft

SRCS = ./srcs/ch_file.c \
	   ./srcs/fillit.c \
	   ./srcs/helper_solver.c \
	   ./srcs/lst_create.c \
	   ./srcs/solver.c
OBJS = $(SRCS:%.c=%.o)

HEADER = ./includes/fillit.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
		make -C $(LIBFT)
		gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HEADER) -L. libft/libft.a

clean :
		/bin/rm -f $(OBJS)
		make -C $(LIBFT) clean

fclean : clean
		/bin/rm -f $(NAME)
		make -C $(LIBFT) fclean

re : fclean all
