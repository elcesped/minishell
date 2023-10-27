/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:47:22 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/13 21:43:55 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static int	is_charset(char const s, char c)
  {
  if (s == c)
  return (1);
  return (0);
  }*/

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		m;

	i = 0;
	count = 0;
	m = 0;
	while (s[i])
	{
		if (s[i] != c && m == 0)
		{
			count++;
			m = 1;
		}
		if (s[i] == c)
			m = 0;
		i++;
	}
	return (count);
}

static size_t	lword(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_cpy(char const *s, char c)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(char) * (lword(s, c) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < lword(s, c))
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	**liberer_les_reufs(char const *s, char c, char **result)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			result[i] = ft_cpy(s, c);
			if (!result[i])
			{
				while (i >= 0)
					free(result[i--]);
				free(result);
				return (NULL);
			}
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!result || !s)
		return (NULL);
	return (liberer_les_reufs(s, c, result));
}

/*int	main()
  {
  char	**result;
  char	*str = "Salut tout le monde !";
  char	charset = ' ';
  size_t	i;

  result = ft_split(str, charset);
  i = 0;
  while (i < ft_count(str, charset))
  {
  printf("%s\n", result[i]);
  i++;
  }
  printf("\n");
  return (0);
  }*/
