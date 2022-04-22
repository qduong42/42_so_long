/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:35:21 by qduong            #+#    #+#             */
/*   Updated: 2022/04/22 19:13:21 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	init(t_vars *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->map = NULL;
	mlx->game.dim.x = 0;
	mlx->game.dim.y = 0;
	mlx->game.pos.x = 0;
	mlx->game.pos.y = 0;
	mlx->game.space = 0;
	mlx->game.start = 0;
	mlx->game.exit = 0;
	mlx->game.collectibles = 0;
	mlx->game.moves = 0;
}

int	check_argc(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		exit(ft_putstr_fd("Run the program with\t ./so_long valid_map.ber\n", 2));
	i = ft_strlen(argv[1]);
	if (i == 0)
		exit(ft_putstr_fd("Run the program with\t ./so_long valid_map.ber\n", 2));
	return (0);
}

//i[0] = strlen of second argument
//i[1] = counter for last string index
//i[2] = index to check last dimition of a[4]

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
			return (1);
	}
	return (0);
}

void	in_check_map(char **argv, t_vars *mlx)
{
	int		fd;
	char	*str;
	int		row;
	int		column;

	row = 0;
	fd = open(*argv, O_RDONLY);
	if (fd < 0)
		exit(ft_putstr_fd("Invalid map", 2));
	str = get_next_line(fd);
	while (str)
	{
		column = ft_len(str);
		row++;
		mlx->game.dim.x = column;
		free(str);
		str = get_next_line(fd);
	}
	mlx->game.dim.y = row;
	free(str);
	close(fd);
	if (row < 2)
		exit(ft_putstr_fd("Not enough characters in .ber to create map\n", 2));
	return ;
}
