/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:52:19 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/04 15:17:19 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		main(int ac, char **av)
{
	DIR		*file_des;
	struct dirent	*current;
	struct stat		sb;
	struct group	*pwd;

	file_des = opendir("./sources");
	if (ac == 2)
		av[1] = NULL;
	current = readdir(file_des);
	ft_putendl(current->d_name);
	stat(ft_strjoin("./sources/", current->d_name), &sb);
/*	ft_putstr("UID = ");
	ft_putnbr((int)sb.st_uid);
	ft_putendl("");
	ft_putstr("GID = ");
	ft_putnbr((int)sb.st_gid);
	ft_putendl("");
	ft_putstr("NLINK = ");
	ft_putnbr((int)sb.st_nlink);
	ft_putendl("");
	ft_putstr("SIZE = ");
	ft_putnbr((int)sb.st_size); */
	pwd = getgrgid(sb.st_gid);
	ft_putendl(pwd->gr_name);
	closedir(file_des);
	return (0);
}
