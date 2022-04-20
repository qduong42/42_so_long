/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:33:48 by qduong            #+#    #+#             */
/*   Updated: 2022/04/19 17:42:10 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

typedef struct s_game
{
	int		collectibles;
	int		exit;
	int		start;
	int		x;
	int		y;
}				t_game;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		**map;
	t_game		game;
}				t_vars;	

#endif