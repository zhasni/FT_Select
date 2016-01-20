# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/16 14:59:53 by zhasni            #+#    #+#              #
#    Updated: 2015/03/19 11:21:45 by zhasni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= 	ft_select.c \
				main.c \
				print.c \
				signal.c \
				set.c \
				tools.c

NAME		= 	ft_select
CC			= 	gcc
CFLAGS		= 	-Werror -Wextra -Wall
OBJ			= 	$(SRC:.c=.o)
RM			= 	rm -rf
INCLUDES	=	libft/
OBJ 		=	$(SRC:.c=.o)
LIBFT		=	libft/
HEADERS		=	-I./. -Ilibft/
LIB			=	libft.a

all: $(LIB) $(NAME)
	@echo "\033[0mCrew ready to sail Cap'tain!~~";
	@echo "                                    ,shhhhhhhhhhhhhhho.      ,hhhhhhhhhhhhhhhoohhhhhhhhhhhhhhhh, ";
	@echo "                                  ,sNMMMMMMMMMMMMMMm+.       /MMMMMMMMMMMMMd/.sMMMMMMMMMMMMMMMM: ";
	@echo "                                ,smMMMMMMMMMMMMMMm+,         /MMMMMMMMMMMd+,  sMMMMMMMMMMMMMMMM: ";
	@echo "                              ,smMMMMMMMMMMMMMMm+,           /MMMMMMMMMd+,    sMMMMMMMMMMMMMMMM: ";
	@echo "                            ,omMMMMMMMMMMMMMMmo,             /MMMMMMMd+,      sMMMMMMMMMMMMMMMM: ";
	@echo "                          ,omMMMMMMMMMMMMMMmo,               /MMMMMm+,        sMMMMMMMMMMMMMMMM: ";
	@echo "                        ,omMMMMMMMMMMMMMMmo,                 /MMMmo,          sMMMMMMMMMMMMMMMM: ";
	@echo "                      ,omMMMMMMMMMMMMMMmo,                   /Mmo,            sMMMMMMMMMMMMMMMM: ";
	@echo "                    ,omMMMMMMMMMMMMMMNs,                     :o,             ,yMMMMMMMMMMMMMMMN, ";
	@echo "                  ,omMMMMMMMMMMMMMMNs,                                     ,:hMMMMMMMMMMMMMMNh:  ";
	@echo "                ,+mMMMMMMMMMMMMMMNs,                                     ,:hMMMMMMMMMMMMMMNh:    ";
	@echo "              ,+mMMMMMMMMMMMMMMNs,                                      ,hMMMMMMMMMMMMMMNd/      ";
	@echo "            ,+mMMMMMMMMMMMMMMNs,                                      ,yMMMMMMMMMMMMMMMd/,       ";
	@echo "          ,/mMMMMMMMMMMMMMMNs,                                      ,yMMMMMMMMMMMMMMMd/          ";
	@echo "        ,/mMMMMMMMMMMMMMMNy,                                      ,yMMMMMMMMMMMMMMMd/            ";
	@echo "      ,/mMMMMMMMMMMMMMMMy,                                      ,yNMMMMMMMMMMMMMMm/,             ";
	@echo "     /dMMMMMMMMMMMMMMMy,                                      ,sMMMMMMMMMMMMMMMm/                ";
	@echo "    sMMMMMMMMMMMMMMMMmhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhho      :NMMMMMMMMMMMMMMMy,             ,/, ";
	@echo "    yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs            ,/dM: ";
	@echo "    yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs          ,/dNMM: ";
	@echo "    yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs        ,/dMMMMM: ";
	@echo "    yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs      ,/dNMMMMMM: ";
	@echo "    yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs     /hNMMMMMMMM: ";
	@echo "    yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs  ,:hNMMMMMMMMMM: ";
	@echo "                                     +MMMMMMMMMMMMMMMMh      /MMMMMMMMMMMMMMMMs,:hNMMMMMMMMMMMM: ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh      :ddddddddddddddddoohdddddddddddddd, ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh                                          ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh                                          ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh                                          ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh                                          ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh                                          ";
	@echo "                                     ,MMMMMMMMMMMMMMMMh                                          ";
	@echo "                                     ,hhhhhhhhhhhhhhhho                                          ";

$(LIB):
	@echo "\033[0;34mTrying to board libft.a...";
	@make -C $(LIBFT)

$(NAME): $(OBJ)
	@echo "\033[0;31mSte\033[0;32mali\033[0;33mng a \033[0;34mnew\033[0;35m Ship \033[0m...";
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -L libft/ -lft -lcurses -g
	@echo "\033[0;32mShip stolen.";

%.o: %.c
	@echo "\033[0;35mLooting $<";
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@ $(MLX) -L libft/ -lft

clean:
	@echo "\033[0;36mCleaning Rhum from Cargo...";
	@make clean -C $(LIBFT)
	@$(RM) $(OBJ)
	@echo "\033[0;36mFound some fine bottles!";
fclean: clean
	@echo "\033[1;33mCleaning Gold Pieces from rich spoiled daddy's girl...";
	@make fclean -C $(LIBFT)
	@$(RM) $(NAME)
	@echo "Swimming in gold...";
re: fclean all

.PHONY: all clean fclean re

