/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fields_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 13:53:47 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/22 13:53:56 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		size_itoa(int value)
{
	int		i;

	i = 1;
	while ((value / 10) != 0)
	{
		value = value / 10;
		i++;
	}
	return (i);
}

static int		fill_size(int size[6], t_file *file)
{
	int	len;

	if ((len = size_itoa(file->st_nlink)) > size[0])
		size[0] = len;
	if ((len = ft_strlen(getpwuid(file->st_uid)->pw_name)) > size[1])
		size[1] = len;
	if ((len = ft_strlen(getgrgid(file->st_gid)->gr_name)) > size[2])
		size[2] = len;
	if (!S_ISCHR(file->mode))
		len = size_itoa(file->st_size);
	else
	{
		if ((len = size_itoa(major(file->st_rdev))) > size[4])
			size[4] = len;
		if ((len = size_itoa(minor(file->st_rdev))) > size[5])
			size[5] = len;
		len = size[4] + 2 + size[5];
	}
	if (len > size[3])
		size[3] = len;
	return (1);
}

int				get_fields_size(t_file *begin, int size[6], int *total)
{
	size[4] = 3;
	size[5] = 3;
	while (begin != NULL)
	{
		fill_size(size, begin);
		*total += begin->st_blocks;
		begin = begin->next;
	}
	if (size[4] + size[5] + 1 < size[3])
		size[4] = size[3] - size[5] - 1;
	return (1);
}
