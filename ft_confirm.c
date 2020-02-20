/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_confirm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:29:44 by pntsunts          #+#    #+#             */
/*   Updated: 2020/02/20 16:16:35 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_confirm(int ac, char **av)
{
	struct P_flags F_lags;
	int i;
	int j;

	F_lags->l_flag = 0;
	F_lags->a_flag = 0;
	F_lags->r_flag = 0;
	F_lags->t_flag = 0;
	F_lags->Re_flag = 0;

	i = 1;

	if (ft_checkf(ac, av) == 1)
	{
		j = 1;
		while (av[i] != '\0')
		{
			if (av[i][j] != 'l' && av[i][j] != 'a' && av[i][j] != 'r' && av[i][j] != 't' 				&& av[i][j] != 'R')
			{
				ft_putstr("illegal option ----");
				return ;
			}
			if (av[i][j] == 'l')
				F_lags->l_flag = 1;
			else if (av[i][j] == 'a')
				F_lags->a_flag = 1;
			else if (av[i][j] == 'r')
				F_lags->r_flag = 1;
			else if (av[i][j] == 't')
				F_lags->t_flag = 1;
			else if (av[i][j] == 'R')
				F_lags->Re_flag = 1;
			j++;
		}
		i++;
	}
}
