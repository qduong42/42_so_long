/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:40:12 by qduong            #+#    #+#             */
/*   Updated: 2022/04/24 15:25:41 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
Code to test:
**insert 30-31 	printf("Length x:[%d]%zu\n", i, ft_len(mlx->map[i]));
**insert 31-32 	printf("Map string[%i]:%s", i, mlx->map[i]);
*/

void	parse_map(char **argv, t_vars *mlx)
{
	int		fd;
	int		i;

	mlx->map = ft_calloc(mlx->game.dim.y + 1, sizeof(char *));
	i = 0;
	fd = open(*argv, O_RDONLY);
	while (i < mlx->game.dim.y)
	{
		mlx->map[i] = get_next_line(fd);
		if (ft_len(mlx->map[i]) != (size_t)(mlx->game.dim.x))
		{
			freeme(mlx, i, fd);
			exit(ft_putstr_fd("Map not straight", 2));
		}
		i++;
	}
	close(fd);
	return ;
}

void	check_wall(t_vars *mlx)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	y = 0;
	x = 0;
	while (y < mlx->game.dim.y)
	{
		x = 0;
		while (x < mlx->game.dim.x)
		{
			if (x == 0 || x == mlx->game.dim.x - 1 || \
			y == 0 || y == mlx->game.dim.y - 1)
			{
				if ((mlx->map[y])[x] != '1')
				{
					freeme2(mlx);
					exit(ft_putstr_fd("Not walled", 2));
				}	
			}
			x++;
		}
		y++;
	}
}

//if 2 players-> 2nd player will be replaced by empty space

int	check_p(t_vars *mlx, int *y, int *x)
{
	if (mlx->map[*y][*x] == 'P' && mlx->game.start == 0)
	{
		mlx->game.start++;
		mlx->game.pos.x = *x;
		mlx->game.pos.y = *y;
		return (0);
	}
	else if (mlx->map[*y][*x] == 'P' && mlx->game.start > 0)
	{
		mlx->map[*y][*x] = '0';
		return (0);
	}
	return (1);
}

void	check_items(t_vars *mlx)
{
	int	y;
	int	x;

	y = -1;
	while (++y < mlx->game.dim.y)
	{
		x = -1;
		while (++x < mlx->game.dim.x)
		{
			if (!check_p(mlx, &y, &x))
				continue ;
			else if (mlx->map[y][x] == 'E')
				mlx->game.exit++;
			else if (mlx->map[y][x] == 'C')
				mlx->game.collectibles++;
			else if (mlx->map[y][x] != '0' && mlx->map[y][x] != '1')
			{
				freeme2(mlx);
				exit (ft_putstr_fd("Map contains wrong characters", 2));
			}
		}
	}
}

void	full_check_map(t_vars *mlx)
{
	check_wall(mlx);
	check_items(mlx);
	if (mlx->game.start < 1 || mlx->game.collectibles < 1 || mlx->game.exit < 1)
	{
		freeme2(mlx);
		exit (ft_putstr_fd("Missing P, E or C", 2));
	}
}
