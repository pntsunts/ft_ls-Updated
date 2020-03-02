/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loopdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:12:43 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/02 16:16:40 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	loopdir(char *av, t_files data[])
{
	DIR		*directory;
	struct dirent *folders;
	int i = 0;

	directory = opendir(av);
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
