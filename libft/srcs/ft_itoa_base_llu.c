/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_llu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:09:32 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/08 16:20:14 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		convert_number_to_base_component(int number)
{
	char *base;

	base = "0123456789abcdef";
	return (base[number]);
}

static int		size_itoa(uintmax_t value, int base)
{
	int		i;

	i = 1;
	while ((value / base) != 0)
	{
		value = value / base;
		i++;
	}
	return (i);
}

static void		fill_str_itoa_base(uintmax_t value, int base, char *str, int i)
{
	while ((value / base) != 0)
	{
		str[i] = convert_number_to_base_component(value % base);
		i--;
		value = value / base;
	}
	str[i] = convert_number_to_base_component(value % base);
}

char			*ft_itoa_base_llu(uintmax_t value, int base)
{
	char	*itoa;
	int		size;

	if (base < 2 || base > 16)
		return (NULL);
	size = size_itoa(value, base);
	if (!(itoa = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	itoa[size] = '\0';
	fill_str_itoa_base(value, base, itoa, size - 1);
	return (itoa);
}
