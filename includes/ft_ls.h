/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:52:08 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/07 15:28:59 by klescaud         ###   ########.fr       */
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

t_directory				*add_dir(t_directory *list, char *dirname);
char					**find_subdirs(char *dirname, char *path);
char					**find_files(const char *dirname);

/*
** sort_tab.c
*/

char					**alsort_tab(char **tab);

#endif
