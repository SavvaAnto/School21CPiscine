/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:54:32 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/28 12:49:02 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int		ft_check_base(char *base)
{
	int i;
	int j;

	if (ft_strlen(base) < 2)
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

void	ft_putpos_base(int nbr, char *base)
{
	int		bl;
	char	buf[100];
	int		i;

	bl = ft_strlen(base);
	i = 0;
	while (nbr > 0)
	{
		buf[i] = base[nbr % bl];
		nbr = nbr / bl;
		i++;
	}
	while (i > 0)
	{
		ft_putchar(buf[i - 1]);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	char safer;

	if (!(ft_check_base(base)))
		return ;
	if (nbr == 0)
		ft_putchar(base[0]);
	safer = 0;
	if (nbr < 0)
	{
		safer = base[nbr % ft_strlen(base)];
		nbr = nbr / ft_strlen(base) * (-1);
		ft_putchar('-');
	}
	ft_putpos_base(nbr, base);
	if (safer)
		ft_putchar(safer);
}
