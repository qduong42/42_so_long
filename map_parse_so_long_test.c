/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_so_long_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:32:45 by qduong            #+#    #+#             */
/*   Updated: 2022/04/18 23:48:01 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/gnl/get_next_line.h"
#include "printf/ft_printf.h"
#include "so_long.h"

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


int	main(void)
{
	int		fd;
	char	*str;
	int		row;
	int		column;

	row = 0;
	*str = "";
	fd = open("maps/.ber", O_RDONLY);
	if (fd < 0)
		write(1, "Invalid map", 12);
	while (str)
	{
		str = get_next_line(fd);
		column = ft_strlen(str);
		row ++;
	}
	close(fd);
	return (0);
}
