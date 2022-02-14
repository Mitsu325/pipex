/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:07:37 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/14 01:31:26 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	// int		pid;
	// int		fd[2];
	// char	**path;

	ft_putstr_fd(argv[0], STDOUT);
	ft_putstr_fd("\n", STDOUT);
	if (argc != 5)
		error_handler("Bad arguments", "Ex: ./pipex file1 cmd1 cmd2 file2");
	return (EXIT_SUCCESS);
}
