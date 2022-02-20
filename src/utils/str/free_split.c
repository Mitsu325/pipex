/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:38:30 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 21:38:42 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The free_split() function dynamically de-allocate the memory from a table.*/

#include "pipex.h"

void	free_split(char **table)
{
	int	i;

	i = 0;
	if (!table)
		return ;
	while (*(table + i))
		free(*(table + i++));
	free(table);
}
