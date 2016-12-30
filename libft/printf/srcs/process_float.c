/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:52:07 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/15 20:26:56 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	remove_dot(char **data, int *size)
{
	if ((*data)[*size - 1] == '.')
	{
		(*data)[*size - 1] = '\0';
		*size = *size - 1;
	}
}

static void	apply_plus_space_flag(char **data, int *size, t_flags flags)
{
	char *tmp;

	if (**data != '-')
	{
		tmp = *data;
		if (flags.plus)
			*data = ft_strjoin("+", *data);
		else
			*data = ft_strjoin(" ", *data);
		*size += 1;
		free(tmp);
	}
}

static void	apply_width_nodash(char **data, int *size, t_specifiers specifiers)
{
	int		width;
	char	*to_add;
	char	*tmp;

	width = specifiers.width;
	tmp = *data;
	if (specifiers.flags.zero == 0)
		to_add = ft_strcnew(width - *size, ' ');
	else if (**data != '-' && **data != ' ' && **data != '+')
		to_add = ft_strcnew(width - *size, '0');
	else
	{
		to_add = ft_strcnew(width - *size + 1, '0');
		to_add[0] = **data;
		(*data) += 1;
	}
	*data = ft_strjoin(to_add, *data);
	*size = width;
	free(tmp);
	free(to_add);
}

void		ftpf_process_float(char **data, int *size, t_specifiers specifiers)
{
	if ((specifiers.flags.space || specifiers.flags.plus))
		apply_plus_space_flag(data, size, specifiers.flags);
	if (!specifiers.flags.sharp)
		remove_dot(data, size);
	if (specifiers.width > *size && specifiers.flags.dash == 0)
		apply_width_nodash(data, size, specifiers);
	if (specifiers.width > *size && specifiers.flags.dash == 1)
		ftpf_apply_width_dash(data, size, specifiers.width);
}
