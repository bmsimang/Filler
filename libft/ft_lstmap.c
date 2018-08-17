/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:19:03 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 15:19:06 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *ret;

	ret = f(lst);
	temp = ret;
	while ((lst = lst->next))
	{
		temp->next = f(lst);
		temp = temp->next;
	}
	temp->next = NULL;
	return (ret);
}
