/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:41:22 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 10:41:25 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		destroy_lst(t_points **lst)
{
	t_points *tmp;

	tmp = (*lst);
	while (tmp)
	{
		free(*lst);
		*lst = NULL;
		tmp = tmp->next;
		*lst = tmp;
	}
}

void		destroy_game(t_game *game)
{
	ft_destroy_2d((void **)game->grid);
	ft_destroy_2d((void **)game->token.grid);
}

t_points	*newlst(t_point point)
{
	t_points *lst;

	if (!(lst = (t_points*)malloc(sizeof(t_points))))
		return (NULL);
	lst->point = point;
	lst->next = NULL;
	return (lst);
}

t_bool		addmove(t_points **moves, t_point point)
{
	t_points *node;

	if (!(node = newlst(point)))
		return (False);
	node->next = (*moves);
	(*moves) = node;
	return (True);
}
