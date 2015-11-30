/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 16:07:23 by klescaud          #+#    #+#             */
/*   Updated: 2015/06/12 16:49:31 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tmp_d;
	char		*tmp_s;
	const char	*tmp;

	i = 0;
	tmp_d = dst;
	tmp = src;
	tmp_s = malloc(sizeof(char) * n);
	while (i < n)
	{
		tmp_s[i] = tmp[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		tmp_d[i] = tmp_s[i];
		i++;
	}
	free(tmp_s);
	return (dst);
}
