/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjanei <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 17:01:49 by gjanei            #+#    #+#             */
/*   Updated: 2020/08/01 18:18:38 by gjanei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_BOOLEAN_H
# define __FT_BOOLEAN_H
# include <unistd.h>
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define EVEN even

typedef	int	t_bool;

int		even(int nbr)
{
	return ((nbr + 1) % 2);
}

#endif
