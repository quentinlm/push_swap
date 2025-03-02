/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:19:58 by qclaqueb          #+#    #+#             */
/*   Updated: 2025/01/25 12:30:46 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_liste
{
	void			*content;
	struct s_list	*next;
}	t_liste;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int value, size_t c);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int srchchar);
char	*ft_strrchr(const char *str, int srchchar);
int		ft_strncmp(const char *first, const char *second, size_t len);
void	*ft_memchr(const void *memblock, int srchchar, size_t size);
int		ft_memcmp(const void *p1, const void *p2, size_t size);
char	*ft_strnstr(const char *fullstr, const char *substr, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t elemc, size_t elems);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *format, ...);
int		ft_print_char(va_list args);
int		ft_format_s(va_list args);
int		ft_format_p(va_list args);
int		ft_format_int(va_list args);
int		ft_format_u(va_list args);
int		ft_format_x(va_list args, int flag);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
void	ft_format_flag(va_list args, const char *format, int i);

#endif
