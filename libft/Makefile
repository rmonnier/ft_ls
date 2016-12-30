# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 10:17:46 by rmonnier          #+#    #+#              #
#    Updated: 2016/11/28 15:16:18 by rmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =				ft_atoi.c\
					ft_bzero.c\
					ft_isalnum.c\
					ft_isalpha.c\
					ft_isascii.c\
					ft_isdigit.c\
					ft_islower.c\
					ft_isprint.c\
					ft_isspace.c\
					ft_isupper.c\
					ft_iswhite.c\
					ft_itoa.c\
					ft_itoa_base.c\
					ft_lstadd.c\
					ft_lstdel.c\
					ft_lstdelone.c\
					ft_lstiter.c\
					ft_lstmap.c\
					ft_lstnew.c\
					ft_memalloc.c\
					ft_memccpy.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_memcpy.c\
					ft_memdel.c\
					ft_memmove.c\
					ft_memset.c\
					ft_print_memory.c\
					ft_putchar.c\
					ft_putchar_fd.c\
					ft_putendl.c\
					ft_putendl_fd.c\
					ft_putnbr.c\
					ft_putnbr_fd.c\
					ft_putstr.c\
					ft_putstr_fd.c\
					ft_split_whitespaces.c\
					ft_strcat.c\
					ft_strchr.c\
					ft_strclr.c\
					ft_strcmp.c\
					ft_strcpy.c\
					ft_strcnew.c\
					ft_strdel.c\
					ft_strdup.c\
					ft_strequ.c\
					ft_striter.c\
					ft_striteri.c\
					ft_strjoin.c\
					ft_strlcat.c\
					ft_strlen.c\
					ft_strlowcase.c\
					ft_strmap.c\
					ft_strmapi.c\
					ft_strncat.c\
					ft_strncmp.c\
					ft_strncpy.c\
					ft_strndup.c\
					ft_strnequ.c\
					ft_strnew.c\
					ft_strnstr.c\
					ft_strrchr.c\
					ft_strsplit.c\
					ft_strstr.c\
					ft_strsub.c\
					ft_strtrim.c\
					ft_strupcase.c\
					ft_swap.c\
					ft_tolower.c\
					ft_toupper.c\
					get_next_line.c
OBJ_NAME		=		$(SRCS:.c=.o)
OBJ_PATH		=		obj/
OBJ			=		$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC			=		./includes/
NAME			=		libft.a
FLAG			=		-Wall -Werror -Wextra

$(NAME): $(OBJ)
	make -C printf/
	cp printf/printf.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir -p obj
	gcc -c $(FLAG) -I $(INC) $< -o $@

clean:
	make -C printf/ fclean
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
