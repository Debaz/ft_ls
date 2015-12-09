/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:21:17 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/08 14:19:17 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** print_long => Prints the long display for a file.
*/

void		print_long(char *path)
{
	struct stat		filestat;
	struct passwd	userpswd;
	struct group	grppswd;

	stat(path, &filestat);
	ft_putstr(perm_display(filestat));
	ft_putnbr(filestat.st_nlink);
	userpswd = getpwuid(filestat.st_uid);
	ft_putstr(userpswd.pw_name);
	grppswd = getgrgid(filestat.st_gid);
	ft_putstr(grppswd.gr_name);
	ft_putnbr(filestat.st_size);
	ft_putstr(ctime(filestat.st_mtime));
	ft_putendl(path);
}

/*
** file_type => defines the type of a file for the long display
*/

int			file_type(int mode)
{
	char	type;

	if (S_ISREG(mode))
		type = '-';
	else if (S_ISDIR(mode))
		type = 'd';
	else if (S_ISBLK(mode))
		type = 'b';
	else if (S_ISCHR(mode))
		type = 'c';
	else if (S_ISFIFO(mode))
		type = 'p';
	else if (S_ISLINK(mode))
		type = 'l';
	else if (S_ISSOCK(mode))
		type = 's';
	else
		type = '?';
	return (type);
}

/*
** perm_display => builds the first part of the long display
*/

char		*perm_display(struct stat filestat)
{
	char	**rwx;
	char	*bits;

	bits = (char *)malloc(sizeof(char) * 12);
	rwx = ft_strsplit("---,--x,-w-,-wx,r--,r-x,rw-,rwx", ',');
	bits[0] = file_type(filestat.st_mode);
	ft_strcpy(&bits[1], rwx[(filestat.st_mode >> 6) & 7]);
	ft_strcpy(&bits[4], rwx[(filestat.st_mode >> 3) & 7]);
	ft_strcpy(&bits[7], rwx[(filestat.st_mode & 7)]);
	if (filestat.st_mode & S_ISUID)
		bits[3] = (filestat.st_mode & 0100) ? 's' : 'S';
	if (filestat.st_mode & S_ISGID)
		bits[6] = (filestat.st_mode & 0010) ? 's' : 'S';
	if (filestat.st_mode & S_ISVTX)
		bits[9] = (filestat.st_mode & 0100) ? 't' : 'T';
	bits[10] = ' ';
	bits[11] = '\0';
//	FREETAB (rwx);
	return (bits);
}
