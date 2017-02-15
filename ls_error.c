/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 20:43:24 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/13 15:11:17 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		errno_display(char *str)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
}

static void		usage_display(char *str)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(*str, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ft_ls [-Ralrt] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

int				ls_error(int error, char *str)
{
	if (error == ERRNO)
		errno_display(str);
	else if (error == USAGE)
		usage_display(str);
	else if (error == MALL_ERR)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
