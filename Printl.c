/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:04:32 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/05 14:52:37 by pntsunts         ###   ########.fr       */
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
/*
int main(int argc, char **argv) {
	if (argc > 1)
		printl(argv[1]);
	return 0;
}*/
