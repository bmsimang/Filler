/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:10:32 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:10:35 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_contains_str(const char **argv, const char *str, int len)
{
	int		index;

	index = 0;
	while (index < len)
	{
		if (ft_strequ(argv[index], str))
			return (1);
		index++;
	}
	return (0);
}
