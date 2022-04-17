/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:33:48 by qduong            #+#    #+#             */
/*   Updated: 2022/04/15 19:41:36 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

typedef struct s_game
{
	int		collectibles;
	int		exit;
	int		start;
}				t_game;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_game		game;
}				t_vars;	

#endif