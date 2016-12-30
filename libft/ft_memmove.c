/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:59:54 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/08 18:30:34 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	t_byte	*d;
	t_byte	*s;

	if (dst > src)
	{
		d = (t_byte*)dst + len;
		s = (t_byte*)src + len;
		while (len-- > 0)
			*--d = *--s;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
