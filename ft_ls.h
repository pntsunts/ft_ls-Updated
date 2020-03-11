/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:31:21 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/11 16:28:42 by pntsunts         ###   ########.fr       */
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

typedef struct		s_files
{
	char			*name;
//	char			*link;
//	struct s_files	*next;
//	struct s_files	*prev;
//	struct s_files	*sub_dir;
	struct stat		filestat;
	time_t			mtime;
//	time_t			ttime;
	//int				mtime;
//	time_t			atime;
//	time_t			ctime;
//	int				ntime;
//	int				cntime;
//	char 			*dirname;
//	char			*file_name;
//	struct stat		*stptr;
//	int				isdir;
}				t_files;

void see(char *dir_name, t_files tmp[]);
int ft_structlen(t_files length[]);
void ft_displaytime(t_files test[], int n);
void number_sort(t_files order[], int n);
void	printtime(const char *dir_name, t_files data[]);
void revsort(t_files data[]);
void ft_time(const char *dir_name, t_files data[]);
void printr(const char *dir_name, t_files store[]);
void sion(const char *dir_name);
void recur(const char *dir_name);
void ft_ls(const char *dir_name);
void ft_ls_a(const char *dir_name);
void printrev(const char *dir_name, t_files data[]);
void ft_perm(const char *dir_name);
int	ft_checkf(char *av);
void ft_confirm(int ac, char **av, P_flags *F_lags);
void test(int ac, char **av, P_flags *F_lags, t_files tmp[]);
void permission(char *dir_name);
void printl(char *dir_name);
char *username(uid_t name);
char *grpname(gid_t name);
void ptime(char *str);
void printing(char **av, t_files data[]);
int ft_isdir(const char *dir_name);
void loopdir(char *av, t_files data[]);

#endif
