/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 22:57:39 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/31 23:03:33 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	res[i] = '\0';
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

long	char_to_int_base(char c, char *base)
{
	long i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (ft_strlen(base));
}

long	str_to_long_base(char *str, char *base)
{
	long	res;
	long	pow;
	int		i;

	res = 0;
	pow = 1;
	i = ft_strlen(str);
	while (i > 0)
	{
		res += char_to_int_base(str[i - 1], base) * pow;
		pow *= ft_strlen(base);
		i--;
	}
	return (res);
}
