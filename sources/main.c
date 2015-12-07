/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:52:19 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/07 15:19:59 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		main(int ac, char **av)
{
	char	**file_list;
	int		i;

	if (ac > 1)
	{
		i = 0;
		file_list = find_files(av[1]);
		file_list = alsort_tab(file_list);
		while (file_list[i])
		{
			ft_putendl(file_list[i]);
			i++;
		}
	}
	return (0);
}
