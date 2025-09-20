/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chevfy <chevfy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:36:29 by chevfy            #+#    #+#             */
/*   Updated: 2025/09/19 19:30:46 by chevfy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_hexlen(unsigned int n);
int		ft_formats(va_list args, const char format);
int		ft_printf(const char *str, ...);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printpercent(void);
void	ft_putstr(char *str);
int		ft_printnbr(int n);
int		ft_len_num(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, const char format);
char	*ft_puthex(unsigned int n, const char format);
int		ft_hexlen(unsigned int n);
int		ft_printptr(unsigned long long n);
int		ft_printptr(unsigned long long ptr);
char	*ft_putptr(uintptr_t n);
int		ft_ptrlen(uintptr_t n);

#endif