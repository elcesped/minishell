/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:19:55 by mvachera          #+#    #+#             */
/*   Updated: 2023/05/09 19:09:37 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	i;
	long	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	if (n == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	size_t	len;

	nb = n;
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (nb == 0)
		str[0] = '0';
	else if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		str[len--] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (str);
}

/*int	main()
{
	char	*str;
	int	nb = -78895;

	str = ft_itoa(nb);
	printf("%s\n", str);
	return (0);
}*/
