/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:51:19 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/11 16:25:34 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	test(int ac, char **av, P_flags *F_lags, t_files tmp[])
{
	int i;
	i = 1;

	while (i < ac && ft_checkf(av[i]))
	{
		ft_confirm(ac, av, F_lags);
		if (F_lags->l_flag == 1)
		{
//			printing(av, tmp);
			see(".", tmp);
		}
   		if (F_lags->Re_flag == 1)
		{
			sion(".");
			recur(".");
		}
		if (F_lags->a_flag == 1)
			ft_ls_a(".");
		if (F_lags->r_flag == 1)
		{
			printr(".", tmp);
		}
		if (F_lags->t_flag == 1)
		{
			printtime(".", tmp);
		}
		i++;
	}
}
