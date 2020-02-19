/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:26:56 by pntsunts          #+#    #+#             */
/*   Updated: 2020/02/19 16:45:49 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_perm(const char *dir_name)
{
	struct stat filestat;
	struct passwd *pass;
	struct group *grp;

	if (stat(dir_name, &filestat) == -1)
	{
		perror("Error");
		return ;
	}
	ft_putchar((S_ISDIR(filestat.st_mode)) ? 'd' : '\0');
	ft_putchar((S_ISLNK(filestat.st_mode)) ? 'l' : '\0');
	ft_putchar((filestat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((filestat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((filestat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((filestat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((filestat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((filestat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((filestat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((filestat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((filestat.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("   ");
	ft_putnbr(filestat.st_nlink);
	ft_putstr("   ");
	if ((pass = getpwuid(filestat.st_uid)))
		ft_putstr(pass->pw_name);
	ft_putstr("   ");
	if ((grp = getgrgid(filestat.st_gid)))
		ft_putstr(grp->gr_name);
}
