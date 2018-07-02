# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcollard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:23:24 by tcollard          #+#    #+#              #
#    Updated: 2018/04/04 17:01:57 by tcollard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = fillit

CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -Llibft
LDLIBS = -lft

PATH_SRC = ./srcs/
PATH_OBJ = ./obj/

NAME_SRC = fct_tab.c \
		   ft_sqrt.c \
		   ref0_4.c \
		   ref5_9.c \
		   ref10_14.c \
		   ref15_18.c \
		   tetris_display.c \
		   pass_char.c \
		   tetris.c \
		   tetris_fill.c \
		   ft_memdel2.c \
		   ft_check_file.c \
		   ft_error.c \
		   ft_lib_tetri.c \
		   ft_lst_check.c \
		   ft_lst_tetri.c \
		   main.c

NAME_OBJ = $(NAME_SRC:.c=.o)

SRC = $(addprefix $(PATH_SRC),$(NAME_SRC))
OBJ = $(addprefix $(PATH_OBJ),$(NAME_OBJ))

all: $(NAME)

$(NAME): $(OBJ)
	@cd ./libft && make
	gcc $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(PATH_OBJ)%.o : $(PATH_SRC)%.c
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	gcc $(CFLAGS) -I includes -o $@ -c $<
	
clean:
	@cd ./libft && make clean
	/bin/rm -fv $(OBJ)
	@rmdir $(PATH_OBJ) 2> /dev/null || true

fclean: clean
	@cd ./libft && make fclean
	/bin/rm -fv $(NAME) debug

re: fclean all

norme :
	norminette $(SRC)
	norminette ./includes/*.h

debug : $(OBJ)
	make -C ./libft
	gcc $(CFLAGS) $(LDFLAGS) $(LDLIBS) -fsanitize=address -g3 $^ -o $@
