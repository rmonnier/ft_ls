/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:30:21 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/08 19:58:21 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		ft_itoa_size(int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*output;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_itoa_size(n);
	if (!(output = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n < 0)
	{
		n = -n;
		output[0] = '-';
	}
	output[len] = '\0';
	i = len - 1;
	while (n >= 10)
	{
		output[i] = '0' + n % 10;
		n /= 10;
		i--;
	}
	output[i] = '0' + n;
	return (output);
}
