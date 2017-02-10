/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:56:58 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/08 16:11:51 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** main part of the string formatting function
*/

static char	*get_formated_string(const char **format, va_list ap,
									int *size, int n)
{
	t_specifiers	specifiers;
	char			*s;

	ftpf_initialize_specifiers(&specifiers);
	ftpf_get_format_specifications(format, ap, &specifiers);
	s = ftpf_get_raw_data(ap, specifiers, size, n);
	if (s != NULL)
		ftpf_process_data(&s, size, specifiers);
	return (s);
}

/*
** main part of the function
*/

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*s;
	int		size;
	int		n;

	n = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format++);
		else
		{
			format++;
			if ((s = get_formated_string(&format, ap, &size, n)) == NULL)
				return (-1);
			write(1, s, size);
			n = n + size - 1;
			free(s);
		}
		n++;
	}
	va_end(ap);
	return (n);
}
