/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:36:21 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/22 19:19:12 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		lst_delone(t_file **file)
{
	ft_memdel((void**)&(*file)->name);
	ft_memdel((void**)file);
}

void			only_files(t_file **begin, int options)
{
	t_file	*tmp;

	tmp = *begin;
	while (tmp != NULL && S_ISDIR(tmp->mode))
	{
		tmp = tmp->next;
		lst_delone(begin);
		*begin = tmp;
	}
	if (tmp != NULL)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		if (S_ISDIR(tmp->mode))
		{
			(*begin)->next = tmp->next;
			lst_delone(&tmp);
			tmp = (*begin)->next;
		}
		else
		{
			tmp = tmp->next;

			begin = &((*begin)->next);
		}
	}
}
