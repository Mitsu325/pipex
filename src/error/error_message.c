/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:17:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 21:17:39 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The error_message() function print the error and helper message. */

#include "pipex.h"

void	error_message(char *error_msg, char *help_msg)
{
	putstr_fd("\e[91mError: ", STDERR);
	putstr_fd(error_msg, STDERR);
	putstr_fd("\n\e[0m", STDERR);
	putstr_fd("Example: ", STDOUT);
	putstr_fd(help_msg, STDOUT);
	putstr_fd("\n", STDOUT);
	exit(EX_FAILURE);
}
