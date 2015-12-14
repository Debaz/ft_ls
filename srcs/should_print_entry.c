/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_print_entry.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:53:40 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/14 15:53:40 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** The 42 norm does not allow for multiple lines in return
** statements.
*/

t_bool				should_print_entry(t_entry *entry, t_options *options)
{
	t_bool			bleh;

	bleh = *entry->short_name != '.'
		|| options->show_all
		|| options->handling_screwups;
	return (bleh);
}
