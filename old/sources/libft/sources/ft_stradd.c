/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 14:48:57 by klescaud          #+#    #+#             */
/*   Updated: 2015/10/19 13:50:31 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_stradd(char *s1, char s2)
{
	char	*temp;

	temp = malloc(sizeof(char) * ft_strlen(s1) + 2);
	temp = ft_strcpy(temp, s1);
	temp[ft_strlen(s1)] = s2;
	temp[ft_strlen(s1) + 1] = '\0';
	return (temp);
}
