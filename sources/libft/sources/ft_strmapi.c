/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 15:26:06 by klescaud          #+#    #+#             */
/*   Updated: 2015/06/12 15:27:59 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*dst;
	int		i;

	if (s && f)
	{
		dst = ft_strnew(ft_strlen(s));
		i = 0;
		while (s[i])
		{
			dst[i] = f(i, s[i]);
			i++;
		}
		return (dst);
	}
	return (NULL);
}
