/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:47:27 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/08 16:23:46 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** simple functions that identify usefull characters
*/

t_bool	ftpf_is_flag(char const c)
{
	return (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+');
}

t_bool	ftpf_is_length_specifier(char const c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L');
}

t_bool	ftpf_identifier(char const c)
{
	return (c == 'd' || c == 'D' || c == 'i' ||
			c == 'u' || c == 'U' || c == 'o' || c == 'O' ||
			c == 'x' || c == 'X' || c == 'b' || c == 'B' ||
			c == 'c' || c == 'C' || c == 's' || c == 'S' ||
			c == 'f' || c == 'F' || c == 'p' || c == '%');
}

int		ftpf_get_conv_base(char id)
{
	if (id == 'x' || id == 'X' || id == 'p')
		return (16);
	else if (id == 'u' || id == 'U' ||
				id == 'd' || id == 'D' ||
				id == 'i')
		return (10);
	else if (id == 'o' || id == 'O')
		return (8);
	else if (id == 'b' || id == 'B')
		return (2);
	return (-1);
}

void	ftpf_initialize_specifiers(t_specifiers *specifiers)
{
	specifiers->flags.sharp = 0;
	specifiers->flags.zero = 0;
	specifiers->flags.dash = 0;
	specifiers->flags.space = 0;
	specifiers->flags.plus = 0;
	specifiers->width = -1;
	specifiers->precision = -1;
	specifiers->length.h = 0;
	specifiers->length.l = 0;
	specifiers->length.j = 0;
	specifiers->length.z = 0;
	specifiers->length.f = 0;
	specifiers->identifier = 0;
}
