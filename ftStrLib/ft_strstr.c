/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:44:21 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/26 18:33:40 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		does_include(char *str, char *to_find, int i)
{
	int j;

	j = 1;
	while (to_find[j])
	{
		if (str[i + j] == to_find[j])
			j++;
		else
			return (0);
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(to_find[0]) || str[i] == to_find[0])
		{
			if (does_include(str, to_find, i))
			{
				return(&str[i]);
			}
		}
		i++;
	}
	return ("(null)");
}
