/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:55:29 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/26 17:58:54 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	putnbr_hex(unsigned char octet, int i)
{
	char *base;

	base = "0123456789abcdef";
	if (i == 1)
	{
		putnbr_hex(octet >> 4, 0);
		write(1, base + octet % 16, 1);
	}
	else
		write(1, base + octet % 16, 1);
}

static void	print_characters(unsigned char *addr, size_t size, unsigned int i)
{
	unsigned int	a;
	unsigned char	c;

	a = 0;
	while (a < 16 && a + i < size)
	{
		c = *(addr + a + i);
		if (c >= 32 && c <= 126)
		{
			write(1, &c, 1);
		}
		else
			write(1, ".", 1);
		a++;
	}
}

static void	print_number(unsigned char *addr, size_t size, unsigned int i)
{
	unsigned int a;

	a = 0;
	while (a < 16 && a + i < size)
	{
		putnbr_hex(*(addr + i + a), 1);
		if (a % 2 == 1)
			write(1, " ", 1);
		a++;
	}
	while (a < 16)
	{
		write(1, "  ", 2);
		if (a % 2 == 1)
			write(1, " ", 1);
		a++;
	}
}

void		ft_print_memory(const void *addr, size_t size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		print_number((unsigned char*)addr, size, i);
		print_characters((unsigned char *)addr, size, i);
		write(1, "\n", 1);
		i = i + 16;
	}
}
