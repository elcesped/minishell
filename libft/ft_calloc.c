/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:07:52 by mvachera          #+#    #+#             */
/*   Updated: 2023/05/11 14:53:26 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			nmemb_size;

	i = 0;
	nmemb_size = nmemb * size;
	if (nmemb_size == 0)
		return (malloc(1));
	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = (unsigned char *)malloc(nmemb_size);
	if (!ptr)
		return (NULL);
	while (i < nmemb_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*int	main()
{
	unsigned char	*ptr;
	size_t	i;
	
	i = 0;
	ptr = ft_calloc(7, 1);
	while (i < 7)
	{
		printf("%c ", ptr[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/

/*int main(void) 
{
    int n = 5;
    int *arr = ft_calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Erreur: la mémoire n'a pas pu être allouée\n");
        return 1;
    }

    // Initialisation de l'array

    // Affichage de l'array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Libération de la mémoire
    free(arr);

    return 0;
}*/
