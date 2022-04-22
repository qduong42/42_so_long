/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:21:22 by qduong            #+#    #+#             */
/*   Updated: 2022/04/18 14:18:25 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_gmemmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	{
		while (n)
		{
			d[i] = s[i];
			i++;
			n--;
		}
	}
	return (dest);
}

int	ft_gnl_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
		{
			i++;
			return (i);
		}
		i++;
	}
	return (0);
}

size_t	ft_nlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}
