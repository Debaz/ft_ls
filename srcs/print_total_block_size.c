/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total_block_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:52:30 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/14 15:52:30 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_total_block_size(t_list *entries)
{
	unsigned long long	total;
	char				*string;

	total = 0;
	while (entries)
	{
		total += lstat_if_sym(((t_entry*)entries->data))->st_blocks;
		entries = entries->next;
	}
	ft_putstr("total ");
	string = ft_itoa_ularge(total);
	ft_putstr(string);
	free(string);
	ft_putchar('\n');
}
