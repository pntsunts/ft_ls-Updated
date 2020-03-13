/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:24:27 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/13 12:25:08 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(const char *dir_name, t_files data[])
{
	DIR				*directory;
	struct dirent	*folders;
	int i = 0;

	directory = opendir(dir_name);
	while ((folders = readdir(directory)) != NULL)
	{
		if (folders->d_name[0] != '.')
		{
			data[i].name = ft_strdup(folders->d_name);
			i++;
		}
	}
	closedir(directory);
}

int		countfiles(t_files store[])
{
	int i = 0;

	while (store[i].name != 0)
		i++;
	return (i);
}

void	ls(const char *dir_name, t_files store[])
{
	int i ;

	ft_ls(dir_name, store);
	i = countfiles(store);
	sortls(store, i);
	i = 0;
	while (store[i].name != NULL)
		ft_putendl(store[i++].name);
	return ;
	
}

void	sortls(t_files data[], int n)
{
	int		i;
	int		j;
	t_files	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (ft_strcmp(data[j].name, data[j + 1].name) > 0)
			{
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
