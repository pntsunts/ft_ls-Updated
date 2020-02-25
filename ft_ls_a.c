/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:07:47 by pntsunts          #+#    #+#             */
/*   Updated: 2020/02/25 11:58:53 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_ls_a(const char *dir_name)
{
	DIR		*directory;

	struct dirent *folders;
	
	directory = opendir(dir_name);
	while ((folders = readdir(directory)) != NULL)
	{
		if (folders->d_name[0] != '\0')
		{
			ft_putstr(folders->d_name);
			ft_putchar('\n');
		}
	}
	closedir(directory);
	return ;
}
