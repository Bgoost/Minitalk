/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:54:37 by crmanzan          #+#    #+#             */
/*   Updated: 2023/10/20 13:56:40 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

int				ft_printf(char const *str, ...);
int				printchar(char c);
int				printstr(char *str);
int				printhexptr(unsigned long hex, int shift, int mayus);
int				printnbr(int n);
unsigned int	printunnbr(unsigned int n);
char			*ft_strchr(const char *s, int c);
#endif
