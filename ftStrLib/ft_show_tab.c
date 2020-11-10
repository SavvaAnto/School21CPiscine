/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:36:23 by gjanei            #+#    #+#             */
/*   Updated: 2020/08/01 18:05:54 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int		i;
	char	line;

	i = 0;
	while (str[i] > 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	line = '\n';
	write(1, &line, 1);
}

void	ft_put_positive(int nb)
{
	char	buf[100];
	int		i;
	char	line;
	char	zero;

	zero = '0';
	i = 0;
	if (nb == 0)
		write(1, &zero, 1);
	while (nb > 0)
	{
		buf[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	while (i > 0)
	{
		write(1, &buf[i - 1], 1);
		i--;
	}
	line = '\n';
	write(1, &line, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_put_positive(par[i].size);
		ft_putstr(par[i].copy);
		i++;
	}
}
