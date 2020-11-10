/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:33:00 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/27 19:48:08 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int x, int y)
{
	int i;
	int res;

	i = 0;
	res = 1;
	while (i < y)
	{
		res = res * x;
		i++;
	}
	return (res);
}

int		str_to_int(char *str, int len)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (i < len)
	{
		res = res + (str[i] - 48) * ft_pow(10, len - 1 - i);
		i++;
	}
	return (res);
}

int		ft_atoi(char *str)
{
	char	buf[100];
	int		sign;
	int		i;
	int		j;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		buf[j] = str[i];
		j++;
		i++;
	}
	return (sign * str_to_int(buf, j));
}
