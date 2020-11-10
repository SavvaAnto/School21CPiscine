/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 23:04:58 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/31 23:32:05 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "ft_convert_base2.c"
#include <stdio.h>

int		ft_getdec(char *nbr, char *base_from)
{
	int i;
	int sign;

	i = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
	{
		i++;
	}
	sign = 1;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = sign * (-1);
		i++;
	}

	nbr = ft_get_portion(nbr + i, base_from);
	printf(" %s ", nbr);
	return (sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nbr_dec;
	char	*buf;
	char	*ans;
	int		sign;
	int		i;

	buf = malloc(100);
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	sign = ft_getdec(nbr, base_from);
	printf("\\%s\\", nbr);
	nbr_dec = str_to_long_base(nbr, base_from);
	printf("%li", nbr_dec);
	if (nbr_dec  > INT_MAX)
		return (NULL);
	i = 0;
	while (nbr_dec > 0)
	{
		buf[i] = base_to[nbr_dec % ft_strlen(base_to)];
		nbr_dec /= ft_strlen(base_to);
		i++;
	}
	if (sign < 0 && str_to_long_base(nbr, base_from) != 0)
	{
		buf[i] = '-';
		i++;
	}
	ans = malloc(i);
	ans[ft_strlen(buf)] = '\0';
	while (i >= 0)
	{
		ans[ft_strlen(buf) - i] = buf[i - 1];
		i--;
	}
	return (ans);
}
