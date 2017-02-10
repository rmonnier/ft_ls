/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:28:03 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/18 14:16:34 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	char	*output;

	while (*s && ft_iswhite(*s))
		s++;
	n = 0;
	while (s[n])
		n++;
	if (n != 0)
	{
		n--;
		while (ft_iswhite(s[n]))
			n--;
		n++;
	}
	if (!(output = ft_strnew(n)))
		return (NULL);
	i = -1;
	while (++i < n)
		output[i] = s[i];
	return (output);
}
