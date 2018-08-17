/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcuthead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:36:03 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:36:06 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcuthead(char **s, int c)
{
	char *temp;

	if (!*s)
		return (NULL);
	if (!(temp = ft_strsub(*s, c, ft_strlen(*s) - c)))
		return (NULL);
	if (*s)
		free(*s);
	if (!(*s = (char*)malloc(ft_strlen(temp) + 1)))
		return (NULL);
	ft_bzero((void*)(*s), ft_strlen(temp) + 1);
	ft_strcpy(*s, temp);
	free(temp);
	temp = NULL;
	return (*s);
}
