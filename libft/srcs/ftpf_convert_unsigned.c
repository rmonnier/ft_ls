/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:08:02 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/08 16:08:04 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** data conversion for o, O, u, U, x, X, b, B
*/

static uintmax_t	get_arg(va_list ap, char id, t_length length)
{
	uintmax_t output;

	if (length.l >= 2)
		output = (uintmax_t)va_arg(ap, unsigned long long);
	else if (length.l == 1 || id == 'U' || id == 'O' || id == 'B')
		output = (uintmax_t)va_arg(ap, unsigned long);
	else if (length.z >= 1)
		output = (uintmax_t)va_arg(ap, size_t);
	else if (length.j >= 1)
		output = va_arg(ap, uintmax_t);
	else if (length.h >= 2)
		output = (uintmax_t)(unsigned char)va_arg(ap, unsigned int);
	else if (length.h == 1)
		output = (uintmax_t)(unsigned short)va_arg(ap, unsigned int);
	else
		output = (uintmax_t)va_arg(ap, unsigned int);
	return (output);
}

char				*ftpf_convert_unsigned(va_list ap, t_specifiers specifiers,
									int *size)
{
	uintmax_t	arg;
	int			base;
	char		*s;

	arg = get_arg(ap, specifiers.identifier, specifiers.length);
	base = ftpf_get_conv_base(specifiers.identifier);
	s = ft_itoa_base_llu(arg, base);
	*size = ft_strlen(s);
	return (s);
}
