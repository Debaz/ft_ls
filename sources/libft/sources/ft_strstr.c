/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 16:39:51 by klescaud          #+#    #+#             */
/*   Updated: 2015/06/12 16:43:16 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	len;

	if (*to_find)
	{
		len = ft_strlen(to_find);
		while (ft_strncmp(str, to_find, len) != 0)
		{
			if (*str == '\0')
				return (NULL);
			str++;
		}
	}
	return ((char *)str);
}
