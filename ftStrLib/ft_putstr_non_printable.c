/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:09:21 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/25 23:10:01 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	convert(int d)
{
	char h;

	if (d < 10)
	{
		h = d + 48;
	}
	else
	{
		h = d + 87;
	}
	return (h);
}

void	ft_putstr_non_printable(char *str)
{
	int i;
	int div;
	int mod;

	i = 0;
	while (str[i])
	{
		if (!(str[i] <= '~' && str[i] >= ' '))
		{
			ft_putchar('\\');
			div = str[i] / 16;
			mod = str[i] % 16;
			ft_putchar(convert(div));
			ft_putchar(convert(mod));
			i++;
			continue ;
		}
		ft_putchar(str[i]);
		i++;
	}
}
