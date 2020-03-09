/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:43:29 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/09 16:36:17 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_time(const char *dir_name, t_files data[])
{
	DIR				*directory;
	struct dirent 	*folders;
	struct stat   t_f;
	int i = 0;

	directory = opendir(dir_name);
	while ((folders = readdir(directory)) != NULL)
	{
		if (folders->d_name[i] != '.')
		{
			data[i].name = ft_strdup(folders->d_name);
			data[i].mtime = t_f.st_mtime;
			i++;
		}
	}
	closedir(directory);
}

void	printtime(t_files store[])
{
//	int i = 0;
	ft_time(".", store);
	distime(store,length(store)); 

}

void	distime(t_files data[], int i)
{
	i--;

	ft_putendl("OPPPPPPS");
	sortime(data, i);
	while (i >= 0)
	{
		if (*data[i].name != '.')
		{
			ft_putendl(data[i].name);
			ft_strdel(&data[i].name);
		}
		i--;
	}
}

int		length(t_files len[])
{
	int i;

	i = 0;
	while (len[i].name != NULL)
		i++;
	return (i);
}

void		swap(t_files	*data, int i)
{
	t_files		tmp;

	if (ft_strcmp(data[i].name , data[i + 1].name) > 0)
	{
		tmp = data[i];
		data[i] = data[i + 1];
		data[i + 1] = tmp;
	}
}

void	strset(t_files *data, int i)
{
	struct timespec s1;
	struct timespec s2;

	s1 = data[i].stptr.st_mtimespec;
	s2 = data[i + 1].stptr.st_mtimespec;
}

int		timesort(t_files *data, int i)
{
	struct timespec s1;
	struct timespec s2;
	t_files tmp;

	if (s1.tv_sec < s2.tv_sec)
	{
		tmp = data[i];
		data[i] = data[i + 1];
		data[i + 1] = tmp;
		return (-1);
	}
	else if (s1.tv_sec == s2.tv_sec)
		swap(data, i);
	return (0);
}

void	sortime(t_files *data, int i)
{
	int y;
	int x;
	int z;
//	struct timespec s1;
//	struct timespec s2;

	z = i > 1;
	while (z)
	{
		x = -1;
		z = 0;
		while (++x < (i - 1))
		{
			strset(data, i);
			y = timesort(data, i);
			z = (y == -1) ? 1 : 0;
			if (z == 1)
				break;
		}
	}
}
