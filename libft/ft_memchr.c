/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:45:26 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/08 19:34:07 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	t_byte	to_find;
	t_byte	*str;

	to_find = (t_byte)c;
	str = (t_byte*)s;
	while (n && *str != to_find)
	{
		n--;
		str++;
	}
	return (n == 0 ? NULL : (void*)str);
}
