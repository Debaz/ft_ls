/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 15:08:11 by klescaud          #+#    #+#             */
/*   Updated: 2015/06/12 15:09:49 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		index;

	if (s && f)
	{
		index = 0;
		while (*s)
		{
			f(index, s);
			index++;
			s++;
		}
	}
}
