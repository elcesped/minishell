/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:02:37 by mvachera          #+#    #+#             */
/*   Updated: 2023/05/11 17:12:22 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_strnstr(const char *big, const char *little, size_t len)
  {
  size_t	i;
  size_t	j;

  i = 0;
  j = 0;
  if (little[j] == '\0')
  return ((char *) big);
  while (big[i] != '\0')
  {
  while (little[j] && big[i + j] == little[j] && i + j < len)
  j++;
  if (little[j] == '\0')
  return ((char *) big + i);
  j = 0;
  i++;
  }
  return (0);
  }*/

static unsigned int	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	to_find_len;

	if (to_find == NULL || str == NULL)
		if (n == 0)
			return ((char *)str);
	if (*to_find == '\0')
		return ((char *)str);
	if (*str == '\0')
		return (NULL);
	to_find_len = ft_len(to_find);
	while (*str && to_find_len <= n--)
	{
		if (!ft_memcmp(str, to_find, to_find_len))
			return ((char *)str);
		str++;
	}
	return (NULL);
}

/*int	main()
  {
  char	*big = "Streamer";
  char	*little = "ea";
  printf("%s\n", ft_strnstr(big, little, 6));
  return (0);
  }*/
