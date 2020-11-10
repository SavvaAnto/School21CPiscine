/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 01:11:50 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/31 19:59:47 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long i;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	*range = malloc((max - min) * 4);
	if (*range == NULL)
	{
		return (-1);
	}
	i = 0;
	while (i < max - min)
	{
		*(*range + i) = min + i;
		i++;
	}
	return (i);
}
