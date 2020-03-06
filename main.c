/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:26:22 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/06 14:50:01 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	P_flags *F_lags = (P_flags*)malloc(sizeof(P_flags));
	//t_files *tmp = (t_files*)malloc(sizeof(t_files));
	t_files tmp[1024];
	int i = 0;
	if (ac < 2)
	{
		if (av[i][0] != '-')
		{
			ft_ls("./");
		}
	}
	else
	{
		//ft_perm(av[1]);
		//ft_checkf(ac, av);
		//ft_confirm(ac, av, &F_lags);
		test(ac, av, F_lags, tmp);
	}
	sleep(10);
	return (0);
}

/*int main(void)
{
	sion("./");
	recur("/");
}*/
