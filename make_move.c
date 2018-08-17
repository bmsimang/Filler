/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:42:03 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 10:42:07 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			area(t_game *game, t_point point)
{
	int		sg;

	if (game->p_s == 'o')
	{
		if ((game->dir = (game->dir == 0 ? 1 : 0)))
			sg = (point.col + 1) * (point.row + 1);
		else
			sg = (point.col + 1) * (game->rows - point.row - 1);
	}
	else
	{
		if (game->dir == 0)
		{
			game->dir = 1;
			sg = (game->cols - point.col - 1) * (point.row + 1);
		}
		else
		{
			game->dir = 0;
			sg = (game->cols - point.col - 1) * (game->rows - point.row - 1);
		}
	}
	return (sg);
}

t_point		get_best_move(t_game *game)
{
	t_point		ret;
	t_points	*tmp_moves;
	int			max_area;

	tmp_moves = game->moves;
	max_area = -1;
	while (game->moves)
	{
		if (area(game, game->moves->point) >= max_area)
		{
			max_area = area(game, game->moves->point);
			ret.col = game->moves->point.col;
			ret.row = game->moves->point.row;
		}
		game->moves = game->moves->next;
	}
	destroy_lst(&tmp_moves);
	return (ret);
}
