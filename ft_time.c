/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:43:29 by pntsunts          #+#    #+#             */
/*   Updated: 2020/03/06 15:09:41 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_time(const char *dir_name, t_files data[])
{
	DIR				*directory;
	struct dirent 	*folders;
	struct stat   t_f;
	int i = 0;

	directory = opendir(dir_name);
	while ((folders = readdir(directory)) != NULL)
	{
		if (folders->d_name[i] != '.')
		{
			data[i].name = ft_strdup(folders->d_name);
			data[i].mtime = t_f.st_mtime;
			i++;
		}
	}
	closedir(directory);
}

void	printtime(t_files store[])
{
//	int i = 0;
	ft_time(".", store);
	dtime(store,length(store)); 

}

void	dtime(t_files data[], int i)
{
	i--;
	sorte(data);
	ft_putendl(data[1].name);
	while (i >= 0)
	{
		if (*data[i].name != '.')
		{
			ft_putendl(data[i].name);
			ft_strdel(&data[i].name);
		}
		i--;
	}
}

int		length(t_files len[])
{
	int i;

	i = 0;
	while (len[i].name != NULL)
		i++;
	return (i);

}

/*void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}*/

t_files	*ft_swap(t_files *s1, t_files *s2)
{
	if (s1->prev != NULL)
		s1->prev->next = s2;
	s2->prev = s1->prev;
	s1->prev = s2;
	s1->next = s2->next;
	if (s2->next != NULL)
		s2->next->prev = s1;
	s2->next = s1;
	return (s2);
}

t_files		*sorte(t_files data[])
{
	t_files *str;

	str = data;
	while (str->next != NULL)
	{
		if (str->ctime < str->next->ctime)
		{
			str = ft_swap(str, str->next);
			str = data;
		}
		else if (str->ctime == str->next->ctime)
		{
			if (str->ctime < str->next->ctime)
			{
				str = ft_swap(str, str->next);
				str = data;
			}
			else
				str = str->next;
		}
		else
			str = str->next;
	}
	return (data);
}



