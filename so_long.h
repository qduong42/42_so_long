/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:33:48 by qduong            #+#    #+#             */
/*   Updated: 2022/04/25 17:04:25 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "mlx/mlx.h"
# include "lib/ft_printf.h"
# include "lib/get_next_line.h"
# include <stdio.h>

/*
** DEFINE KEYS
*/
enum	e_keys
{
	ESC = 53,
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2
};

typedef struct s_coords
{
	int	x;
	int	y;
}				t_coords;

typedef struct s_game
{
	int			collectibles;
	int			exit;
	int			start;
	int			space;
	t_coords	pos;
	t_coords	dim;
	int			moves;
}				t_game;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		**map;
	void		*player;
	void		*exit;
	void		*collect;
	void		*wall;
	void		*space;
	int			imgx;
	int			imgy;
	t_game		game;
	char		*string;
}				t_vars;	

/*
**Checks
*/

void	init(t_vars *mlx);
int		check_argc(int argc, char **argv);
int		check_input(int argc, char **argv);
void	in_check_map(char **argv, t_vars *mlx);
void	parse_map(char **argv, t_vars *mlx);
void	full_check_map(t_vars *mlx);

/*
**Utils
*/

size_t	ft_len(const char *s);
void	put_stuff(t_vars *mlx, int x, int y, char c);
void	put_string_game(t_vars *mlx);

/*
**Free
*/

void	freeme(t_vars *mlx, int i, int fd);
void	freeme2(t_vars *mlx);
int		freeme3(t_vars *mlx);

/*
** Move Functions
*/

void	left(t_vars *mlx);
void	up(t_vars *mlx);
void	right(t_vars *mlx);
void	down(t_vars *mlx);

#endif