/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:21:17 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/09 21:22:26 by Debaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** print_long => Prints the long display for a file.
*/

void		print_long(char *path)
{
	struct stat		filestat;
	struct passwd	*userpswd;
	struct group	*grppswd;

	stat(path, &filestat);
	ft_putstr(perm_display(filestat));
	ft_putstr(" ");
	ft_putnbr(filestat.st_nlink);
	ft_putchar(' ');
	userpswd = getpwuid(filestat.st_uid);
	ft_putstr(userpswd->pw_name);
	ft_putstr("  ");
	grppswd = getgrgid(filestat.st_gid);
	ft_putstr(grppswd->gr_name);
	ft_putstr("  ");
	ft_putnbr(filestat.st_size);
	ft_putchar(' ');
	ft_putstr(format_date(ctime(&filestat.st_mtime)));
	ft_putchar(' ');
//  v - Ligne a modifier plus tard, fonctionne dans le cas ou le path contient './'
	ft_putendl(&path[2]);
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
	else if (S_ISLNK(mode))
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

/*
** format_date => format the date to be used in long display
*/

char		*format_date(char *date)
{
	char	*new_date;
	int		i;

	i = 0;
	new_date = (char *)malloc(sizeof(char) * 13);
	while (i < 12)
	{
		new_date[i] = date[i + 4];
		i++;
	}
	new_date[i] = '\0';
	return (new_date);
}
