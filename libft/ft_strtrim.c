/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:31:40 by mvachera          #+#    #+#             */
/*   Updated: 2023/05/11 15:12:58 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	len(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = my_strlen(s1);
	while (s1[i] && is_set(s1[i], set))
		i++;
	j--;
	while (is_set(s1[j], set))
		j--;
	j++;
	k = j - i;
	return (k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	m;

	i = 0;
	m = 0;
	j = my_strlen(s1);
	if (!s1 || !set)
                return (NULL);
	result = (char *)malloc(sizeof(char) * (len(s1, set) + 1));
	if (!result)
		return (NULL);
	while (s1[i] && is_set(s1[i], set))
		i++;
	j--;
	while (j > i && is_set(s1[j], set))
		j--;
	j++;
	while (i < j)
	{
		result[m] = s1[i];
		m++;
		i++;
	}
	result[m] = '\0';
	return (result);
}*/

char	*ft_strtrim(char const *s1, char const *set)

{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	j = len - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	len = j - i + 1;
	str = ft_substr(s1, i, len);
	return (str);
}

/*int	main()
{
	char	*src = "------salut-matheo-----";
	char	*set = "-";
	char	*dst;

	dst = ft_strtrim(src, set);
	printf("%s\n", dst);
	free(dst);
	return (0);
}*/
