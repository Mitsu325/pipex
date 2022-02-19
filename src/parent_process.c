/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:31:17 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 15:37:12 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* The parent_process() function modify the stdin and stdout. Execute the cmd
with the result of the child process as input value.*/
void	parent_process(char **argv, char **envp, int *fd)
{
	int	fd_output_file;
	int run_cmd_status;

	fd_output_file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, MODE_RWE);
	if (fd_output_file == -1)
		error_exit();
	dup2(fd[0], STDIN);
	dup2(fd_output_file, STDOUT);
	close(fd[0]);
	close(fd[1]);
	run_cmd_status = run_cmd_parent(argv[3], envp);
	if (run_cmd_status)
	{
		write(1, "", 1);
		exit(EXIT_FAILURE);
	}
}