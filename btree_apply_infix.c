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

void	btree_apply_infix(t_file **root, void (*applyf)(t_file **node))
{
	if (root == 0)
		return ;
	if (root->left != 0)
		btree_apply_infix(root->left, applyf);
	applyf(root->item);
	if (root->right != 0)
		btree_apply_infix(root->right, applyf);
}
