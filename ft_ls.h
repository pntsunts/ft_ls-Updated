/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:31:21 by pntsunts          #+#    #+#             */
/*   Updated: 2020/02/21 12:56:03 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include "libft/libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

typedef struct flags
{
	int	l_flag;
	int a_flag;
	int r_flag;
	int Re_flag;
	int t_flag;
}		P_flags;

void sion(const char *dir_name);
void recur(const char *dir_name);
void ft_ls(const char *dir_name);
void ft_perm(const char *dir_name);
int	ft_checkf(char *av);
void ft_confirm(int ac, char **av, P_flags *F_lags);
void test(int ac, char **av, P_flags *F_lags);

#endif
