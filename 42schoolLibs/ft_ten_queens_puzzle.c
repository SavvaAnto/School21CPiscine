/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 05:11:12 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/29 12:30:35 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_forbidden[30][30];
int g_res;

void	ft_recover(int mem[30][30])
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			g_forbidden[10 + i][10 + j] = mem[10 + i][10 + j];
			j++;
		}
		i++;
	}
}

void	ft_display(void)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (g_forbidden[10 + j][10 + i] == 2)
			{
				c = j + 48;
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	c = '\n';
	write(1, &c, 1);
}

void	ft_forbid(int y, int x)
{
	int i;

	i = 0;
	while (i < 10)
	{
		g_forbidden[10 + i][10 + x] = 1;
		g_forbidden[10 + y][10 + i] = 1;
		g_forbidden[10 + y + i][10 + x + i] = 1;
		g_forbidden[10 + y - i][10 + x + i] = 1;
		i++;
	}
	g_forbidden[10 + y][10 + x] = 2;
	if (x == 9)
	{
		ft_display();
		g_res++;
		return ;
	}
}

void	ft_putqueen(int x, int y)
{
	int mem[30][30];
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mem[10 + i][10 + j] = g_forbidden[10 + i][10 + j];
			j++;
		}
		i++;
	}
	while (y < 10 && x < 10)
	{
		if (!g_forbidden[10 + y][10 + x])
		{
			ft_forbid(y, x);
			ft_putqueen(x + 1, 0);
		}
		ft_recover(mem);
		y++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int i;
	int j;

	g_res = 0;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			g_forbidden[10 + i][10 + j] = 0;
			j++;
		}
		i++;
	}
	ft_putqueen(0, 0);
	return (g_res);
}
