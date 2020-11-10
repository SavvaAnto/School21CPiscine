/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:36:37 by gjanei            #+#    #+#             */
/*   Updated: 2020/07/29 14:38:00 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		ft_putchar(*(str + i));
		i++;
	}
}

int main(int argc, char **argv)
{
	(void) argc;

	ft_putstr(argv[0]);
	return (0);
}
