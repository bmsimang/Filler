/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:22:43 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:22:58 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*u_b;
	unsigned char	u_c;
	int				index;

	u_b = (unsigned char*)b;
	u_c = (unsigned char)c;
	index = 0;
	while (n--)
	{
		u_b[index++] = u_c;
	}
	return (u_b);
}
