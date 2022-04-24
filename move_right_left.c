/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:11:34 by qduong            #+#    #+#             */
/*   Updated: 2022/04/24 15:35:13 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// tests map by printing full grid insert end of move fkt
	// int i = 0;
	// while (i < mlx->game.dim.y)
	// {
	// 	printf("__NEW__Map string[%i]:%s\n", i, mlx->map[i]);
	// 	i++;
	// }

static void	moveleft(t_vars *mlx, char x)
{
	if (x == '0')
	{
		mlx->map[mlx->game.pos.y][mlx->game.pos.x - 1] = 'P';
		mlx->map[mlx->game.pos.y][mlx->game.pos.x] = '0';
		mlx->game.pos.x --;
		mlx->game.moves++;
	}
	else if (x == 'C')
	{
		mlx->map[mlx->game.pos.y][mlx->game.pos.x - 1] = 'P';
		mlx->map[mlx->game.pos.y][mlx->game.pos.x] = '0';
		mlx->game.pos.x --;
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

void	left(t_vars *mlx)
{
	if (mlx->map[mlx->game.pos.y][mlx->game.pos.x - 1] == '0')
		moveleft(mlx, '0');
	else if (mlx->map[mlx->game.pos.y][mlx->game.pos.x - 1] == '1')
	{
		ft_putstr_fd("Only ghosts can move through walls!", 2);
		return ;
	}
	else if (mlx->map[mlx->game.pos.y][mlx->game.pos.x - 1] == 'E')
	{
		if (mlx->game.collectibles != 0)
			return ;
		else
		{
			ft_printf("Moves:%d\n", mlx->game.moves + 1);
			freeme3(mlx);
		}
	}
	else if (mlx->map[mlx->game.pos.y][mlx->game.pos.x - 1] == 'C')
		moveleft(mlx, 'C');
	return ;
}

static void	moveright(t_vars *mlx, char x)
{
	if (x == '0')
	{
		mlx->map[mlx->game.pos.y][mlx->game.pos.x + 1] = 'P';
		mlx->map[mlx->game.pos.y][mlx->game.pos.x] = '0';
		mlx->game.pos.x ++;
		mlx->game.moves++;
	}
	else if (x == 'C')
	{
		mlx->map[mlx->game.pos.y][mlx->game.pos.x + 1] = 'P';
		mlx->map[mlx->game.pos.y][mlx->game.pos.x] = '0';
		mlx->game.pos.x ++;
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

void	right(t_vars *mlx)
{
	if (mlx->map[mlx->game.pos.y][mlx->game.pos.x + 1] == '0')
		moveright(mlx, '0');
	else if (mlx->map[mlx->game.pos.y][mlx->game.pos.x + 1] == '1')
	{
		ft_putstr_fd("Only ghosts can move through walls!", 2);
		return ;
	}
	else if (mlx->map[mlx->game.pos.y][mlx->game.pos.x + 1] == 'E')
	{
		if (mlx->game.collectibles != 0)
			return ;
		else
		{
			ft_printf("Moves:%d\n", mlx->game.moves + 1);
			freeme3(mlx);
		}
	}
	else if (mlx->map[mlx->game.pos.y][mlx->game.pos.x + 1] == 'C')
		moveright(mlx, 'C');
	return ;
}