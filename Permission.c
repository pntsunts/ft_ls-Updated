/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Permission.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:07:02 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/05 15:16:11 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	permission(char *dir_name)
{
	struct stat filestat;

	stat(dir_name, &filestat);

	ft_putchar((S_ISDIR(filestat.st_mode)) ? 'd' : '-');
	ft_putchar((filestat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((filestat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((filestat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((filestat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((filestat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((filestat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((filestat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((filestat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((filestat.st_mode & S_IROTH) ? 'x' : '-');
}

char	*username(uid_t name)
{
	struct	passwd *pass;
	pass = getpwuid(name);
	return (pass->pw_name);
}

char	*grpname(gid_t name)
{
	struct group *grp;
	grp = getgrgid(name);
	return (grp->gr_name);
}

void	ptime(char *str)
{
	size_t	i;

	i = 4;
	while (i < 16)
		ft_putchar(str[i++]);
}
