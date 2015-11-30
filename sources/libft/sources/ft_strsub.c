/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 15:32:42 by klescaud          #+#    #+#             */
/*   Updated: 2015/06/12 15:35:37 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*dst;

	dst = (char *)malloc((len + 1) * sizeof(*s));
	if (dst == NULL || s == NULL)
		return (NULL);
	ft_strncpy(dst, &(s[start]), len);
	dst[len] = '\0';
	return (dst);
}
