/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:45:31 by pntsunts          #+#    #+#             */
/*   Updated: 2020/02/13 15:47:28 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int ac, char **av)
{
	struct stat filestat;

	if (ac == 2)
	{
		if (stat(av[1], &filestat) == -1)
		{
			perror("Error");
			return (-1);
		}
		if (S_ISDIR(filestat.st_mode))
			ft_putstr("d");
		if (filestat.st_mode & S_IWUSR)
			ft_putstr("w");
		if (filestat.st_mode & S_IXUSR)
			ft_putstr("x");
		if (filestat.st_mode & S_IRUSR)
			ft_putstr("r");
		if (filestat.st_mode & S_IWGRP)
			ft_putstr("w");
		if (filestat.st_mode & S_IXGRP)
			ft_putstr("x");
		if (filestat.st_mode & S_IRGRP)
			ft_putstr("r");
		if (filestat.st_mode & S_IWOTH)
			ft_putstr("w");
		if (filestat.st_mode & S_IROTH)
			ft_putstr("r");
		if (filestat.st_mode & S_IXOTH)
			ft_putstr("x");
		ft_putstr("-");
		ft_putstr("     ");
		ft_putnbr(filestat.st_nlink);
		ft_putstr("    ");
		ft_putnbr(filestat.st_size);
		ft_putstr("    ");
		return (0);
	}
}
