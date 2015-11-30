/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 11:43:04 by klescaud          #+#    #+#             */
/*   Updated: 2015/10/19 12:23:01 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_mini_atoi(char c)
{
	return (c - '0');
}

static char		*ft_strverif(char *str)
{
	int		i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\r' ||
		str[i] == '\t' || str[i] == '\v' || str[i] == '\f') &&
		str[i] != '\0')
		i++;
	if (str[i] != '+' && str[i] != '-' && !ft_isdigit(str[i]))
		return (NULL);
	return (&str[i]);
}

int				ft_atoi(const char *str)
{
	char	*tmp;
	int		res;
	int		i;

	res = 0;
	i = 0;
	if ((tmp = ft_strverif((char *)str)) == NULL)
		return (0);
	if (tmp[0] == '-' || tmp[0] == '+')
		i++;
	while (tmp[i])
	{
		if (!ft_isdigit(tmp[i]))
			break ;
		res *= 10;
		res = res + ft_mini_atoi(tmp[i]);
		i++;
	}
	if (tmp[0] == '-')
		return (-res);
	return (res);
}
