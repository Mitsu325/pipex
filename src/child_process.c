/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:31:01 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 15:33:06 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* The child_process() function modify the stdin and stdout. Execute the cmd
and the result will be used in the parent process.*/
void	child_process(char **argv, char **envp, int *fd)
{
	int	fd_input_file;

	fd_input_file = open(argv[1], O_RDONLY, MODE_RWE);
	dup2(fd_input_file, STDIN);
	dup2(fd[1], STDOUT);
	close(fd[0]);
	close(fd[1]);
	run_cmd_child(argv[2], envp);
}
