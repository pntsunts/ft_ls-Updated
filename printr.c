/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:21:30 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/06 11:06:05 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printr(const char *dir_name, t_files store[])
{
	int i = 0;
	//revsort(store);
	printrev(dir_name, store);
	revsort(store);
	while (store[i].name != NULL)
		i++;
	i--;
	while (i >= 0)
		ft_putendl(store[i--].name);
	return ;
}

void	revsort(t_files data[])
{
	int i;
	int j;
	char *tmp;

	j = 0;
	while (!j)
	{
		i = 0;
		while (data[i + 1].name)
		{
			if (ft_strcmp(data[i].name, data[i + 1].name) > 0)
			{
				tmp = data[i].name;
				data[i].name = data[i + 1].name;
				data[i + 1].name  = tmp;
			}
			i++;
		}
		i = 0;
		j = 1;
		while (data[i + 1].name && j)
		{
			if (ft_strcmp(data[i].name, data[i + 1].name) > 0)
				j = 0;
			i++;
		}
	}
}
