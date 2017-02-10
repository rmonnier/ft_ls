/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:52:07 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/20 12:46:23 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_zero_cases(char **data, int *size, t_specifiers *specifiers)
{
	int	i;

	i = 0;
	while ((*data)[i])
	{
		if (ft_isdigit((*data)[i]) == 0)
			return ;
		i++;
	}
	if (specifiers->precision == 0)
	{
		**data = '\0';
		*size = 0;
	}
	if (specifiers->identifier == 'x' || specifiers->identifier == 'X')
		specifiers->flags.sharp = 0;
}

/*
** sharp flag for o, O, x, X
*/

static void	apply_sharp_flag(char **data, int *size, char id)
{
	char *tmp;

	tmp = *data;
	if (id == 'o' || id == 'O')
	{
		if (**data == '0')
			return ;
		*data = ft_strjoin("0", *data);
		*size += 1;
		free(tmp);
	}
	else if (id == 'x' || id == 'X' || id == 'p')
	{
		*data = ft_strjoin("0x", *data);
		*size += 2;
		free(tmp);
	}
}

static void	apply_precision(char **data, int *size, t_specifiers specifiers)
{
	int		precision;
	char	*to_add;
	char	*tmp;

	precision = specifiers.precision;
	tmp = *data;
	to_add = ft_strcnew(precision - *size, '0');
	*data = ft_strjoin(to_add, *data);
	*size = precision;
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
	if (specifiers.flags.zero == 0 || specifiers.precision > 0)
		to_add = ft_strcnew(width - *size, ' ');
	else if (specifiers.flags.sharp &&
			(specifiers.identifier == 'x' || specifiers.identifier == 'X' ||
			specifiers.identifier == 'p'))
	{
		(*data) += 2;
		to_add = ft_strcnew(width - *size + 2, '0');
		to_add[0] = '0';
		to_add[1] = 'x';
	}
	else
		to_add = ft_strcnew(width - *size, '0');
	*data = ft_strjoin(to_add, *data);
	*size = width;
	free(tmp);
	free(to_add);
}

void		ftpf_process_unsigned(char **data, int *size,
									t_specifiers specifiers)
{
	if (specifiers.precision > *size)
		apply_precision(data, size, specifiers);
	if (ft_atoi(*data) == 0)
		apply_zero_cases(data, size, &specifiers);
	if (specifiers.flags.sharp)
		apply_sharp_flag(data, size, specifiers.identifier);
	if (specifiers.width > *size && specifiers.flags.dash == 0)
		apply_width_nodash(data, size, specifiers);
	if (specifiers.width > *size && specifiers.flags.dash == 1)
		ftpf_apply_width_dash(data, size, specifiers.width);
	if (specifiers.identifier == 'X')
		ft_strupcase(*data);
}
