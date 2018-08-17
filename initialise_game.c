/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:40:58 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 10:41:01 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char			**allocate_grid(int rows, int cols)
{
	char	**grid;
	int		row;

	row = 0;
	if (!(grid = (char**)malloc(sizeof(char*) * (rows + 1))))
		return (NULL);
	grid[rows] = NULL;
	while (row < rows)
	{
		if (!(grid[row] = (char*)malloc(cols + 1)))
			return (NULL);
		ft_bzero(grid[row], cols + 1);
		row++;
	}
	return (grid);
}

void			get_player(char *line, t_game *game)
{
	if (line[10] == '1')
	{
		game->p_b = 'O';
		game->p_s = 'o';
	}
	else
	{
		game->p_b = 'X';
		game->p_s = 'x';
	}
}

t_bool			get_dimensions(char *line, t_game *game)
{
	char		**split;

	if (!(split = ft_strsplit(line, ' ')))
		return (False);
	game->rows = ft_atoi(split[1]);
	game->cols = ft_atoi(split[2]);
	ft_destroy_2d((void **)split);
	return (True);
}

static t_bool	update_grid(t_game *game)
{
	int		row;
	int		col;
	char	**split;
	char	*line;

	row = 0;
	line = NULL;
	while (row < game->rows)
	{
		get_next_line(0, &line);
		if (!(split = ft_strsplit(line, ' ')))
			return (False);
		col = 0;
		while (col < game->cols)
		{
			game->grid[row][col] = split[1][col];
			col++;
		}
		row++;
		ft_destroy_2d((void **)split);
	}
	free(line);
	return (True);
}

t_bool			play_game(t_game *game)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (False);
	free(line);
	ft_destroy_2d((void **)game->grid);
	if (!(game->grid = allocate_grid(game->rows, game->cols)))
		return (False);
	if (!(update_grid(game)))
		return (False);
	return (True);
}
