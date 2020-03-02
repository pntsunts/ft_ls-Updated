/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:43:59 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/02 16:16:56 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printing(char **av, t_files data[])
{
	int i = 1;
	int j = 0;
	while (ft_checkf(av[i]))
		i++;
	while (av[i])
	{
		if (ft_isdir(av[i]) == 0)
			printl(av[i]);
		else
		{
			//ft_putstr("this is directory");
			//"printl(loopdir(av, data);
			loopdir(av[i], data);
			while (data[j].name != NULL)
				printl(av[j++]);
		}
		i++;
	}
}
