/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:14:30 by qduong            #+#    #+#             */
/*   Updated: 2022/04/24 15:35:27 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tests map by printing full grid insert end of move fkt
	// int i = 0;
	// while (i < mlx->game.dim.y)
	// {
	// 	printf("__NEW__Map string[%i]:%s\n", i, mlx->map[i]);
	// 	i++;
	// }

#include "so_long.h"

static void	moveup(t_vars *mlx, char x)
{
	if (x == '0')
	{
		mlx->map[mlx->game.pos.y - 1][mlx->game.pos.x] = 'P';
		mlx->map[mlx->game.pos.y][mlx->game.pos.x] = '0';
		mlx->game.pos.y --;
		mlx->game.moves++;
	}
	else if (x == 'C')
	{
		mlx->map[mlx->game.pos.y - 1][mlx->game.pos.x] = 'P';
		mlx->map[mlx->game.pos.y][mlx->game.pos.x] = '0';
		mlx->game.pos.y --;
		mlx->game.collectibles --;
		mlx->game.moves++;
	}
}

//add at start of down fkt to test
	// printf("x-pos:%d\n", mlx->game.pos.x);
	// printf("y-pos:%d\n", mlx->game.pos.y);
	// printf("Char at x-pos:%d\t y-pos:%d -- %c\n", 
	//mlx->game.pos.x, mlx->game.pos.y, 
	//mlx->map[mlx->game.pos.y][mlx->game.pos.x]);

void	up(t_vars *mlx)
{
	if (mlx->map[mlx->game.pos.y - 1][mlx->game.pos.x] == '0')
		moveup(mlx, '0');
	else if (mlx->map[mlx->game.pos.y - 1][mlx->game.pos.x] == '1')
	{
		ft_putstr_fd("Only ghosts can move through walls!", 2);
		return ;
	}
	else if (mlx->map[mlx->game.pos.y - 1][mlx->game.pos.x] == 'E')
	{
		if (mlx->game.collectibles != 0)
			return ;
		else
		{
			ft_printf("Moves:%d\n", mlx->game.moves + 1);
			freeme3(mlx);
		}
	}
	else if (mlx->map[mlx->game.pos.y - 1][mlx->game.pos.x] == 'C')
		moveup(mlx, 'C');
	return ;
}

static void	movedown(t_vars *mlx, char x)
{
	if (x == '0')
	{
		mlx->map[mlx->game.pos.y + 1][mlx->game.pos.x] = 'P';
		mlx->map[mlx->game.pos.y][mlx->game.pos.x] = '0';
		mlx->game.pos.y ++;
		mlx->game.moves++;
	}
	else if (x == 'C')
	{
		mlx->map[mlx->game.pos.y + 1][mlx->game.pos.x] = 'P';
		mlx->map[mlx->game.pos.y][mlx->game.pos.x] = '0';
		mlx->game.pos.y ++;
		mlx->game.collectibles --;
		mlx->game.moves++;
	}
}
//add at start of down fkt to test
	// printf("x-pos:%d\n", mlx->game.pos.x);
	// printf("y-pos:%d\n", mlx->game.pos.y);
	// printf("Char at x-pos:%d\t y-pos:%d -- %c\n", 
	//mlx->game.pos.x, mlx->game.pos.y, 
	//mlx->map[mlx->game.pos.y][mlx->game.pos.x]);

void	down(t_vars *mlx)
{
	if (mlx->map[mlx->game.pos.y + 1][mlx->game.pos.x] == '0')
		movedown(mlx, '0');
	else if (mlx->map[mlx->game.pos.y + 1][mlx->game.pos.x] == '1')
	{
		ft_putstr_fd("Only ghosts can move through walls!", 2);
		return ;
	}
	else if (mlx->map[mlx->game.pos.y + 1][mlx->game.pos.x] == 'E')
	{
		if (mlx->game.collectibles != 0)
			return ;
		else if (mlx->game.collectibles == 0)
		{
			ft_printf("Moves:%d\n", mlx->game.moves + 1);
			freeme3(mlx);
		}
	}
	else if (mlx->map[mlx->game.pos.y + 1][mlx->game.pos.x] == 'C')
		movedown(mlx, 'C');
	return ;
}