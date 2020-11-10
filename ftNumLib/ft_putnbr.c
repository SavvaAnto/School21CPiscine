ф/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:08:06 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/28 12:50:50 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putpos(int nb)
{
	char	buf[100];
	int		i;

	i = 0;
	while (nb > 0)
	{
		buf[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	while (i > 0)
	{
		ft_putchar(buf[i - 1]);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	char	safer;

	if (nb == 0)
		ft_putchar('0');
	safer = 0;
	if (nb < 0)
	{
		safer = (nb % 10) * (-1) + 48;
		nb = nb / 10 * (-1);
		ft_putchar('-');
	}
	ft_putpos(nb);
	if (safer)
		ft_putchar(safer);
}
