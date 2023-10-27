/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:26:16 by mvachera          #+#    #+#             */
/*   Updated: 2023/05/03 19:48:32 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*sc;
	size_t			i;

	sc = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		sc[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/*int	main()
{
	unsigned char	*sc[20];
	size_t	i;

	i = 0;
	ft_memset(sc, 'a', sizeof(char) * 10);
	while (i < 10)
	{
		printf("%c", sc[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
