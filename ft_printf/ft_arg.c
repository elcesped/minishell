/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:18:12 by mvachera          #+#    #+#             */
/*   Updated: 2023/09/10 16:46:22 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_charactere(va_list arg)
{
	char	c;

	c = (char)va_arg(arg, int);
	ft_putchar(c);
	return (1);
}

int	ft_string(va_list arg)
{
	char	*s;

	s = va_arg(arg, char *);
	if (s == NULL)
		return (ft_putstr("(null)"));
	else
		ft_putstr(s);
	return (ft_slen(s));
}

int	ft_pointeur(va_list arg)
{
	unsigned long	n;

	n = (unsigned long)va_arg(arg, void *);
	if (n == 0)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	ft_putnbr_base(n, "0123456789abcdef");
	return (ft_count_putnbr_base(n) + 2);
}

int	ft_int(va_list arg)
{
	long	d;

	d = (long)va_arg(arg, int);
	ft_putnbr(d);
	return (ft_count_sign(d));
}

int	ft_unsigned(va_list arg)
{
	unsigned long	u;

	u = (unsigned long)va_arg(arg, unsigned int);
	ft_unsigned_nbr(u);
	return (ft_count_unsigned(u));
}
