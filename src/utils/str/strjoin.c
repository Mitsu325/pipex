/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:16:34 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 19:30:04 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strjoin() function allocates (with malloc) and returns a new string,
which is the result of the concatenation of 's1' and 's2'. */
/* Return the new string. NULL if the allocation fails. */

#include "pipex.h"

char	*strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_str)
		return(NULL);
	i = 0;
	j = 0;
	while (*(s1 + i))
	{
		*(new_str + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j))
	{
		*(new_str + i) = *(s2 + j);
		i++;
		j++;
	}
	*(new_str + i) = '\0';
	return (new_str);
}
