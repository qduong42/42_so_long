/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:21:30 by qduong            #+#    #+#             */
/*   Updated: 2022/04/18 14:18:45 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	newstring = malloc(sizeof(char) * (ft_nlen(s1) + ft_nlen(s2) + 1));
	if (!newstring)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstring[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		newstring[i++] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
		newstring[i++] = s2[j];
	newstring[i] = '\0';
	return (newstring);
}

static char	*ft_bufnchecksplit(char	*returnline, char	*buf)
{
	int		index;
	char	*temp;
	int		len;

	len = 0;
	index = 0;
	index = ft_gnl_strrchr (buf, '\n');
	if (index != 0)
	{
		temp = ft_strjoin(returnline, buf);
		free (returnline);
		returnline = temp;
		while (buf[len])
			len++;
		ft_gmemmove(buf, buf + index, len - index);
		ft_bzero(buf + len - index, 1);
	}
	return (returnline);
}

static char	*ft_bufjoin(char *returnline, char *buf)
{
	char	*temp;

	temp = ft_strjoin(returnline, buf);
	free (returnline);
	returnline = temp;
	ft_bzero(buf, BUFFER_SIZE);
	return (returnline);
}

static char	*freeme(int bytes_read, char *returnline)
{
	if (bytes_read <= 0 && !(*returnline))
	{
		free(returnline);
		return (NULL);
	}
	return (returnline);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*returnline;
	char		*temp;
	int			bytes_read;

	returnline = ft_calloc(1, sizeof(char));
	temp = "";
	while (!ft_gnl_strrchr(buf, '\n'))
	{
		if (*buf)
		{
			returnline = ft_bufjoin(returnline, buf);
		}
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		returnline = freeme(bytes_read, returnline);
		if (bytes_read < BUFFER_SIZE && !ft_gnl_strrchr(buf, '\n'))
		{
			returnline = ft_bufjoin(returnline, buf);
			return (returnline);
		}
	}
	returnline = ft_bufnchecksplit(returnline, buf);
	return (returnline);
}

//accounting for case where buf contains \n
//52-62 put in sub-function by passing buf and returnline