/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 12:43:20 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/13 15:06:49 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sion(const char *dir_name)
{
	DIR				*directory;
	char			*data;
	struct dirent	*folder;

	directory = opendir(dir_name);
	data = (char *)malloc(sizeof(char) * 4080);
	if (!directory)
	{
		ft_putstr("Can't open the directory");
		return ;
	}
	ft_putchar('\n');
	while ((folder = readdir(directory)) != NULL)
	{
		if (folder->d_name[0] != '.' && folder->d_type == DT_DIR)
		{
			ft_strcpy(data, dir_name);
			ft_strcat(data, "/");
			ft_strcat(data, folder->d_name);
			recur(data);
		}
	}
	closedir(directory);
	free(data);
}

void	recur(const char *dir_name)
{
	DIR				*directory;
	char			*data;
	struct dirent	*folder;

	directory = opendir(dir_name);
	ft_putendl(dir_name);
	data = (char *)malloc(sizeof(char) * 4080);
	if (!directory)
	{
		ft_putstr("Cant open the Directory");
		return ;
	}
	while ((folder = readdir(directory)) != NULL)
		if (folder->d_name[0] != '.')
		{
			ft_putstr(folder->d_name);
			ft_putchar('\t');
			ft_strcpy(data, dir_name);
			ft_strcat(data, "/");
			ft_putchar('\n');
			ft_strcat(data, folder->d_name);
		}
	closedir(directory);
	free(data);
}
