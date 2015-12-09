/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:52:19 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/09 14:57:25 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		main(int ac, char **av)
{
	t_directory	*list;
	int			i;

	list = NULL;
	if (ac > 1)
	{
		list = build_list(list, av[1]);
		while (list->next != NULL)
		{
			i = 0;
			while (list->file[i])
			{
				ft_putendl(list->file[i]);
				i++;
			}
			list = list->next;
		}
	}
	return (0);
}
