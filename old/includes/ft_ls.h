/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:52:08 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/10 10:44:03 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <stdio.h>
# include <time.h>

/*
** s_directory usage :
** name => Contains the name of the current directory;
** subdir => Contains the name of all subdirectories;
** file => Contains the name of all files and subdirectories;
** next => Chained list pointer.
*/

typedef	struct			s_directory
{
	char				*name;
	char				**subdir;
	char				**file;
	struct s_directory	*next;
}						t_directory;

/*
** dir_list.c
*/

t_directory				*build_list(t_directory *list, char *dirname);
t_directory				*add_dir(t_directory *list, char *dirname);
char					**find_subdirs(char *dirname, char *path);
char					**find_files(const char *dirname);
int						is_hidden(char *file);

/*
** sort_tab.c
*/

char					**alsort_tab(char **tab);
char					**rev_alsort_tab(char **tab);
char					**timesort_tab(char **tab, char *path);
char					**rev_timesort_tab(char **tab, char *path);
int						file_datecmp(char *file1, char *file2, char *path);

/*
** display.c
*/

void					print_long(char *path);
int						file_type(int mode);
char					*perm_display(struct stat filestat);
char					*format_date(char *date);
void					print_size(int size);

#endif
