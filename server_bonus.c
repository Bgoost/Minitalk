/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:22:20 by crmanzan          #+#    #+#             */
/*   Updated: 2024/02/19 10:48:13 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

//	SIGUSR1 is bit 1 and SIGUSR2 is bit 0 bc i want
//	LINE 29: If the signal sent by the client is equal as sigusr1
//	LINE 30: We always add a one and then move the bit to the left
//	LINE 31: We decrease the bit counter
//	LINE 34: We write the char
//	LINE 35: We reset the counter
//	LINE 36: We set all the bit as 0
static void	recieve(int signum, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	c = 0;
	int			signal;

	(void)context;
	signal = SIGUSR1;
	if (signum == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (!c)
			signal = SIGUSR2;
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, signal);
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = recieve;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
	return (0);
}
