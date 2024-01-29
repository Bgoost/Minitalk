/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:51:19 by crmanzan          #+#    #+#             */
/*   Updated: 2024/01/25 16:10:45 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	recieve(int signum, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	c = 0;

	(void)context;
	(void)info;
//	SIGUSR1 is bit 1 and SIGUSR2 is bit 0 bc i want
//	If the signal sent by the client is equal as sigusr1
	if (signum == SIGUSR1)
		//We always add a one and then move the bit to the left
		c |= (1 << bit);
	// We decrease the bit counter
	bit++;
	if (bit == 8)
	{
		//We write the char
		write(1, &c, 1);
		//We reset the counter
		bit = 0;
		//We set all the bit as 0
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = recieve;
	s_sigaction.sa_flags = SA_SIGINFO;
	//sigusr1 equals 0, 2 equals 1
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
	return (0);
}
