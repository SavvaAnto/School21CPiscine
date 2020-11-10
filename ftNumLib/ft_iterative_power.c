/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 05:15:53 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/29 05:16:11 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int res;

	if (power < 0)
		return (0);
	res = 1;
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}
