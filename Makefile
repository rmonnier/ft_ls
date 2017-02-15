# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 10:17:46 by rmonnier          #+#    #+#              #
#    Updated: 2017/02/14 20:07:39 by rmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		add_new_file.c\
					free_files_list.c\
					ft_sort_tab.c\
					get_fields_size.c\
					get_options.c\
					ls_error.c\
					lst_swap.c\
					main.c\
					only_files.c\
					print_folders.c\
					print_list.c\
					print_long_format.c\
					sort_list.c
OBJ_NAME			=		$(SRCS:.c=.o)
OBJ_PATH			=		obj/
OBJ					=		$(addprefix $(OBJ_PATH), $(OBJ_NAME))
NAME				=		ft_ls
FLAGS				=		-Wall -Werror -Wextra
INC					=		-I./includes/


.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) $(INC) -L ./libft/ -lft -o $(NAME) $(OBJ)

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir -p obj
	gcc -c $(FLAGS) $< $(INC) -o $@

clean:
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
