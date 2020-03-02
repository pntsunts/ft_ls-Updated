/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:21:30 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/02 15:48:08 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printr(const char *dir_name, t_files store[])
{
//	t_files store[1024];
	int i = 0;
	printrev(dir_name, store);
	while (store[i].name != NULL)
		i++;
	i--;
	while (i >= 0)
		ft_putendl(store[i--].name);
	return ;
}
