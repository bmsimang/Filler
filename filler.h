/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:40:36 by bmsimang          #+#    #+#             */
/*   Updated: 2018/08/14 10:40:43 by bmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <stdio.h>
# define MIN(x,y) (x <= y ? x : y)

typedef	enum	e_bool
{
	False,
	True
}				t_bool;

typedef struct	s_point
{
	int row;
	int col;
}				t_point;

typedef	struct	s_points
{
	t_point			point;
	struct s_points	*next;
}				t_points;

typedef	struct	s_token
{
	int			cols;
	int			rows;
	char		**grid;
}				t_token;

typedef	struct	s_game
{
	char		p_b;
	char		p_s;
	char		**grid;
	int			rows;
	int			cols;
	int			dir;
	t_token		token;
	t_points	*moves;
}				t_game;

char			**allocate_grid(int rows, int cols);
void			destroy_game(t_game *game);
t_bool			play_game(t_game *game);
t_bool			get_token(t_token *token, char *line);
t_bool			get_possible_moves(t_game *game, t_token *token);
t_point			get_best_move(t_game *game);
t_point			get_1st_move(t_game *game);
t_points		*newlst(t_point point);
char			**cut_grid(t_point *point, t_token *token, t_game *game);
void			get_player(char *line, t_game *game);
t_bool			get_dimensions(char *line, t_game *game);
t_bool			addmove(t_points **moves, t_point point);
void			destroy_lst(t_points **lst);
#endif
