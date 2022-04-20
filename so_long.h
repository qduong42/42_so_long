/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:33:48 by qduong            #+#    #+#             */
/*   Updated: 2022/04/20 23:02:09 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "mlx/mlx.h"
# include "lib/ft_printf.h"
# include "lib/get_next_line.h"

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
}				t_game;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		**map;
	t_game		game;
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

/*
**Free
*/

void	freeme(t_vars *mlx, int i, int fd);
void	freeme2(t_vars *mlx);

#endif