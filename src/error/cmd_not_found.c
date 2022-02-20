/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_not_found.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:33:04 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 21:34:17 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_not_found(char **cmd, int pid)
{
	putstr_fd(cmd[0], STDERR);
	free_split(cmd);
	putstr_fd(": ", STDERR);
	putstr_fd("command not found", 2);
	putstr_fd("\n", 2);
	if (pid)
		exit(DEL);
}
