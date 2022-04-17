/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:43:21 by qduong            #+#    #+#             */
/*   Updated: 2022/04/17 13:04:44 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "printf/ft_printf.h"
#include "so_long.h"
#include <stdio.h>

int	check_argc(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		exit(write(1, "Run the program with\t ./so_long valid_map.ber\n", 47));
	i = ft_strlen(argv[1]);
	if (i == 0)
		exit(write(1, "Run the program with\t ./so_long valid_map.ber\n", 47));
	return (0);
}

//i[0] = strlen of second argument
//i[1] = counter for last string index
//i[2] = index to check last position of a[4]

int	check_input(int argc, char **argv)
{
	int		i[3];
	char	a[4];

	check_argc(argc, argv);
	i[2] = 3;
	a[0] = '.';
	a[1] = 'b';
	a[2] = 'e';
	a[3] = 'r';
	i[0] = ft_strlen(argv[1]);
	i[1] = 1;
	while (argv[1][i[0] - i[1]] && i[2] >= 0 && i[1] <= 4)
	{
		if (argv[1][i[0] - i[1]] == a[i[2]])
		{
			i[1]++;
			i[2]--;
		}
		else
			exit(write(1, "Run the program with\t\
			./so_long valid_map.ber\n", 49));
	}
	return (write(1, "Opening file will be attempted", 31));
}

void	parse_map(char **argv)
{
	
	return ;
}

int	main(int argc, char **argv)
{
	t_vars	mlx;

	check_input(argc, argv);
	parse_map(argv);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 32, 64, "so_long");
	return (0);
}
