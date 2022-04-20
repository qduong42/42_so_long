/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:43:21 by qduong            #+#    #+#             */
/*   Updated: 2022/04/19 17:48:07 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "printf/ft_printf.h"
#include "printf/gnl/get_next_line.h"
#include "so_long.h"
#include <stdio.h>

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
			return (1);
	}
	return (0);
}

size_t	ft_len(const char *s)
{
	size_t	i;

	i = 0;
	if (!s || s == NULL)
		return (1);
	while (s[i] != '\0' && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	parse_map(char **argv, t_vars *mlx)
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
		mlx->game.x = column;
		free(str);
		str = get_next_line(fd);
	}
	mlx->game.y = row;
	free(str);
	close(fd);
	return ;
}

void	check_map(char **argv, t_vars *mlx)
{
	int		fd;
	int		i;

	mlx->map = ft_calloc(mlx->game.y, sizeof(t_game *));
	i = 0;
	fd = open(*argv, O_RDONLY);
	while (i < mlx->game.y)
	{
		mlx->map[i] = get_next_line(fd);
		if (ft_len(mlx->map[i]) != (size_t)(mlx->game.x))
			exit(ft_putstr_fd("Map not straight", 2));
		i++;
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_vars	mlx;

	if (check_input(argc, argv))
		exit(ft_putstr_fd("Run the program with\t ./so_long valid_map.ber\n", 2));
	parse_map(&argv[1], &mlx);
	check_map(&argv[1], &mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 32, 64, "so_long");
	return (0);
}
