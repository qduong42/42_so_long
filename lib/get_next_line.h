/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:55:10 by qduong            #+#    #+#             */
/*   Updated: 2022/04/25 14:39:29 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

void		ft_bzero(void *s, size_t n);
void		*ft_gmemmove(void *dest, const void *src, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_nlen(const char *s);
int			ft_gnl_strrchr(const char *s, int c);
char		*get_next_line(int fd);
int			ft_put_error(char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# define MAX_FD 1024

#endif
