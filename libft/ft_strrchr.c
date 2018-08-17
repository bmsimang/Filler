/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:41:40 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:41:42 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		rev_index;
	char	*temp_s;

	temp_s = (char*)s;
	rev_index = ft_strlen(temp_s);
	while (rev_index > 0 && (temp_s[rev_index] != c))
		rev_index--;
	if (temp_s[rev_index] == c)
		return (temp_s + rev_index);
	else
		return (NULL);
}
