/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:00:11 by qduong            #+#    #+#             */
/*   Updated: 2022/04/20 23:01:59 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeme(t_vars *mlx, int i, int fd)
{
	int	x;

	x = 0;
	while (x < i)
	{
		free(mlx->map[x]);
		x++;
	}
	free(mlx->map[i]);
	free(mlx->map);
	close(fd);
}

void	freeme2(t_vars *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->game.dim.y)
	{
		free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
}
