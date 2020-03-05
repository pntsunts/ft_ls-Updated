/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:43:59 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/05 14:01:18 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printing(char **av, t_files tmp[])
{
	int		i;
	int		j;
	char	*s1;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (ft_isdir(av[i]) && !ft_checkf(av[i]))
		{
			loopdir(av[i], tmp);
			j = 0;
			while (tmp[j].name != NULL)
			{
				s1 = ft_strjoin(ft_strjoin(av[i], "/"), tmp[j].name);
				printl(s1);
				j++;
			}
		}
		else
		{
			printl(av[i]);
		}
		i++;
	}
}
