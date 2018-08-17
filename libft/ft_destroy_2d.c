/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:10:54 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:10:55 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_destroy_2d(void **grid)
{
	int index;

	if (grid)
	{
		index = 0;
		while (grid[index])
		{
			ft_memdel(&grid[index]);
			index++;
		}
		free(grid);
		grid = NULL;
	}
	return (NULL);
}
