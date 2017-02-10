/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:35:04 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/08 18:49:17 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	while (n--)
	{
		*(t_byte *)dst++ = *(t_byte *)src;
		if (*(t_byte *)src++ == (t_byte)c)
			return (dst);
	}
	return (NULL);
}
