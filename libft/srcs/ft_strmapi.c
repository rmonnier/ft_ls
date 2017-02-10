/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:18:35 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/18 14:11:26 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	n;
	char	*output;

	i = 0;
	n = ft_strlen(s);
	if (!(output = ft_strnew(n)))
		return (NULL);
	while (i < n)
	{
		output[i] = f(i, s[i]);
		i++;
	}
	return (output);
}
