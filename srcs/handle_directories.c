/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_directories.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:53:54 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/14 15:53:54 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_folder_name_before(char *folder_name
												, t_options *options)
{
	if (options->printed_folder_already)
		ft_putstr("\n");
	ft_putstr(folder_name);
	ft_putstr(":\n");
	options->printed_folder_already = 1;
}

void				handle_directories(t_list *folder_name
										, t_list *directory
										, t_options *options)
{
	char			*string;
	t_bool			print_folder;

	while (folder_name)
	{
		string = (char*)folder_name->data;
		print_folder = should_print_folder(string, options);
		if (options->print_folder_names_before && print_folder)
			print_folder_name_before(string, options);
		if (directory->data)
			handle_directory(string, (t_list*)directory->data, print_folder
							, options);
		folder_name = folder_name->next;
		directory = directory->next;
	}
}
