/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:47:40 by mvachera          #+#    #+#             */
/*   Updated: 2023/05/11 14:59:57 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*char_dst;
	const unsigned char	*char_src;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (0);
	char_dst = (unsigned char *) dst;
	char_src = (const unsigned char *) src;
	i = 0;
	if (char_src < char_dst)
	{
		while (n--)
			char_dst[n] = char_src[n];
	}
	else
	{
		while (i < n)
		{
			char_dst[i] = char_src[i];
			i++;
		}
	}
	return (char_dst);
}

/*int	main()
  {
  int	source[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int	destination[10];
  int	i;

  i = 0;
  ft_memmove(source + 2, source, sizeof(int) * 10);
  while (i < 10)
  {
  printf("destination[%d]=%d\n", i, destination[i]);
  i++;
  }
  return (0);
  }*/

/*int main() {
  char str1[] = "Hello World";
  char str2[] = "Goodbye";
  printf("Before memmove:\nstr1 = %s\nstr2 = %s\n", str1, str2);
  memmove(str1, str2, 4);
  printf("After memmove:\nstr1 = %s\nstr2 = %s\n", str1, str2);
  return 0;
  }*/
