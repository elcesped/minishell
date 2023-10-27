/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:41:45 by mvachera          #+#    #+#             */
/*   Updated: 2023/09/10 16:46:14 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_unsigned_nbr(unsigned int nb);
int		ft_charactere(va_list arg);
int		ft_string(va_list arg);
int		ft_pointeur(va_list arg);
int		ft_int(va_list arg);
int		ft_unsigned(va_list arg);
size_t	ft_slen(char *str);
size_t	ft_count_sign(int n);
size_t	ft_count_unsigned(unsigned int n);
void	ft_putnbr_base(unsigned long long int nbr, char *base);
int		ft_count_putnbr_base(unsigned long long int nbr);
int		ft_hexa_min(va_list arg);
int		ft_hexa_maj(va_list arg);
int		ft_len(const char *format);
int		ft_search_arg(va_list arg, char const c);
int		ft_printf(const char *format, ...);

#endif
