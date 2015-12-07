/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:14:18 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/07 12:34:31 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** add_dir => Adds a new element to the list.
*/

t_directory	*add_dir(t_directory *list, char *dirname)
{
	t_directory	*temp;
	t_directory *new;

	if ((new = malloc(sizeof(t_directory))) == NULL)
		return (NULL);
	new->name = dirname;
	new->subdir = find_subdirs(dirname);
	new->file = find_files(dirname);
	new->next = NULL;
	if (list == NULL)
		return (new);
	else
	{
		temp = list;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		return (list);
	}
}

/*
** find_subdirs => lists all the subdirs of a directory.
*/

char	**find_subdirs(char *dirname)
{
	DIR				*fd;
	struct dirent	*file;
	char			*file_list;
	struct stat		*file_stat;

	fd = opendir(dirname);
	file_list = ft_strnew(0);
	file_stat = malloc(sizeof(struct stat));
	if ((file = malloc(sizeof(struct dirent))) == NULL)
		return (NULL);
	while ((file = readdir(fd)) != NULL)
	{
		stat(ft_strjoin("./", file->d_name), file_stat);
		if (S_ISDIR(file_stat->st_mode))
		{
			file_list = ft_strjoin(file_list, " ");
			file_list = ft_strjoin(file_list, file->d_name);
			printf("%s\n", file->d_name);
		}
	}
	closedir(fd);
	return (ft_strsplit(file_list, ' '));
}

/*
** find_files => lists all the files and subdirs that the directory contains.
*/

char	**find_files(const char *dirname)
{
	DIR				*fd;
	struct dirent	*file;
	char			*file_list;

	fd = opendir(dirname);
	file_list = ft_strnew(0);
	if ((file = malloc(sizeof(struct dirent))) == NULL)
		return (NULL);
	while ((file = readdir(fd)) != NULL)
	{
		file_list = ft_strjoin(file_list, " ");
		file_list = ft_strjoin(file_list, file->d_name);
		printf("%s\n", file->d_name);
	}
	closedir(fd);
	return (ft_strsplit(file_list, ' '));
}
