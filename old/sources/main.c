/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:52:19 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/09 21:21:58 by Debaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		main(int ac, char **av)
{
	char	**files;
	int		i;

	if (ac > 1)
	{
		i = 0;
		files = find_files(av[1]);
		files = alsort_tab(files);
		files = timesort_tab(files, ft_strjoin(av[1], "/"));
		while (files[i])
		{
			if (files[i][0] != '.')
				print_long(ft_strjoin(ft_strjoin(av[1],"/"), files[i]));
			i++;
		}
	}
	return (0);
}
