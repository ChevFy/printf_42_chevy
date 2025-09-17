
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printpercent(void);
void	ft_putstr(char *str);
int		ft_printnbr(int n);

#endif