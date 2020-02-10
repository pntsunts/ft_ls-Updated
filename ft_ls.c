/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:24:27 by pntsunts          #+#    #+#             */
/*   Updated: 2020/02/10 15:44:55 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main()
{
	DIR *directory;

	struct dirent *folders;

	directory = opendir(".");

	folders = readdir(directory);

	while (folders != NULL)
	{
		if (folders->d_name[0] != '.')
		{
			ft_putstr(folders->d_name);
			ft_putchar('\t');
		}
	}
	closedir(directory);
	return (0);
}
