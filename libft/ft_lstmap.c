/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:52:43 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/18 14:30:35 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*output;
	t_list		*t1;
	t_list		*t2;

	t1 = (f)(lst);
	if (!(output = ft_lstnew(t1->content, t1->content_size)))
		return (NULL);
	t2 = output;
	lst = lst->next;
	while (lst)
	{
		t1 = (f)(lst);
		if (!(t2->next = ft_lstnew(t1->content, t1->content_size)))
			return (NULL);
		t2 = t2->next;
		lst = lst->next;
	}
	return (output);
}
