/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 14:48:46 by klescaud          #+#    #+#             */
/*   Updated: 2015/05/27 12:47:17 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrev(char *s)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strdup(s);
	while (s[i])
	{
		temp[(ft_strlen(s) - 1) - i] = s[i];
		i++;
	}
	s = ft_strcpy(s, temp);
	return (s);
}
