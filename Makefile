# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/17 16:22:40 by srepelli     #+#   ##    ##    #+#        #
#    Updated: 2018/07/18 10:27:40 by srepelli    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

SRCPATH1 = ./checker_src/

SRCPATH2 = ./push_swap_src/

SRCS1 = checker.c \
		moves.c \
		movelist1.c \
		movelist2.c \
		movelist3.c \
		error_check.c \
		visualizer.c \
		main1.c

SRCS2 = moveprint1.c \
		moveprint2.c \
		moveprint3.c \
		movelist1.c \
		movelist2.c \
		movelist3.c \
		push_swap.c \
		quicksort.c \
		simplesort.c \
		main2.c \
		error_check.c \
		sortb.c

FLAGS = -Wall -Wextra -Werror

OBJ1 = $(SRCS1:.c=.o)

OBJ2 = $(SRCS2:.c=.o)

HEAD = -I ./

LIBPATH = ./libft/

LIB = libft.a

.PHONY : all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1): $(LIBPATH)$(LIB) $(OBJ1)
	gcc $(FLAGS) $(HEAD) $(LIBPATH)$(LIB) $(OBJ1) -o $(NAME1)

$(NAME2): $(LIBPATH)$(LIB) $(OBJ2)
	gcc $(FLAGS) $(HEAD) $(LIBPATH)$(LIB) $(OBJ2) -o $(NAME2)

$(LIBPATH)$(LIB):
	$(MAKE) -C $(LIBPATH)

%.o: $(SRCPATH1)%.c
	gcc $(FLAGS) $(HEAD) -c $< -o $@

%.o: $(SRCPATH2)%.c
	gcc $(FLAGS) $(HEAD) -c $< -o $@

clean:
	/bin/rm -f $(OBJ1) $(OBJ2)
	$(MAKE) fclean -C $(LIBPATH)
	$(MAKE) fclean -C $(LIBPATH)$(PFPATH)

fclean: clean
	/bin/rm -f $(NAME1) $(NAME2)

re: fclean all
