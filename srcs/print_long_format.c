/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:06:44 by rmonnier          #+#    #+#             */
/*   Updated: 2017/02/10 14:43:08 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		get_file_type(int mode)
{
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

static char		get_file_acl(char path[PATH_MAX])
{
	acl_t	tmp;
	char	buf[101];

	if (listxattr(path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
}

static void		get_file_mode(char str[12], int mode, char path[PATH_MAX])
{
	str[0] = get_file_type(mode);
	str[1] = ((S_IRUSR & mode) != 0) ? 'r' : '-';
	str[2] = ((S_IWUSR & mode) != 0) ? 'w' : '-';
	str[3] = ((S_IXUSR & mode) != 0) ? 'x' : '-';
	str[4] = ((S_IRGRP & mode) != 0) ? 'r' : '-';
	str[5] = ((S_IWGRP & mode) != 0) ? 'w' : '-';
	str[6] = ((S_IXGRP & mode) != 0) ? 'x' : '-';
	str[7] = ((S_IROTH & mode) != 0) ? 'r' : '-';
	str[8] = ((S_IWOTH & mode) != 0) ? 'w' : '-';
	str[9] = ((S_IXOTH & mode) != 0) ? 'x' : '-';
	if ((S_ISUID & mode) != 0)
		str[3] = str[3] == '-' ? 'S' : 's';
	if ((S_ISGID & mode) != 0)
		str[6] = str[6] == '-' ? 'S' : 's';
	if ((S_ISVTX & mode) != 0)
		str[9] = str[9] == '-' ? 'T' : 't';
	str[10] = get_file_acl(path);
	str[11] = '\0';
}

static void		print_time(t_file *file)
{
	time_t	today;
	char	*str;

	str = ctime(&(file->time));
	time(&today);
	if ((today - 15724800 > file->time) || (today < file->time))
		ft_printf(" %6.6s  %.4s", str + 4, str + 20);
	else
		ft_printf(" %12.12s", str + 4);
}

void				print_long_format(t_file *file, int size[6])
{
	char	str[12];
	char	buf[NAME_MAX + 1];

	get_file_mode(str, file->mode, file->full_path);
	ft_printf("%s", str);
	ft_printf(" %*hu", size[0], file->st_nlink);
	ft_printf(" %-*s", size[1], getpwuid(file->st_uid)->pw_name);
	ft_printf("  %-*s", size[2], getgrgid(file->st_gid)->gr_name);
	if (str[0] != 'c' && str[0] != 'b')
		ft_printf("  %*lld", size[3], file->st_size);
	else
	{
		ft_printf(" %*d", size[4], major(file->st_rdev));
		ft_printf(", %*d", size[5], minor(file->st_rdev));
	}
	print_time(file);
	if (str[0] != 'l')
		ft_printf(" %s\n", file->name);
	else
	{
		ft_bzero(buf, NAME_MAX + 1);
		readlink(file->full_path, buf, NAME_MAX);
		ft_printf(" %s -> %s\n", file->name, buf);
	}
	return ;
}
