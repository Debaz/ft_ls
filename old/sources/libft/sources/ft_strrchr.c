/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 16:35:46 by klescaud          #+#    #+#             */
/*   Updated: 2015/06/12 16:39:42 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*occ;

	i = 0;
	occ = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			occ = (char *)&str[i];
		i++;
	}
	if (str[i] == c)
		occ = (char *)&str[i];
	if (occ != NULL)
		return (occ);
	else
		return (0);
}
