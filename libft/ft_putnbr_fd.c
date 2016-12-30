/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 22:13:51 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/30 20:05:16 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_aux(int n, int fd)
{
	if (n <= -10)
		ft_putnbr_fd_aux(n / 10, fd);
	ft_putchar_fd(-(n % 10) + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n >= 0)
		n = -n;
	ft_putnbr_fd_aux(n, fd);
}
