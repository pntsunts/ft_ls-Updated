/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:26:56 by pntsunts          #+#    #+#             */
/*   Updated: 2020/02/18 16:40:49 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_perm(const char *dir_name)
{
	struct stat filestat;
	
	if (stat(dir_name, &filestat) == -1)
	{
		perror("Error");
		return ;
	}
	if (S_ISDIR(filestat.st_mode))
		ft_putstr("d");
	if (filestat.st_mode & S_IWUSR)
		ft_putstr("w");
	if (filestat.st_mode
}
