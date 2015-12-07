/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:19:54 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/07 15:23:37 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** alsort_tab => Sort a char** by alphanumerical sorting
*/

char	**alsort_tab(char **tab)
{
	int		i;
	int		sorted;
	char	*temp;

	i = 0;
	while (tab[i])
	{
		sorted = 1;
		if ((tab[i + 1]) && (ft_strcmp(tab[i], tab[i + 1])) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			sorted = 0;
		}
		i++;
		if (!sorted)
			i = 0;
	}
	return (tab);
}
