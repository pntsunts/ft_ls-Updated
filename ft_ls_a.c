/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:07:47 by pntsunts          #+#    #+#             */
/*   Updated: 2020/02/11 10:43:23 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				main(void)
{
	DIR		*directory;

	struct dirent *folders;
	
	directory = opendir(".");
	while ((folders = readdir(directory)) != NULL)
	{
		if (folders->d_name[0] != '\0')
		{
			ft_putstr(folders->d_name);
			ft_putchar('\n');
		}
	}
	closedir(directory);
	return (0);
}
