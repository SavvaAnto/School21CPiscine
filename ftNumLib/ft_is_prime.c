/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 19:58:43 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/29 05:13:32 by gjanei           ###   ########.fr       */
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
