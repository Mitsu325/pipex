/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:10:36 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 19:30:55 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The putstr_fd() function write string 'str' to the given file descriptor. */

#include "pipex.h"

void	putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
	{
		putchar_fd(*str, fd);
		str++;
	}
}
