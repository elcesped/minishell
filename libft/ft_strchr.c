/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:35:25 by mvachera          #+#    #+#             */
/*   Updated: 2023/05/10 19:00:16 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/*int main()
{
	char str[] = "tripouille";

	printf("%p\n", ft_strchr(str, 't' + 256));
	printf("%p\n", strchr(str, 't' + 256));

	printf("%p\n", ft_strchr(str, 't'));
	printf("%p\n", strchr(str, '\0'));
}*/
