/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:17:15 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:17:19 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	temp = (*alst);
	while (temp)
	{
		del(temp->content, temp->content_size);
		free((*alst));
		(*alst) = NULL;
		temp = temp->next;
		(*alst) = temp;
	}
}
