/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_encoder_string.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:14:31 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/08 16:15:06 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unicode_encoder_string(wchar_t *unicode_str)
{
	char	*encoding;
	char	*to_add;
	char	*tmp;

	encoding = ft_strdup("");
	while (*unicode_str)
	{
		if ((to_add = ft_unicode_encoder((wint_t)(*unicode_str))) == NULL)
			return (NULL);
		tmp = encoding;
		encoding = ft_strjoin(encoding, to_add);
		free(to_add);
		free(tmp);
		unicode_str++;
	}
	return (encoding);
}
