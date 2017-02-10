/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:52:34 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/03 19:09:11 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	size_t			i;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	if (big[0] == '\0')
		return (NULL);
	if (big[0] != little[0])
		return (ft_strstr(big + 1, little));
	while (big[i] == little[i])
	{
		if (little[i + 1] == '\0')
			return ((char*)big);
		i++;
	}
	return (ft_strstr(big + 1, little));
}
