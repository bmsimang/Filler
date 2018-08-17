/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:21:19 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:21:21 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *u_s;
	unsigned char u_c;

	u_s = (unsigned char*)s;
	u_c = (unsigned char)c;
	while (n--)
	{
		if (*u_s == u_c)
			return (u_s);
		u_s++;
	}
	return (NULL);
}
