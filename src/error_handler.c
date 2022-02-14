/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:21:01 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/14 01:31:56 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handler(char *error_msg, char *help_msg)
{
	ft_putstr_fd("\e[91mError: ", STDERR);
	ft_putstr_fd(error_msg, STDERR);
	ft_putstr_fd("\n\e[0m", STDERR);
	ft_putstr_fd(help_msg, STDOUT);
	ft_putstr_fd("\n", STDOUT);
	exit(EXIT_FAILURE);
}
