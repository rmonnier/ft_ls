/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:00:39 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/07 19:16:39 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	size_t	i;
	t_byte	*data1;
	t_byte	*data2;

	data1 = (t_byte*)s1;
	data2 = (t_byte*)s2;
	i = 0;
	while (i < n)
	{
		if (data1[i] != data2[i])
			return (data1[i] - data2[i]);
		i++;
	}
	return (0);
}
