/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:20:32 by mvachera          #+#    #+#             */
/*   Updated: 2023/05/08 20:57:08 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/*int	main()
{
	char	*sc = "12345678910";
	size_t	i = 0;
	bzero(sc, sizeof(int) * 10);
	while (i < 10)
	{
		printf("%c\n", sc);
		i++;
	}
	printf("\n");
	return (0);
}*/
