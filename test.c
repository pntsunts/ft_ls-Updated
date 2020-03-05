/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:51:19 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/05 15:20:42 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	test(int ac, char **av, P_flags *F_lags, t_files tmp[])
{
	//int i = 1;
	//int j;

	//while (ft_checkf(av[i]))
	//	i++;
	ft_confirm(ac, av, F_lags);
	//printf("l:%i\na:%i\nr:%i\nt:%i\nR:%i\n",F_lags->l_flag,F_lags->a_flag,F_lags->r_flag,F_lags->t_flag,F_lags->Re_flag);
	if (F_lags->l_flag == 1)
	{
		printing(av, tmp);
	}
   	if (F_lags->Re_flag == 1)
	{
		sion("/goinfre/pntsunts/Desktop");
		recur("/");
	}
	if (F_lags->a_flag == 1)
		ft_ls_a(".");
	if (F_lags->r_flag == 1)
	{
		//ft_putstr("YOU IN");
		printr(".", tmp);
	}
}
