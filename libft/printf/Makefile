# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 10:17:46 by rmonnier          #+#    #+#              #
#    Updated: 2016/12/22 15:09:47 by rmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAME		=		ft_printf.c\
							convert_characters.c\
							convert_float.c\
							convert_signed.c\
							convert_unsigned.c\
							get_format_specifications.c\
							ft_itoa_base_lld.c\
							ft_itoa_base_llu.c\
							ft_ftoa.c\
							ft_unicode_encoder.c\
							ft_unicode_encoder_string.c\
							get_raw_data.c\
							get_specifiers.c\
							process_characters.c\
							process_data.c\
							process_float.c\
							process_signed.c\
							process_unsigned.c\
							tools.c\
							tools_is_functions.c
SRCS_PATH		=		srcs/
SRCS			=		$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME		=		$(SRCS_NAME:.c=.o)
OBJ_PATH		=		obj/
OBJ				=		$(addprefix $(OBJ_PATH), $(OBJ_NAME))
NAME			=		printf.a
FLAG			=		-Wall -Werror -Wextra
INC				=		./includes/


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) -I $(INC) $< -o $@

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
