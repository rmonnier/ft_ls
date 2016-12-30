/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_characters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:58:58 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/20 12:44:29 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** data conversion for c, C, s, S
*/

static char	*get_arg_c(va_list ap, int *size)
{
	char	arg;
	char	*output;

	arg = (char)va_arg(ap, int);
	output = ft_strndup(&arg, 1);
	*size = 1;
	return (output);
}

static char	*get_arg_s(va_list ap, int *size)
{
	char	*arg;
	char	*output;

	arg = (char*)va_arg(ap, char*);
	if (arg != NULL)
		output = ft_strdup(arg);
	else
		output = ft_strdup("(null)");
	*size = ft_strlen(output);
	return (output);
}

static char	*get_arg_lc(va_list ap, int *size)
{
	wint_t	arg;
	char	*output;

	arg = (wint_t)va_arg(ap, wint_t);
	if ((output = ft_unicode_encoder(arg)) == NULL)
		return (NULL);
	if ((*size = ft_strlen(output)) == 0)
		*size = 1;
	return (output);
}

static char	*get_arg_ls(va_list ap, int *size)
{
	wchar_t	*arg;
	char	*output;

	arg = (wchar_t*)va_arg(ap, wchar_t*);
	if (arg != NULL)
	{
		if ((output = ft_unicode_encoder_string(arg)) == NULL)
			return (NULL);
	}
	else
		output = ft_unicode_encoder_string(L"(null)");
	*size = ft_strlen(output);
	return (output);
}

char		*ftpf_convert_characters(va_list ap, t_specifiers specifiers,
									int *size)
{
	char	*s;

	if (specifiers.identifier == 'C' ||
				(specifiers.identifier == 'c' && specifiers.length.l == 1))
		s = get_arg_lc(ap, size);
	else if (specifiers.identifier == 'S' ||
				(specifiers.identifier == 's' && specifiers.length.l == 1))
		s = get_arg_ls(ap, size);
	else if (specifiers.identifier == 'c')
		s = get_arg_c(ap, size);
	else if (specifiers.identifier == 's')
		s = get_arg_s(ap, size);
	return (s);
}
