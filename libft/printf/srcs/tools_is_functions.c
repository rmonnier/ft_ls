/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:47:27 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/08 18:50:40 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** function that select a method to get the data
*/

t_bool	ftpf_is_unsigned_conv(char c)
{
	return (c == 'u' || c == 'U' || c == 'o' || c == 'O' ||
			c == 'x' || c == 'X' ||
			c == 'b' || c == 'B' || c == 'p');
}

t_bool	ftpf_is_signed_conv(char c)
{
	return (c == 'd' || c == 'D' || c == 'i');
}

t_bool	ftpf_is_characters_conv(char c)
{
	return (c == 'c' || c == 'C' || c == 's' || c == 'S');
}

t_bool	ftpf_is_float_conv(char c)
{
	return (c == 'f' || c == 'F');
}
