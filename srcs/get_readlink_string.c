/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_readlink_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:53:19 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/14 15:53:19 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*get_readlink_string(char *link_path)
{
	char			buffer[READLINK_BUFSIZE];
	size_t			lu;

	lu = readlink(link_path, buffer, READLINK_BUFSIZE);
	if (lu >= READLINK_BUFSIZE)
		ft_putendl_exit("Link filename too long\n", 1);
	buffer[lu] = '\0';
	return (ft_strdup(buffer));
}
