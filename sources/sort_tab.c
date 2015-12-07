/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:19:54 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/07 14:35:02 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	**alsort_tab(char **tab)
{
	int		i;
	int		sorted;

	i = 0;
	while (tab[i])
	{
		sorted = 1;
		if ((tab[i + 1]) && ft_strcmp(tab[i], tab[i + 1]))
		{
			swap_tab_lines(&tab[i], &tab[i + 1]);
			sorted = 0;
		}
		i++;
		if (!sorted)
			i = 0;
	}
	return (tab);
}

void	swap_tab_lines(char **s1, char **s2)
{
	char	**tmp;

	tmp = NULL;
	*tmp = *s1;
	s1 = s2;
	*s2 = *tmp;
	free(tmp);
}
