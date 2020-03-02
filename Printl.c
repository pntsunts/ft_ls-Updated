/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:04:32 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/02 15:52:33 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printl(char *dir_name)
{
	struct stat filestat;

	stat(dir_name, &filestat);
	permission(dir_name);
	ft_putstr("	 ");
	ft_putnbr(filestat.st_nlink);
	ft_putstr("  ");
	ft_putstr(username(filestat.st_uid));
	ft_putstr("  ");
	ft_putstr(grpname(filestat.st_gid));
	ft_putstr("  ");
	ft_putnbr(filestat.st_size);
	ft_putstr("  ");
	ptime(ctime(&filestat.st_mtime));
	ft_putstr("  ");
	ft_putendl(dir_name);
}
