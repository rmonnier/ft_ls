/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:52:07 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/08 18:50:59 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** data conversion for d, D, i
*/

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

static void	apply_precision(char **data, int *size, t_specifiers specifiers)
{
	int		precision;
	char	*to_add;
	char	*tmp;

	precision = specifiers.precision;
	if ((precision <= *size && **data != '-') || precision <= *size - 1)
		return ;
	tmp = *data;
	if (**data != '-')
	{
		to_add = ft_strcnew(precision - *size, '0');
		*size = precision;
	}
	else
	{
		(*data) += 1;
		to_add = ft_strcnew(precision - *size + 2, '0');
		to_add[0] = '-';
		*size = precision + 1;
	}
	*data = ft_strjoin(to_add, *data);
	free(tmp);
	free(to_add);
}

static void	apply_width_nodash(char **data, int *size, t_specifiers specifiers)
{
	int		width;
	char	*to_add;
	char	*tmp;

	width = specifiers.width;
	tmp = *data;
	if (specifiers.flags.zero == 0 || specifiers.precision >= 0)
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

void		ftpf_apply_width_dash(char **data, int *size, int width)
{
	char	*tmp;

	tmp = *data;
	*data = ft_strcnew(width, ' ');
	ft_strncpy(*data, tmp, *size);
	*size = width;
	free(tmp);
}

void		ftpf_process_signed(char **data, int *size, t_specifiers specifiers)
{
	if (specifiers.precision > 0)
		apply_precision(data, size, specifiers);
	if (specifiers.precision == 0 && ft_atoi(*data) == 0)
	{
		**data = '\0';
		*size = 0;
	}
	if ((specifiers.flags.space || specifiers.flags.plus))
		apply_plus_space_flag(data, size, specifiers.flags);
	if (specifiers.width > *size && specifiers.flags.dash == 0)
		apply_width_nodash(data, size, specifiers);
	if (specifiers.width > *size && specifiers.flags.dash == 1)
		ftpf_apply_width_dash(data, size, specifiers.width);
}
