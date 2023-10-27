/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:33:05 by mvachera          #+#    #+#             */
/*   Updated: 2023/05/08 16:34:00 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	my_func(unsigned int i, char *str)
{
	printf("My inner function: index = %d and %c\n", i, *str);
	*str = *str - 32;
}

int     main(void)
{
	char      str[] = "salutmatheo";

	ft_striteri(str, my_func);
	printf("%s\n", str);
	return (0);
}*/
