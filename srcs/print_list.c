/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 13:38:29 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/22 13:38:31 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		print_list_standard(t_file *begin, int options)
{
	while (begin != NULL)
	{
		ft_printf("%s\n", begin->name);
		begin = begin->next;
	}
	return (1);
}

static int		print_list_long(t_file *begin, int options)
{
	int	size[6];
	int	total;
	int	first;

	ft_bzero(size, sizeof(size));
	total = 0;
	first = 1;
	get_fields_size(begin, size, &total);
	while (begin != NULL)
	{
		if (first == 1 && !(options & LS_D))
		{
			ft_printf("total %d\n", total);
			first = 0;
		}
		print_long_format(begin, options, size);
		begin = begin->next;
	}
	return (1);
}

int				print_list(t_file **begin, int options)
{
	sort_list(begin, options);
	if (options & LS_L)
		print_list_long(*begin, options);
	else
		print_list_standard(*begin, options);
	return (1);
}
