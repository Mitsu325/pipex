/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_safe_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:18:04 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 21:18:34 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The error_safe_exit() function print error message to the stderr and exit
the process safely. */

#include "pipex.h"

void	error_safe_exit(char **env_path)
{
	free_split(env_path);
	perror("Error");
	exit(EX_FAILURE);
}
