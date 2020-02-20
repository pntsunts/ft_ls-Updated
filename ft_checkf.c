/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:48:01 by pntsunts          #+#    #+#             */
/*   Updated: 2020/02/20 12:10:23 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_check(int ac, char **av)
{
	if (ac < 2)
		exit(1);
	else 
	{
		while (av[1] != '\0')
		{
			if (av[1][0] != '-')
			break;

			if (av[1][0] == '-')
				return (1);
			else
				return (0);
		}
	}
	return (0);
}
