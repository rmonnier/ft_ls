/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:20:44 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/20 12:44:59 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*n_conv(va_list ap, t_length length, int *size, int n)
{
	char	*s;

	if (length.l >= 2)
		*(va_arg(ap, long long*)) = (long long)n;
	else if (length.l == 1)
		*(va_arg(ap, long*)) = (long)n;
	else if (length.z >= 1)
		*(va_arg(ap, intmax_t*)) = (intmax_t)n;
	else if (length.j >= 1)
		*(va_arg(ap, intmax_t*)) = (ssize_t)n;
	else if (length.h >= 2)
		*(va_arg(ap, char*)) = (char)n;
	else if (length.h == 1)
		*(va_arg(ap, short*)) = (short)n;
	else
		*(va_arg(ap, int*)) = n;
	s = ft_strdup("");
	*size = 0;
	return (s);
}

char		*ftpf_get_raw_data(va_list ap, t_specifiers specifiers,
								int *size, int n)
{
	char	*s;

	if (ftpf_is_unsigned_conv(specifiers.identifier))
		s = ftpf_convert_unsigned(ap, specifiers, size);
	else if (ftpf_is_signed_conv(specifiers.identifier))
		s = ftpf_convert_signed(ap, specifiers, size);
	else if (ftpf_is_characters_conv(specifiers.identifier))
		s = ftpf_convert_characters(ap, specifiers, size);
	else if (specifiers.identifier == 'n')
		s = n_conv(ap, specifiers.length, size, n);
	else if (ftpf_is_float_conv(specifiers.identifier))
		s = ftpf_convert_float(ap, specifiers, size);
	else
	{
		s = ft_strndup(&(specifiers.identifier), 1);
		*size = ft_strlen(s);
	}
	return (s);
}
