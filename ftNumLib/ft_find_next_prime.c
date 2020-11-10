/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 20:57:41 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/29 05:18:50 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_downward_rounded_sqrt(int nb)
{
	int i;

	i = 0;
	while ((i * i) <= nb && i < 46341)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1);
}

int	ft_is_prime(int nb)
{
	int i;
	int sqrt;

	if (nb <= 1)
		return (0);
	sqrt = ft_downward_rounded_sqrt(nb);
	i = 2;
	while (i <= sqrt)
	{
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if (ft_is_prime(nb))
		{
			return (nb);
		}
		nb++;
	}
}
