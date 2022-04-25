/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:29:25 by qduong            #+#    #+#             */
/*   Updated: 2022/04/25 14:29:48 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_error(char *s)
{
	write(STDERR_FILENO, "Error\n", 6);
	ft_putstr_fd(s, STDERR_FILENO);
	return (-1);
}
