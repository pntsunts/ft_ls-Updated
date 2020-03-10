/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:43:29 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/10 14:49:19 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_time(const char *dir_name, t_files data[])
{
	DIR				*directory;
	struct dirent 	*folders;
	struct stat   t_f;
	int i = 0;
	char path[1042];

	ft_bzero(path, 1);
	ft_strcat(path, dir_name);
	directory = opendir(dir_name);
	while ((folders = readdir(directory)) != NULL)
	{
		if (folders->d_name[i] != '.')
		{
			ft_strcat(path, folders->d_name);
			//lstat(path, (data[i].stptr));
			//lstat(path, &t_f);
			data[i].name = ft_strdup(folders->d_name);
			if (lstat(data[i].name, &t_f) < 0)
			{
				printf("This sucks");
				return ;
			}
			data[i].mtime = t_f.st_mtime;
			i++;
		}
	}
	closedir(directory);
}

void printtime(const char *dir_name, t_files data[])
{
	ft_time(dir_name, data);
	ft_displaytime(data, ft_structlen(data));
}

int		ft_structlen(t_files length[])
{
	int	i;

	i = 0;
	while (length[i].name != NULL)
		i++;
	return (i);
}

void	ft_displaytime(t_files test[], int n)
{
	n--;
	number_sort(test, n);
	while (n >= 0)
	{
		if (*test[n].name != '.')
		{
			ft_putendl(test[n].name);
			ft_strdel(&test[n].name);
		}
		n--;
	}
}

void	number_sort(t_files order[], int n)
{
	int		i;
	int		j;
	t_files	temp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		//printf("Index is >> %d, %ld ", i, order[i].mtime);
		//printf(" %s\n", order[i].name);
		while (j < n - i - 1)
		{
		//	printf("Current: %ld\nNext: %ld\n", order[j].mtime, order[j + 1].mtime);
			//if (order[j].mtime > order[j + 1].mtime)
			if (order[j].mtime > order[j + 1].mtime)
			{
				ft_putstr("Swapping values");
				temp = order[j];
				order[j] = order[j + 1];
				order[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
