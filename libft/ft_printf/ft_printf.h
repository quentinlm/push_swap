#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(va_list args);
int		ft_format_s(va_list args);
int		ft_format_p(va_list args);
int		ft_format_int(va_list args);
int		ft_format_u(va_list args);
int		ft_format_x(va_list args, int flag);
char	*ft_strchr(const char *s, int c);
int		ft_isdigite(int c);
size_t	ft_strlene(const char *str);
char	*ft_itoa(int n);
void	ft_format_flag(va_list args, const char *format, int i);

#endif