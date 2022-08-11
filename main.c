/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:43:21 by qduong            #+#    #+#             */
/*   Updated: 2022/08/11 20:54:53 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

	// tests map by printing full grid insert end of move fkt
	// int i = 0;
	// while (i < mlx->game.dim.y)
	// {
	// 	printf(" string[%i]:%s\n", i, mlx->map[i]);
	// 	i++;
	// }

void	moveup(t_vars *mlx, char x)
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
	int i = 0;
	while (i < mlx->game.dim.y)
	{
		printf("Map string[%i]:%s", i, mlx->map[i]);
		i++;
	}
}

void	up(t_vars *mlx)
{
	printf("x-pos:%d\n", mlx->game.pos.x);
	printf("y-pos:%d\n", mlx->game.pos.y);
	printf("Char at x-pos:%d\t y-pos:%d -- %c\n", mlx->game.pos.x, \
	mlx->game.pos.y, mlx->map[mlx->game.pos.y][mlx->game.pos.x]);
	if (mlx->map[mlx->game.pos.y - 1][mlx->game.pos.x] == '0')
		moveup(mlx, '0');
	else if (mlx->map[mlx->game.pos.y - 1][mlx->game.pos.x] == '1')
	{
		ft_putstr_fd("Only ghosts can move through walls!\n", 2);
		return ;
	}
	else if (mlx->map[mlx->game.pos.y - 1][mlx->game.pos.x] == 'E')
		if (mlx->game.collectibles != 0)
		{
			ft_putstr_fd("Collect all collectibles before going to the exit!\n", 2);
			return ; // nothing happens
		}
	else
	{
		ft_printf("Moves:%d\n", mlx->game.moves + 1);
		freeme3(mlx); //exit game
	}
	else if (mlx->map[mlx->game.pos.y - 1][mlx->game.pos.x] == 'C')
		moveup(mlx, 'C');
	return ;
}

void	movedown(t_vars *mlx, char x)
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
	int i = 0;
	while (i < mlx->game.dim.y)
	{
		printf("Map string[%i]:%s", i, mlx->map[i]);
		i++;
	}
}

void	down(t_vars *mlx)
{
	printf("x-pos:%d\n", mlx->game.pos.x);
	printf("y-pos:%d\n", mlx->game.pos.y);
	printf("Char at x-pos:%d\t y-pos:%d -- %c\n", mlx->game.pos.x, \
	mlx->game.pos.y, mlx->map[mlx->game.pos.y][mlx->game.pos.x]);
	if (mlx->map[mlx->game.pos.y + 1][mlx->game.pos.x] == '0')
		movedown(mlx, '0');
	else if (mlx->map[mlx->game.pos.y + 1][mlx->game.pos.x] == '1')
	{
		ft_putstr_fd("Only ghosts can move through walls!", 2);
		return ;
	}
	else if (mlx->map[mlx->game.pos.y + 1][mlx->game.pos.x] == 'E')
		if (mlx->game.collectibles != 0)
		{
		ft_putstr_fd("Collect all collectibles before going to the exit!\n", 2);
		return; // nothing happens
		}
	else
	{
		ft_printf("Moves:%d\n", mlx->game.moves + 1);
		freeme3(mlx); //exit game
	}
	else if (mlx->map[mlx->game.pos.y + 1][mlx->game.pos.x] == 'C')
		movedown(mlx, 'C');
	return ;
}

void	moveleft(t_vars *mlx, char x)
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
	int i = 0;
	while (i < mlx->game.dim.y)
	{
		printf("Map string[%i]:%s", i, mlx->map[i]);
		i++;
	}
}

void	left(t_vars *mlx)
{
	printf("x-pos:%d\n", mlx->game.pos.x);
	printf("y-pos:%d\n", mlx->game.pos.y);
	printf("Char at x-pos:%d\t y-pos:%d -- %c\n", mlx->game.pos.x, \
	mlx->game.pos.y, mlx->map[mlx->game.pos.y][mlx->game.pos.x]);
	if (mlx->map[mlx->game.pos.y][mlx->game.pos.x - 1] == '0')
		moveleft(mlx, '0');
	else if (mlx->map[mlx->game.pos.y][mlx->game.pos.x - 1] == '1')
	{
		ft_putstr_fd("Only ghosts can move through walls!", 2);
		return ;
	}
	else if (mlx->map[mlx->game.pos.y][mlx->game.pos.x - 1] == 'E')
		if (mlx->game.collectibles != 0)
		{
			ft_putstr_fd("Collect all collectibles before going to the exit!\n", 2);
			return ; // nothing happens
		}
	else
	{
		ft_printf("Moves:%d\n", mlx->game.moves + 1);
		freeme3(mlx); //exit game
	}
	else if (mlx->map[mlx->game.pos.y][mlx->game.pos.x - 1] == 'C')
		moveleft(mlx, 'C');
	return ;
}

void	moveright(t_vars *mlx, char x)
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
	int i = 0;
	while (i < mlx->game.dim.y)
	{
		printf("Map string[%i]:%s", i, mlx->map[i]);
		i++;
	}
}

void	right(t_vars *mlx)
{
	printf("x-pos:%d\n", mlx->game.pos.x);
	printf("y-pos:%d\n", mlx->game.pos.y);
	printf("Char at x-pos:%d\t y-pos:%d -- %c\n", mlx->game.pos.x, \
	mlx->game.pos.y, mlx->map[mlx->game.pos.y][mlx->game.pos.x]);
	if (mlx->map[mlx->game.pos.y][mlx->game.pos.x + 1] == '0')
		moveright(mlx, '0');
	else if (mlx->map[mlx->game.pos.y][mlx->game.pos.x + 1] == '1')
	{
		ft_putstr_fd("Only ghosts can move through walls!", 2);
		return ;
	}
	else if (mlx->map[mlx->game.pos.y][mlx->game.pos.x + 1] == 'E')
		if (mlx->game.collectibles != 0)
		{
			ft_putstr_fd("Collect all collectibles before going to the exit!\n", 2);
			return; // nothing happens
		}
	else
	{
		ft_printf("Moves:%d\n", mlx->game.moves + 1);
		freeme3(mlx); //exit game
	}
	else if (mlx->map[mlx->game.pos.y][mlx->game.pos.x + 1] == 'C')
		moveright(mlx, 'C');
	return ;
}

int	key_hook(int key, t_vars *mlx)
{
	int i;
	i = 0;
	while (i < mlx->game.dim.y)
	{
		printf("Map string[%i]:%s", i, mlx->map[i]);
		i++;
	}
	printf("\n");
	printf("key:%d\n", key);
	if (key == ESC)
	{
		freeme3(mlx);
	}
	else if (key == UP)
		up(mlx);
	else if (key == DOWN)
		down(mlx);
	else if (key == LEFT)
		left(mlx);
	else if (key == RIGHT)
		right(mlx);
	else
		ft_putstr_fd("Use WASD to move or ESC to quit\n", 2);
	return 0;
}

int	main(int argc, char **argv)
{
	t_vars	mlx;

	if (check_input(argc, argv))
		exit(ft_putstr_fd("Run the program with\t ./so_long valid_map.ber\n", 2));
	//no malloc until this point
	init(&mlx);
	in_check_map(&argv[1], &mlx);
	//clean up to this point
	parse_map(&argv[1], &mlx);
	//clean up to this point
	full_check_map(&mlx);
	//clean up to this point
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.game.dim.x * 32, \
	mlx.game.dim.y * 32, "so_long");
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, freeme3, &mlx);
	//mlx_hook(mlx.win, 2, 0, hero_move, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
