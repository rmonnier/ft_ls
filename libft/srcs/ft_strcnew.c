/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:26:51 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/16 16:23:59 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strcnew(size_t size, char c)
{
	char	*output;

	if (!(output = (char*)malloc(size + 1)))
		return (NULL);
	ft_memset(output, c, size);
	output[size] = '\0';
	return (output);
}
