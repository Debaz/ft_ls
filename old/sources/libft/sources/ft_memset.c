/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 16:14:18 by klescaud          #+#    #+#             */
/*   Updated: 2015/06/01 16:19:18 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)b;
	while (i < (int)len)
	{
		str[i] = (char)c;
		i++;
	}
	return (b);
}
