/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:17:37 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 19:30:04 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The putchar_fd() function write char 'ch' to the given file descriptor. */

#include "pipex.h"

void	putchar_fd(char ch, int fd)
{
	write(fd, &ch, 1);
}
