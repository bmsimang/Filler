/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:42:42 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:42:44 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;

	index = 0;
	if (!s1 || !(sub = ft_strnew(len)))
		return (NULL);
	while (index < len)
		sub[index++] = s1[start++];
	return (sub);
}
