/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aamegamind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:16:23 by crmanzan          #+#    #+#             */
/*   Updated: 2024/01/25 10:36:20 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main (void){
	// LIBFT NORMAL
	//
	// PRINTF NORMAL
	
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
	
}
