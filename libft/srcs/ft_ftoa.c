/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_lld.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:08:23 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/16 18:41:59 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_ftoa_before_dot(long double value)
{
	int			i;
	intmax_t	n;

	n = (intmax_t)value;
	i = 1;
	while ((n / 10) != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	fill_str_ftoa(long double value, char *str, int size, int precision)
{
	int			i;
	intmax_t	n;

	n = 1;
	i = size - 1;
	while ((intmax_t)(value / n) != 0)
	{
		str[i] = '0' + (intmax_t)(value / n) % 10;
		i--;
		n *= 10;
	}
	str[size] = '.';
	value = (value - (long double)(intmax_t)value) * 100;
	i = 0;
	while (i < precision)
	{
		str[size + 1 + i++] = '0' + (intmax_t)(value + 0.5) / 10 % 10;
		value *= 10;
	}
}

char		*ft_ftoa(long double value, int precision)
{
	char	*ftoa;
	int		size;

	if (precision == -1)
		precision = 6;
	size = size_ftoa_before_dot(value);
	if ((intmax_t)value < 0)
		size++;
	if (!(ftoa = (char*)ft_memalloc(sizeof(char) * (size + precision + 2))))
		return (NULL);
	if ((intmax_t)value < 0)
	{
		ftoa[0] = '-';
		value = -value;
	}
	ftoa[size + precision + 1] = '\0';
	fill_str_ftoa(value, ftoa, size, precision);
	return (ftoa);
}
