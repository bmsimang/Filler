/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:39:59 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:40:01 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *hold_s1;
	unsigned char *hold_s2;

	hold_s1 = (unsigned char*)s1;
	hold_s2 = (unsigned char*)s2;
	if (n <= 0)
		return (0);
	if (!ft_strlen((char*)hold_s1) || !ft_strlen((char*)hold_s2))
		return (*hold_s1 - *hold_s2);
	while (n-- && *hold_s1 && *hold_s2)
	{
		if ((*hold_s1 > *hold_s2) || (*hold_s1 < *hold_s2))
			return (*hold_s1 - *hold_s2);
		if (n == 0)
			break ;
		hold_s1++;
		hold_s2++;
	}
	return (*hold_s1 - *hold_s2);
}
