# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 10:17:46 by rmonnier          #+#    #+#              #
#    Updated: 2017/02/09 17:56:20 by rmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAME =		ft_atoi.c\
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


SRCS_NAME_PF		=		ft_printf.c\
							ftpf_convert_characters.c\
							ftpf_convert_float.c\
							ftpf_convert_signed.c\
							ftpf_convert_unsigned.c\
							ftpf_get_format_specifications.c\
							ft_itoa_base_lld.c\
							ft_itoa_base_llu.c\
							ft_ftoa.c\
							ft_unicode_encoder.c\
							ft_unicode_encoder_string.c\
							ftpf_get_raw_data.c\
							ftpf_get_specifiers.c\
							ftpf_process_characters.c\
							ftpf_process_data.c\
							ftpf_process_float.c\
							ftpf_process_signed.c\
							ftpf_process_unsigned.c\
							ftpf_tools.c\
							ftpf_tools_is_functions.c

SRCS_PATH		=		srcs/
SRCS			=		$(addprefix $(SRCS_PATH), $(SRCS_NAME))
SRCS_PF		=		$(addprefix $(SRCS_PATH), $(SRCS_NAME_PF))
OBJ_NAME		=		$(SRCS_NAME:.c=.o)
OBJ_NAME_PF =		$(SRCS_NAME_PF:.c=.o)
OBJ_PATH		=		obj/
OBJ			=		$(addprefix $(OBJ_PATH), $(OBJ_NAME))
OBJ_PF		=		$(addprefix $(OBJ_PATH), $(OBJ_NAME_PF))
INC			=		./includes/
NAME			=		libft.a
FLAG			=		-Wall -Werror -Wextra


$(NAME): $(OBJ) $(OBJ_PF)
	ar rc $(NAME) $(OBJ) $(OBJ_PF)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAG) -I $(INC) $< -o $@

all: $(NAME)


clean:
	/bin/rm -f $(OBJ) $(OBJ_PF)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
