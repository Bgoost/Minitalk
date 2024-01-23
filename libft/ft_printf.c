/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:58:03 by crmanzan          #+#    #+#             */
/*   Updated: 2024/01/23 12:59:49 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_type(const char *c, va_list ap)
{
	int	i;

	i = 0;
	if (*c == 'c')
		i = printchar(va_arg(ap, int));
	else if (*c == '%')
		i = printchar((char) '%');
	else if (*c == 's')
		i = printstr(va_arg(ap, char *));
	else if (*c == 'p')
		i = printhexptr(va_arg(ap, unsigned long), 2, 0);
	else if (*c == 'd')
		i = printnbr(va_arg(ap, int));
	else if (*c == 'i')
		i = printnbr(va_arg(ap, int));
	else if (*c == 'u')
		i = printunnbr(va_arg(ap, unsigned int));
	else if (*c == 'x')
		i = printhexptr(va_arg(ap, unsigned int), 0, 0);
	else if (*c == 'X')
		i = printhexptr(va_arg(ap, unsigned int), 1, -32);
	if (i == -1)
		return (-1);
	else
		return (i);
}

int	process_specifiers(const char *str, va_list ap)
{
	int	tmp;
	int	final;

	final = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_strchr("cspdiuxX%", *str))
			{
				tmp = ft_type(str, ap);
				final += tmp;
			}
		}
		else
		{
			tmp = printchar(*str);
			final += tmp;
		}
		if (tmp == -1)
			return (-1);
		str++;
	}
	return (final);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, str);
	result = process_specifiers(str, ap);
	if (result == -1)
		return (-1);
	va_end(ap);
	return (result);
}
/*
int main(void)
{
	int x = 50;
	int *ptr = &x;

	ft_printf("\n%c", '0');
	ft_printf("\n%s", "jaja");
	ft_printf("\n%p", ptr);
	ft_printf("\n%d", *ptr);
	ft_printf("\n%i", 123);
	ft_printf("\n%u", -123);
	ft_printf("\n%x", 11);
	ft_printf("\n%X", 11);
	ft_printf("\n%c, %%, %c0, %a", '0', 'i', 2);
	return 0;
}*/
