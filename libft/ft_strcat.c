/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:33:56 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:34:03 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int index;
	int length;

	length = ft_strlen(s1);
	index = 0;
	while (s2[index] != '\0')
		s1[length++] = s2[index++];
	s1[length] = '\0';
	return (s1);
}
