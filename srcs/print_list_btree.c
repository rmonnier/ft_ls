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

static int		print_node_standard(t_file **node)
{
	while (begin != NULL)
	{
		ft_printf("%s\n", begin->name);
		begin = begin->next;
	}
	return (1);
}

static void	btree_apply_infix_long(t_file **root, void (*applyf)(t_file *node, int size[6]))
{
	if (root == 0)
	return ;
	if (root->left != 0)
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	if (root->right != 0)
	btree_apply_infix(root->right, applyf);
}

static int		print_btree_long(t_file **root, int options)
{
	int	size[6];
	int	total;
	int	first;

	ft_bzero(size, sizeof(size));
	total = 0;
	first = 1;
	get_fields_size(root, size, &total);
	if (root && *root && !(options & LS_D))
		ft_printf("total %d\n", total);
	btree_apply_infix_long(root, &print_long_format);
	return (1);
}


int				print_list(t_file **root, int options)
{
	if (options & LS_L)
		print_btree_long(root, options);
	else
		btree_apply_infix(root, &print_node_standard;
	return (1);
}
