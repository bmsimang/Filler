/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:39:39 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:39:41 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t index;
	size_t length;

	index = 0;
	length = ft_strlen(s1);
	while (s2[index] != '\0' && index < n)
		s1[length++] = s2[index++];
	s1[length] = '\0';
	return (s1);
}
