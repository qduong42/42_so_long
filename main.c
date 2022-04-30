/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:43:21 by qduong            #+#    #+#             */
/*   Updated: 2022/04/26 18:10:45 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Insert to line 26- 27 to test
	// int i;
	// i = 0;
	// while (i < mlx->game.dim.y)
	// {
	// 	printf("Map string[%i]:%s", i, mlx->map[i]);
	// 	i++;
	// }
	// printf("\n");
	// printf("key:%d\n", key);

int	key_hook(int key, t_vars *mlx)
{
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
		ft_putendl_fd("Use WASD to move or ESC to quit", 2);
	return (0);
}

	//mlx_hook(mlx.win, 2, 0, hero_move, &mlx); Can be used instead
	//keyhook because 2 is key input

void	load(t_vars *mlx)
{
	mlx -> wall = mlx_xpm_file_to_image(mlx->mlx, \
	"images/wall.xpm", &mlx->imgx, &mlx->imgy);
	mlx -> collect = mlx_xpm_file_to_image(mlx->mlx, \
	"images/qi_tatami.xpm", &mlx->imgx, &mlx->imgy);
	mlx -> player = mlx_xpm_file_to_image(mlx->mlx, \
	"images/P2.xpm", &mlx->imgx, &mlx->imgy);
	mlx -> exit = mlx_xpm_file_to_image(mlx->mlx, \
	"images/exit_tatami.xpm", &mlx->imgx, &mlx->imgy);
	mlx->space = mlx_xpm_file_to_image(mlx->mlx, \
	"images/tatami.xpm", &mlx->imgx, &mlx->imgy);
}

void	put_stuff(t_vars *mlx, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, \
		x * mlx->imgx, y * mlx->imgy);
	else if (c == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->collect, \
	x * mlx->imgx, y * mlx->imgy);
	else if (c == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player, \
	x * mlx->imgx, y * mlx->imgy);
	else if (c == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, \
	x * mlx->imgx, y * mlx->imgy);
	else if (c == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->space, \
	x * mlx->imgx, y * mlx->imgy);
}

void	gib_image(t_vars *mlx)
{
	int	x;
	int	y;

	load(mlx);
	y = -1;
	while (++y < mlx->game.dim.y)
	{
		x = -1;
		while (++x < mlx->game.dim.x)
		{
			if (mlx->map[y][x] == '1')
				put_stuff(mlx, x, y, '1');
			if (mlx->map[y][x] == 'C')
				put_stuff(mlx, x, y, 'C');
			if (mlx->map[y][x] == 'P')
				put_stuff(mlx, x, y, 'P');
			if (mlx->map[y][x] == 'E')
				put_stuff(mlx, x, y, 'E');
			else if (mlx->map[y][x] == '0')
				put_stuff(mlx, x, y, '0');
		}
	}
}

int	main(int argc, char **argv)
{
	t_vars	mlx;

	if (check_input(argc, argv))
		exit(ft_put_error(("Run the program with\t ./so_long valid_map.ber")));
	init(&mlx);
	in_check_map(&argv[1], &mlx);
	parse_map(&argv[1], &mlx);
	full_check_map(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.game.dim.x * 32, \
	mlx.game.dim.y * 32, "geemu");
	gib_image(&mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, freeme3, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
