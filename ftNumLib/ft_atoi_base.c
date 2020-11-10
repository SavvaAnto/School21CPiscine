/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:03:41 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/28 15:41:41 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_get_portion(char *str, char *base)
{
	char	buf[100];
	char	*res;
	int		i;
	int		j;

	res = buf;
	i = 0;
	j = 0;
	while (base[j])
	{
		if (str[i] == base[j])
		{
			res[i] = str[i];
			i++;
			j = 0;
			continue ;
		}
		j++;
	}
	return (res);
}

int		ft_check_base(char *base)
{
	int bl;
	int i;
	int j;

	bl = 0;
	while (base[bl])
		bl++;
	if (bl < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		char_to_int_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int		str_to_int_base(char *str, char *base)
{
	int res;
	int sl;
	int bl;
	int pow;

	sl = 0;
	while (str[sl])
		sl++;
	bl = 0;
	while (base[bl])
		bl++;
	res = 0;
	pow = 1;
	while (sl > 0)
	{
		res = res + char_to_int_base(str[sl - 1], base) * pow;
		pow = pow * bl;
		sl--;
	}
	return (res);
}

int		ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		i;

	if (!(ft_check_base(base)))
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	return (sign * str_to_int_base(ft_get_portion(str + i, base), base));
}
