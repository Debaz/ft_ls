/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 10:22:06 by klescaud          #+#    #+#             */
/*   Updated: 2015/10/20 10:32:23 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t		ft_nblen(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char				*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nblen(n);
	if (!(str = (char *)malloc((len + 1) * sizeof(*str))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len] = '\0';
	while (n >= 10)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	str[len - 1] = n + '0';
	return (str);
}
