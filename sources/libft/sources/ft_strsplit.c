/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Debaz <klescaud@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 17:19:55 by Debaz             #+#    #+#             */
/*   Updated: 2015/10/19 13:48:17 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_wordsize(const char *s, char c)
{
	size_t	size;

	size = 0;
	while (*s && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

size_t	ft_countwords(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	size_t	nb_words;
	size_t	i;
	size_t	word_size;

	if (!s)
		return (NULL);
	nb_words = ft_countwords(s, c);
	if ((ptr = malloc((nb_words + 1) * sizeof(char *))) == NULL)
		return (NULL);
	i = 0;
	while (i < nb_words && *s)
	{
		while (*s == c)
			s++;
		word_size = ft_wordsize(s, c);
		if ((ptr[i] = malloc((word_size + 1) * sizeof(char))) == NULL)
			return (NULL);
		ft_strncpy(ptr[i], s, word_size);
		ptr[i][word_size] = '\0';
		s += word_size;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
