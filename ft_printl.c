/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:11:55 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/05 15:18:27 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printing(char **av, t_files tmp[])
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;

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
				s1 = ft_strjoin(av[i], "/");
				s2 = ft_strjoin(s1, tmp[j].name);
				printl(s2);
				free(s1);
				free(s2);
				j++;
			}
		}
		else
			printl(av[i]);
		i++;
	}
}


