/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:53:10 by mvachera          #+#    #+#             */
/*   Updated: 2023/05/22 16:54:31 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long int nbr, char *base)
{
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, base);
		ft_putnbr_base(nbr % 16, base);
	}
	else
		ft_putchar(base[nbr]);
}

int	ft_count_putnbr_base(unsigned long long int nbr)
{
	int		count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		count++;
	}
	return (count);
}

int	ft_hexa_min(va_list arg)
{
	unsigned long long int	x;

	x = (unsigned long long int)va_arg(arg, unsigned int);
	ft_putnbr_base(x, "0123456789abcdef");
	return (ft_count_putnbr_base(x));
}

int	ft_hexa_maj(va_list arg)
{
	unsigned long long int	xx;

	xx = (unsigned long long int)va_arg(arg, unsigned int);
	ft_putnbr_base(xx, "0123456789ABCDEF");
	return (ft_count_putnbr_base(xx));
}
