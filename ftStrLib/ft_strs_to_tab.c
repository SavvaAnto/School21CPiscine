/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 14:47:19 by gjanei            #+#    #+#             */
/*   Updated: 2020/08/01 23:11:16 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char				*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int					ft_totlen(int n, char **strs)
{
	int totlen;
	int i;

	totlen = 0;
	i = 0;
	while (i < n)
	{
		totlen += ft_strlen(*(strs + i));
		i++;
	}
	return (totlen);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*res;
	int			i;
	int			totlen;

	totlen = ft_totlen(ac, av);
	res = malloc(ac * 4 + totlen * 2 + 1000);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		res[i].size = ft_strlen(*(av + i));
		res[i].str = *(av + i);
		res[i].copy = malloc(ft_strlen(*(av + i)) + 100);
		if (res[i].copy == NULL)
			return (NULL);
		res[i].copy = ft_strcpy(res[i].copy, *(av + i));
		i++;
	}
	res[i].size = 0;
	res[i].str = 0;
	res[i].copy = 0;
	return (res);
}
