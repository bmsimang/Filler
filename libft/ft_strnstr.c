/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:41:19 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:41:21 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	count;

	index = 0;
	while (big[index] != '\0' && index < len)
	{
		count = 0;
		while (little[count])
		{
			if (little[count] == big[index + count])
				count++;
			else
				break ;
		}
		if (!little[count] && len >= index + count)
			return ((char*)(big + index));
		index++;
	}
	return (NULL);
}
