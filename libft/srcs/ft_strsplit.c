/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:18:36 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/18 14:16:48 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		number_of_words(char const *s, char c)
{
	int		n;

	n = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			n += 1;
			while (*s != c && *s)
				s++;
		}
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		n;
	char	**output;

	i = 0;
	n = number_of_words(s, c);
	if (!(output = (char **)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		j = 0;
		while (*s == c)
			s++;
		while (s[j] != c)
			j++;
		output[i] = ft_strndup(s, j);
		i++;
		s += j;
	}
	output[i] = 0;
	return (output);
}
