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

int	free_files_list(t_file **begin)
{
	t_file	*tmp;

	tmp = *begin;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		ft_memdel((void**)&((*begin)->name));
		ft_memdel((void**)begin);
		*begin = tmp;
	}
	return (1);
}
