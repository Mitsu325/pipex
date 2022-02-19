/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:29:40 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 19:30:04 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strnstr() function locates the first occurrence of the null-terminated 
string 'find' in the string 'str', where not more than 'len' characters are 
searched. */
/* If 'find' is an empty string, 'str' is returned; if 'find' occurs nowhere in
'str', NULL is returned; otherwise a pointer to the first character of the first
occurrence of 'find' is returned. */

#include "pipex.h"

char	*strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (*find == '\0')
		return ((char *)str);
	i = 0;
	while (*(str + i) && i < len)
	{
		j = 0;
		while (i + j < len && *(str + i + j) == *(find + j))
		{
			if (*(find + j + 1) == '\0')
				return ((char *)(str + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
