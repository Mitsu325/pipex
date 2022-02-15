/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:10:13 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/14 22:10:13 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strlen() function calculates the length of the character string 'str', 
without count the trailing "\0" null byte.
*/
/* Returns the number of characters in the string s.
*/

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}
