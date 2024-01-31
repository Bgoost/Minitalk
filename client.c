/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:00:11 by crmanzan          #+#    #+#             */
/*   Updated: 2024/01/31 19:33:50 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//  LINE 24: mascara de bits lo que hace es que pone todo lo que nosta en la 
//  posicion "bit" en 0. RECUERDA: sigusr1 es bit 1y el usr2 es el 0

void	send(int pid, char *string)
{
	int	i;
	int	bit;

	i = 0;
	bit = 0;
	while (string[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if (string[i] & (1 << bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(250);
			bit++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (write(2, "Usage: ./client <PID> <message>\n", 32), 1);
	send(ft_atoi(argv[1]), argv[2]);
	return (0);
}
