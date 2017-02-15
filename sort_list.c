/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 13:38:40 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/22 13:38:58 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*lst_sort_ascii(t_file *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next != NULL && ft_strcmp(lst->name, lst->next->name) > 0)
		lst = lst_swap(lst, lst->next);
	lst->next = lst_sort_ascii(lst->next);
	if (lst->next != NULL && ft_strcmp(lst->name, lst->next->name) > 0)
	{
		lst = lst_swap(lst, lst->next);
		lst->next = lst_sort_ascii(lst->next);
	}
	return (lst);
}

static t_file	*lst_sort_rev_ascii(t_file *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next != NULL && ft_strcmp(lst->name, lst->next->name) < 0)
		lst = lst_swap(lst, lst->next);
	lst->next = lst_sort_rev_ascii(lst->next);
	if (lst->next != NULL && ft_strcmp(lst->name, lst->next->name) < 0)
	{
		lst = lst_swap(lst, lst->next);
		lst->next = lst_sort_rev_ascii(lst->next);
	}
	return (lst);
}

static t_file	*lst_sort_rev_time(t_file *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next != NULL && (lst->time > lst->next->time))
		lst = lst_swap(lst, lst->next);
	else if (lst->next && lst->time == lst->next->time)
		if (lst->next && (lst->ntime < lst->next->ntime))
			lst = lst_swap(lst, lst->next);
	lst->next = lst_sort_rev_time(lst->next);
	if (lst->next != NULL && (lst->time > lst->next->time))
	{
		lst = lst_swap(lst, lst->next);
		lst->next = lst_sort_rev_time(lst->next);
	}
	else if (lst->next && lst->time == lst->next->time)
	{
		if (lst->next && (lst->ntime < lst->next->ntime))
		{
			lst = lst_swap(lst, lst->next);
			lst->next = lst_sort_rev_time(lst->next);
		}
	}
	return (lst);
}

static t_file	*lst_sort_time(t_file *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next != NULL && (lst->time < lst->next->time))
		lst = lst_swap(lst, lst->next);
	else if (lst->next && lst->time == lst->next->time)
		if (lst->next && (lst->ntime < lst->next->ntime))
			lst = lst_swap(lst, lst->next);
	lst->next = lst_sort_time(lst->next);
	if (lst->next != NULL && (lst->time < lst->next->time))
	{
		lst = lst_swap(lst, lst->next);
		lst->next = lst_sort_time(lst->next);
	}
	else if (lst->next && lst->time == lst->next->time)
	{
		if (lst->next && (lst->ntime < lst->next->ntime))
		{
			lst = lst_swap(lst, lst->next);
			lst->next = lst_sort_time(lst->next);
		}
	}
	return (lst);
}

int				sort_list(t_file **begin, int options)
{
	if (options & LS_R)
		*begin = lst_sort_rev_ascii(*begin);
	else
		*begin = lst_sort_ascii(*begin);
	if ((options & LS_T) && (options & LS_R))
		*begin = lst_sort_rev_time(*begin);
	else if (options & LS_T)
		*begin = lst_sort_time(*begin);
	return (1);
}
