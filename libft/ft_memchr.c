/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:07:41 by mvachera          #+#    #+#             */
/*   Updated: 2023/05/10 18:24:42 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sc;
	size_t				i;

	i = 0;
	sc = (const unsigned char *) s;
	while (i < n)
	{
		if (sc[i] == (unsigned char)c)
			return ((void *) &sc[i]);
		i++;
	}
	return (NULL);
}

/*int	main()
{
	char	data[] = {'q', 'r', 's', 't', 'p', 'a', 'x'};
	char	*pos = memchr(data, 't', 7);
	size_t	i = 0;

	while (i < 7)
	{
		printf("%c ", pos[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
