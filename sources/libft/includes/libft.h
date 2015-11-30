/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 02:37:43 by klescaud          #+#    #+#             */
/*   Updated: 2015/10/28 16:29:04 by Debaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 32

size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl(const char *s);
void	ft_putendl_fd(const char *s, int fd);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strrev(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_last_int(int *x);
char	*ft_stradd(char *s1, char s2);
char	*ft_itoa(int n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
int		ft_ten_pow(int nb, int pow);
int		ft_atoi(char const *str);
char	ft_mini_itoa(int x);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_strsplit(const char *s, char c);
char	*ft_strnew(size_t size);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	ft_strdel(char **as);
char	*ft_strchr(const char *str, char c);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(const char *s, char (*f)(char));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int		ft_strequ(const char *s1, const char *s2);
int		ft_strnequ(const char *s1, const char *s2, size_t n);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
char	*ft_strtrim(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
char	*ft_strstr(const char *str, const char *to_find);
char	*ft_strnstr(const char *str, const char *to_find, size_t n);
char	*ft_strrchr(const char *str, int c);
void	ft_strclr(char *s);
int		get_next_line(int fd, char **line);

#endif
