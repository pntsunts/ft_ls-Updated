/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printrev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:05:45 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/02 11:48:05 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printrev(const char *dir_name, t_files data[])
{
	DIR			*directory;
	struct dirent *folders;
	int i = 0;

	directory = opendir(dir_name);
	while ((folders = readdir(directory)) != NULL)
	{
		if (folders->d_name[i] != '.')
		{
			data[i].name = ft_strdup(folders->d_name);
			i++;
		}
	}
	closedir(directory);
}

/*int main(void)
{
	t_files data[1024];
	int i = 0;
	printrev(".", data);
	while (data[i].name != NULL)
		i++;
	i--;
	while (i >= 0)
		ft_putendl(data[i--].name);
	return 0;
}

void	printr(const char *dir_name, t_files data[])
{
	t_files	data[1024];
	int i = 0;
	printrev(dir_name, data);
	while (data[i].name != NULL)
		i++;
	i--;
	while (i >= 0)
		ft_putendl(data[i--].name);
	return (0);
}*/
