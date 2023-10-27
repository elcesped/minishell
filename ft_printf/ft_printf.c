/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:11:43 by mvachera          #+#    #+#             */
/*   Updated: 2023/09/10 16:50:43 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_arg(va_list arg, char c)
{
	if (c == 'c')
		return (ft_charactere(arg));
	if (c == 's')
		return (ft_string(arg));
	if (c == 'p')
		return (ft_pointeur(arg));
	if (c == 'd' || c == 'i')
		return (ft_int(arg));
	if (c == 'u')
		return (ft_unsigned(arg));
	if (c == 'x')
		return (ft_hexa_min(arg));
	if (c == 'X')
		return (ft_hexa_maj(arg));
	if (c == '%')
	{
		write(2, "%%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_search_arg(arg, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
