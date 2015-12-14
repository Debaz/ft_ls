/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:54:45 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/14 15:54:46 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_arrow_to_symlink(t_entry *entry)
{
	char			buffer[READLINK_BUFSIZE];

	if (entry->is_symlink)
	{
		ft_putstr(" -> ");
		write(1, buffer, readlink(entry->long_name, buffer, READLINK_BUFSIZE));
	}
}

void				print_entry(t_entry *entry, t_options *options
								, t_strlens *strlens)
{
	if (options->long_format)
	{
		print_file_options(entry, strlens);
		ft_putchar(' ');
		ft_putstr(entry->short_name);
		print_arrow_to_symlink(entry);
		ft_putchar('\n');
	}
	else
		ft_putendl(entry->short_name);
}
