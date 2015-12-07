/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:52:19 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/07 12:34:09 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		main(int ac, char **av)
{
	char	**file_list;
//	int		i;
//	int		a;

//	a = 0;
	if (ac > 1)
	{
//		i = 0;
		file_list = find_files(av[1]);
/*		while (file_list[i])
		{
			while (a == 0 && (file_list[i][0] == '.'))
				i++;
			ft_putendl(file_list[i]);
			i++;
			} */
	}
	return (0);
}
