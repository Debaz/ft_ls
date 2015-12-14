/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:19:54 by klescaud          #+#    #+#             */
/*   Updated: 2015/12/09 20:59:23 by Debaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** alsort_tab => Sort a char** by alphanumerical sorting
*/

char	**alsort_tab(char **tab)
{
	int		i;
	int		sorted;
	char	*temp;

	i = 0;
	while (tab[i])
	{
		sorted = 1;
		if ((tab[i + 1]) && (ft_strcmp(tab[i], tab[i + 1])) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			sorted = 0;
		}
		i++;
		if (!sorted)
			i = 0;
	}
	return (tab);
}

/*
** rev_alsort_tab => Sort a char** by reverse alphanumerical sorting
*/

char	**rev_alsort_tab(char **tab)
{
	int		i;
	int		sorted;
	char	*temp;

	i = 0;
	while (tab[i])
	{
		sorted = 1;
		if ((tab[i + 1]) && (ft_strcmp(tab[i], tab[i + 1])) < 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			sorted = 0;
		}
		i++;
		if (!sorted)
			i = 0;
	}
	return (tab);
}

/*
** timesort_tab => Sort a file array by their last modification date
*/

char	**timesort_tab(char **tab, char *path)
{
	int		i;
	int		sorted;
	char	*temp;

	i = 0;
	while (tab[i])
	{
		sorted = 1;
		if ((tab[i + 1]) && (file_datecmp(tab[i], tab[i + 1], path)) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			sorted = 0;
		}
		i++;
		if (!sorted)
			i = 0;
	}
	return (tab);
}

/*
** rev_timesort_tab => Sort a file array by reversly their last modification date
*/

char	**rev_timesort_tab(char **tab, char *path)
{
	int		i;
	int		sorted;
	char	*temp;

	i = 0;
	while (tab[i])
	{
		sorted = 1;
		if ((tab[i + 1]) && (file_datecmp(tab[i], tab[i + 1], path)) < 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			sorted = 0;
		}
		i++;
		if (!sorted)
			i = 0;
	}
	return (tab);
}

/*
** file_datecmp => Compares two files by their date of last modification.
*/

int		file_datecmp(char *file1, char *file2, char *path)
{
	struct stat		*stat1;
	struct stat		*stat2;

	stat1 = malloc(sizeof(struct stat));
	stat2 = malloc(sizeof(struct stat));
	stat(ft_strjoin(path, file1), stat1);
	stat(ft_strjoin(path, file2), stat2);
	if (stat1->st_mtime < stat2->st_mtime)
// FREE ?
		return (1);
	else if (stat1->st_mtime > stat2->st_mtime)
// FREE ?
		return (-1);
// FREE ?
	return (0);
}
