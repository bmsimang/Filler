/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:21:02 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:21:05 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	u_c;
	unsigned char	*u_dst;
	unsigned char	*u_src;
	size_t			index;

	u_c = (unsigned char)c;
	u_dst = (unsigned char*)dst;
	u_src = (unsigned char*)src;
	index = 0;
	while (index++ < n)
	{
		if (*u_src == u_c)
		{
			*u_dst = u_c;
			u_dst++;
			return (u_dst);
		}
		*u_dst++ = *u_src++;
	}
	return (NULL);
}
