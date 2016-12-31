/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:36:21 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/22 14:00:42 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*init_files_list(char **names_list, int size, int options,
											int first)
{
	int		i;
	t_file	*begin;

	begin = NULL;
	if (size == 0)
		add_new_file("", ".", &begin);
	else
		ft_sort_tab(names_list, size, &ft_strcmp);
	i = 0;
	while (i < size)
	{
		if (add_new_file("", names_list[i], &begin) == -1)
		{
			if (first)
				ls_error(ERRNO, names_list[i]);
		}
		i++;
	}
	sort_list(&begin, options);
	return (begin);
}

int				main(int ac, char **av)
{
	int			i;
	int			options;
	t_file		*begin;
	int			no_files;

	if ((i = get_options(ac, av, &options)) == -1)
		return (1);
	av = av + i;
	ac = ac - i;
	begin = init_files_list(av, ac, options, 1);
	only_files(&begin);
	no_files = begin == NULL ? 1 : 0;
	print_list(&begin, (options | LS_D));
	free_files_list(&begin);
	begin = init_files_list(av, ac, options, 0);
	if (no_files == 0)
		print_folders(begin, options, 1, ac);
	else
		print_folders(begin, options, 2, ac);
	free_files_list(&begin);
	return (0);
}
