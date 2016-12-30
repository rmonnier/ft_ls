/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:05:36 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/16 18:41:15 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** data conversion for F, f
*/

static long double	get_arg(va_list ap, t_length length)
{
	long double output;

	if (length.f >= 1)
		output = va_arg(ap, long double);
	else
		output = (long double)va_arg(ap, double);
	return (output);
}

char				*ftpf_convert_float(va_list ap, t_specifiers specifiers,
									int *size)
{
	long double	arg;
	int			base;
	char		*s;

	arg = get_arg(ap, specifiers.length);
	s = ft_ftoa(arg, specifiers.precision);
	*size = ft_strlen(s);
	return (s);
}
