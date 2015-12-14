/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 15:37:25 by klescaud          #+#    #+#             */
/*   Updated: 2015/10/20 10:17:23 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_blank(int c)
{
	return ((c == ' ' || c == '\t' || c == '\n') ? 1 : 0);
}

char			*ft_strtrim(const char *s)
{
	char	*fresh;
	int		end;
	size_t	i;

	if (!s)
		return (NULL);
	end = 0;
	i = 0;
	fresh = ft_strnew(ft_strlen(s));
	while (i < ft_strlen(s))
	{
		if (!end && ft_blank(s[i]))
			i++;
		else
			fresh[end++] = s[i++];
	}
	while (ft_blank(fresh[--end]))
		fresh[end] = '\0';
	return (fresh);
}
