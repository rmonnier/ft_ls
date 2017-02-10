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

static void	btree_free_node(t_file **node)
{
	ft_memdel((void**)&((*node)->name));
	ft_memdel((void**)node);
}

void	free_files_btree(t_file **root)
{
	btree_apply_infix(t_file **root, &btree_free_node)
}
