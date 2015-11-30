/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Debaz <klescaud@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 17:48:45 by Debaz             #+#    #+#             */
/*   Updated: 2015/06/03 17:52:50 by Debaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if ((str = malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
