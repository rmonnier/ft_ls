/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:36:21 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/12 14:38:14 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_flags(char *str, int *options)
{
	while (*(++str))
	{
		if (*str == 'a')
			*options = *options | LS_A;
		else if (*str == 'l')
			*options = *options | LS_L;
		else if (*str == 'R')
			*options = *options | LS_RR;
		else if (*str == 'r')
			*options = *options | LS_R;
		else if (*str == 't')
			*options = *options | LS_T;
		else if (*str == 'd')
			*options = *options | LS_D;
		else
		{
			ls_error(USAGE, str);
			return (0);
		}
	}
	return (1);
}

int			get_options(int ac, char **av, int *options)
{
	int	i;

	*options = 0;
	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] != '\0')
	{
		if (av[i][1] == '-' && av[i][2] == '\0')
			return (i + 1);
		if (!get_flags(av[i], options))
			return (-1);
		i++;
	}
	return (i);
}
