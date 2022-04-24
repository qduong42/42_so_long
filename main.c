/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:43:21 by qduong            #+#    #+#             */
/*   Updated: 2022/04/24 15:18:14 by qduong           ###   ########.fr       */
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
		ft_putstr_fd("Use WASD to move or ESC to quit\n", 2);
	return (0);
}

	//mlx_hook(mlx.win, 2, 0, hero_move, &mlx); Can be used instead
	//keyhook because 2 is key input

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
	mlx_loop(mlx.mlx);
	return (0);
}
