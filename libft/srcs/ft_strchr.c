/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:48:58 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/08 19:59:30 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	int		n;

	n = 0;
	while (s[n])
	{
		if (s[n] == (char)c)
			return ((char*)s + n);
		n++;
	}
	if (c == 0)
		return ((char*)s + n);
	return (NULL);
}
