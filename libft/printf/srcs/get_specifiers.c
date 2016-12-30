/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 21:51:41 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/20 12:45:42 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** functions that get each kind of specifications through parsing
*/

void	ftpf_get_flags(char const **format, t_specifiers *specifiers)
{
	while (ftpf_is_flag(**format))
	{
		if (**format == '#')
			specifiers->flags.sharp = 1;
		if (**format == '0')
			specifiers->flags.zero = 1;
		if (**format == '-')
			specifiers->flags.dash = 1;
		if (**format == ' ')
			specifiers->flags.space = 1;
		if (**format == '+')
			specifiers->flags.plus = 1;
		(*format)++;
	}
}

void	ftpf_get_width(char const **format, t_specifiers *specifiers,
						va_list ap)
{
	if (ft_isdigit(**format))
	{
		specifiers->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		(*format)++;
		specifiers->width = va_arg(ap, int);
		if (specifiers->width < 0)
		{
			specifiers->width *= -1;
			specifiers->flags.dash = 1;
		}
	}
}

void	ftpf_get_precision(char const **format, t_specifiers *specifiers,
							va_list ap)
{
	(*format)++;
	if (ft_isdigit(**format))
	{
		specifiers->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		(*format)++;
		specifiers->precision = va_arg(ap, int);
	}
	else
		specifiers->precision = 0;
}

void	ftpf_get_length_specifier(char const **format, t_specifiers *specifiers)
{
	while (ftpf_is_length_specifier(**format))
	{
		if (**format == 'h')
			specifiers->length.h++;
		else if (**format == 'l')
			specifiers->length.l++;
		else if (**format == 'j')
			specifiers->length.j++;
		else if (**format == 'z')
			specifiers->length.z++;
		else if (**format == 'L')
			specifiers->length.f++;
		(*format)++;
	}
}

void	ftpf_get_identifier(char const **format, t_specifiers *specifiers)
{
	if (**format == 'p')
	{
		specifiers->flags.sharp = 1;
		specifiers->length.l = 1;
	}
	specifiers->identifier = **format;
	(*format)++;
}
