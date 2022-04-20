/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:43:21 by qduong            #+#    #+#             */
/*   Updated: 2022/04/20 22:53:49 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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
	mlx.win = mlx_new_window(mlx.mlx, 32, 64, "so_long");
	return (0);
}
