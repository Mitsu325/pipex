/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:21:01 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/17 19:49:36 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* The error_message() function print the error and helper message. */
void	error_message(char *error_msg, char *help_msg)
{
	ft_putstr_fd("\e[91mError: ", STDERR);
	ft_putstr_fd(error_msg, STDERR);
	ft_putstr_fd("\n\e[0m", STDERR);
	ft_putstr_fd("Example: ", STDOUT);
	ft_putstr_fd(help_msg, STDOUT);
	ft_putstr_fd("\n", STDOUT);
	exit(EXIT_FAILURE);
}

/* The error_safe_exit() function print error message to the stderr and exit
the process safely.
*/
void	error_safe_exit(char **env_path)
{
	free_split(env_path);
	perror("Error");
	exit(EXIT_FAILURE);
}
