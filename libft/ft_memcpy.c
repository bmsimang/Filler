/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:20:22 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:20:26 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*u_dst;
	unsigned char	*u_src;

	index = 0;
	u_dst = (unsigned char*)dst;
	u_src = (unsigned char*)src;
	while (index < n)
	{
		u_dst[index] = u_src[index];
		index++;
	}
	return (u_dst);
}
