/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:42:20 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 10:42:26 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_bool			get_token(t_token *token, char *line1)
{
	char	*line;
	char	**split;
	int		row;
	int		col;

	line = NULL;
	if (!(split = ft_strsplit(line1, ' ')))
		return (False);
	ft_destroy_2d((void **)token->grid);
	token->rows = ft_atoi(split[1]);
	token->cols = ft_atoi(split[2]);
	ft_destroy_2d((void **)split);
	if (!(token->grid = allocate_grid(token->rows, token->cols)))
		return (False);
	row = 0;
	while (row++ < token->rows && get_next_line(0, &line) > 0)
	{
		col = 0;
		while (col++ < token->cols)
			token->grid[row - 1][col - 1] = line[col - 1];
	}
	free(line);
	return (True);
}

char			**cut_grid(t_point *point, t_token *token, t_game *game)
{
	char	**grid;
	int		row;
	int		col;
	int		g_row;
	int		g_col;

	grid = NULL;
	if (!(grid = allocate_grid(token->rows, token->cols)))
		return (NULL);
	g_row = point->row;
	g_col = point->col;
	row = 0;
	if (g_row + token->rows > game->rows && g_col + token->cols > game->cols)
		return (NULL);
	while (g_row < point->row + token->rows && row < token->rows)
	{
		col = 0;
		g_col = point->col;
		while (g_col < point->col + token->cols && col < token->cols)
			grid[row][col++] = game->grid[g_row][g_col++];
		g_row++;
		row++;
	}
	return (grid);
}

static	t_bool	check_validity(t_point *p, t_token *tok, t_game *gg, int i)
{
	int		row;
	int		col;
	char	**g;
	char	c;

	row = 0;
	if (!(g = cut_grid(p, tok, gg)))
		return (False);
	while (row++ < tok->rows)
	{
		col = 0;
		while (col++ < tok->cols)
		{
			if (tok->grid[row - 1][col - 1] == '*')
			{
				c = g[row - 1][col - 1];
				if ((c == gg->p_b || c == gg->p_s) && ++i < 2)
					continue ;
				if (c != '.')
					return (False);
			}
		}
	}
	ft_destroy_2d((void **)g);
	return (i == 1 ? True : False);
}

t_bool			get_possible_moves(t_game *game, t_token *tok)
{
	t_point		point;

	point.row = 0;
	while (point.row + tok->rows - 1 < game->rows)
	{
		point.col = 0;
		while (point.col + tok->cols - 1 < game->cols)
		{
			if (check_validity(&point, tok, game, 0) == True)
			{
				if (!game->moves && !(game->moves = newlst(point)))
					return (False);
				else if (!(addmove(&(game->moves), point)))
					return (False);
			}
			point.col++;
		}
		point.row++;
	}
	return (True);
}
