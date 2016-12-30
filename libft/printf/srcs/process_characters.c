/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:39:04 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/20 12:45:18 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	octets_to_print(char *str)
{
	t_byte	octet;

	octet = (t_byte)*str;
	if ((octet & 128) == 0)
		return (1);
	if ((octet & 224) == 192)
		return (2);
	if ((octet & 240) == 224)
		return (3);
	if ((octet & 248) == 240)
		return (4);
	return (0);
}

static void	apply_precision(char **data, int *size, t_specifiers specifiers)
{
	int	to_print;
	int	i;

	if ((specifiers.identifier == 'c' || specifiers.identifier == 'C'))
		return ;
	if (specifiers.identifier == 'S')
	{
		i = 0;
		to_print = 0;
		while (to_print + i <= specifiers.precision)
		{
			to_print += i;
			i = octets_to_print(*data + to_print);
		}
		(*data)[to_print] = '\0';
		*size = to_print;
	}
	else
	{
		(*data)[specifiers.precision] = '\0';
		*size = specifiers.precision;
	}
}

static void	apply_width(char **data, int *size, t_specifiers specifiers)
{
	int		width;
	char	*to_add;
	char	*tmp;

	width = specifiers.width;
	if (width > *size)
	{
		tmp = *data;
		if (specifiers.flags.zero == 0 || specifiers.flags.dash)
			*data = ft_strcnew(width, ' ');
		else
			*data = ft_strcnew(width, '0');
		if (specifiers.flags.dash == 0)
			ft_strncpy(*data + width - *size, tmp, *size);
		else
			ft_strncpy(*data, tmp, *size);
		*size = width;
		free(tmp);
	}
}

void		ftpf_process_characters(char **data, int *size,
									t_specifiers specifiers)
{
	if (specifiers.precision > -1 && specifiers.precision < *size)
		apply_precision(data, size, specifiers);
	if (specifiers.width > 0)
		apply_width(data, size, specifiers);
}
