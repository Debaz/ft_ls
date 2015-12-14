/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_last_modified_time.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:50:49 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/14 15:50:49 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					compare_last_modified_time(struct stat *first
												, struct stat *second)
{
	return (second->st_mtimespec.tv_sec - first->st_mtimespec.tv_sec);
}
