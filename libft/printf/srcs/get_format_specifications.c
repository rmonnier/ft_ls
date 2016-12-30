/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifications_parser.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:33:30 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/08 15:12:15 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftpf_get_format_specifications(char const **format, va_list ap,
											t_specifiers *specifiers)
{
	while (ftpf_is_flag(**format) || ft_isdigit(**format) || **format == '*' ||
		**format == '.' || ftpf_is_length_specifier(**format))
	{
		if (ftpf_is_flag(**format))
			ftpf_get_flags(format, specifiers);
		else if (ft_isdigit(**format) || **format == '*')
			ftpf_get_width(format, specifiers, ap);
		else if (**format == '.')
			ftpf_get_precision(format, specifiers, ap);
		else if (ftpf_is_length_specifier(**format))
			ftpf_get_length_specifier(format, specifiers);
	}
	if (**format)
		ftpf_get_identifier(format, specifiers);
	else
		specifiers->identifier = '\0';
}
