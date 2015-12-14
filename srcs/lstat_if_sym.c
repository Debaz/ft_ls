/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstat_if_sym.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:51:57 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/14 15:51:57 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stat				*lstat_if_sym(t_entry *entry)
{
	if (entry->is_symlink)
		return (entry->lstat);
	else
		return (entry->stat);
}
