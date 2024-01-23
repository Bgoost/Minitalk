/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:32:36 by crmanzan          #+#    #+#             */
/*   Updated: 2023/09/26 16:35:35 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	if (i != n)
		return (a[i] - b[i]);
	return (0);
}
/*
int main(int argc, char **argv)
{
	printf("ft_memcmp:%d \n", ft_memcmp("a", NULL, 3));
	printf("memcmp:%d", memcmp("a", NULL, 3));
//	printf("memcmp:%d", memcmp(NULL, NULL, 0));
	return(0);
}*/
