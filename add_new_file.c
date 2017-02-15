/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:36:21 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/22 13:18:19 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		get_full_path(char path[PATH_MAX], char *name,
								char full_path[PATH_MAX])
{
	int	i;

	i = 0;
	while (path[i])
	{
		full_path[i] = path[i];
		i++;
	}
	if (i != 0 && i < PATH_MAX)
	{
		if (!(path[0] == '/' && path[1] == '\0'))
			full_path[i++] = '/';
	}
	while (*name && i < PATH_MAX)
		full_path[i++] = *name++;
	if (i < PATH_MAX)
		full_path[i] = '\0';
	if (i < PATH_MAX)
		return (1);
	else
	{
		errno = ENAMETOOLONG;
		return (0);
	}
}

static t_file	*new_file(char path[PATH_MAX], char *name, t_stat *stat)
{
	t_file	*new;

	if (!(new = (t_file*)ft_memalloc(sizeof(t_file))))
		ls_error(MALL_ERR, NULL);
	new->mode = stat->st_mode;
	new->st_nlink = stat->st_nlink;
	new->st_uid = stat->st_uid;
	new->st_gid = stat->st_gid;
	new->st_size = stat->st_size;
	new->st_rdev = stat->st_rdev;
	new->time = stat->st_mtimespec.tv_sec;
	new->ntime = stat->st_mtimespec.tv_nsec;
	new->st_blocks = stat->st_blocks;
	if (!(new->name = ft_strdup(name)))
		ls_error(MALL_ERR, NULL);
	get_full_path(path, name, new->full_path);
	new->next = NULL;
	return (new);
}

int				add_new_file(char path[PATH_MAX], char *name, t_file **begin)
{
	char		full_path[PATH_MAX];
	t_stat		stat;

	if (!(get_full_path(path, name, full_path)))
	{
		ls_error(ERRNO, name);
		return (-1);
	}
	if (lstat(full_path, &stat) == -1)
		return (-1);
	if (*begin == NULL)
	{
		*begin = new_file(path, name, &stat);
		return (1);
	}
	while ((*begin)->next != NULL)
	{
		begin = &((*begin)->next);
	}
	(*begin)->next = new_file(path, name, &stat);
	return (1);
}
