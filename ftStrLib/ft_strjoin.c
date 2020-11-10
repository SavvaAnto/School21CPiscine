/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 02:39:17 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/31 02:47:40 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int dest_len;
	int i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

int		ft_totlen(int size, char **strs, char *sep)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(*(strs + i));
		i++;
		if (i == size)
			break ;
		len += ft_strlen(sep);
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		len;
	int		i;

	len = ft_totlen(size, strs, sep);
	res = malloc(len + 1);
	i = 0;
	while (i < size)
	{
		res = ft_strcat(res, *(strs + i));
		i++;
		if (i == size)
			break ;
		res = ft_strcat(res, sep);
	}
	*(res + len) = '\0';
	return (res);
}
