/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:19:26 by crmanzan          #+#    #+#             */
/*   Updated: 2023/10/20 13:19:26 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_write_char(char c)
{
	int	result;

	result = printchar(c);
	if (result == -1)
		return (-1);
	return (result);
}

static int	write_digit(int n)
{
	int	result;

	result = check_write_char(n + '0');
	if (result == -1)
		return (-1);
	return (result);
}

int	max(void)
{
	if (write(1, "-2147483648", 11) == -1)
		return (-1);
	return (11);
}

int	printnbr(int n)
{
	int	len;
	int	result;

	len = 0;
	result = 0;
	if (n == -2147483648)
		return (max());
	if (n < 0)
	{
		if (printchar('-') == -1)
			return (-1);
		n = -n;
		len++;
	}
	if (n >= 10)
	{
		result = printnbr(n / 10);
		if (result == -1)
			return (-1);
		len += result;
	}
	if (write_digit(n % 10) == -1)
		return (-1);
	return (++len);
}
/*
int	main()
{
	printf("\n%i, %i, %i", printnbr(0), printnbr(123), printnbr(-2));
	printf("\n%i, %i, %i", 0, 123, -2);
	return (0);
}*/
