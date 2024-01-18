/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:16:22 by crmanzan          #+#    #+#             */
/*   Updated: 2023/10/20 14:00:55 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

static int	ft_hexptrlen(unsigned long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static int	ft_puthexptr(unsigned long n, int shift, int mayus)
{
	if (n >= 16)
	{
		if (ft_puthexptr(n / 16, shift, mayus) == -1
			|| ft_puthexptr(n % 16, shift, mayus) == -1)
			return (-1);
	}
	else
	{
		if (n < 10)
		{
			if (printchar(n + '0') == -1)
				return (-1);
		}
		else
		{
			if (printchar(n - 10 + 'a' + mayus) == -1)
				return (-1);
		}
	}
	return (1);
}

// len [0] == len og, len[1] == tmp
int	printhexptr(unsigned long hex, int shift, int mayus)
{
	int	len[2];

	len[0] = 0;
	len[1] = 0;
	if (shift == 2)
	{
		len[1] = write(1, "0x", 2);
		if (len[1] == -1)
			return (-1);
		len[0] += len[1];
	}
	if (!hex)
	{
		len[1] = write(1, "0", 1);
		if (len[1] == -1)
			return (-1);
		len[0] += len[1];
	}
	else
	{
		if (ft_puthexptr(hex, shift, mayus) == -1)
			return (-1);
		len[0] += ft_hexptrlen(hex);
	}
	return (len[0]);
}
// 1 linea
/*
int main()
{
	printf("\n%x, %x", INT_MAX, printhexptr(INT_MAX, 0));
	//printhexptr((unsigned long)11, 0);
	//printhexptr((unsigned long)11, 1);
	//printhexptr((unsigned long)(void *)11, 2);
}*/
