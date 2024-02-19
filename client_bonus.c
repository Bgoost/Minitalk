/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:20:23 by crmanzan          #+#    #+#             */
/*   Updated: 2024/02/19 10:34:08 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

//  LINE 27: mascara de bits lo que hace es que pone todo lo que nosta en la 
//  posicion "bit" en 0. RECUERDA: sigusr1 es bit 1y el usr2 es el 0
int g_wait;

static void send_char(int pid, char c)
{
    int	bit;

	bit = 0;
    while (bit < 8)
    {
        g_wait = 1;
        if (c & (1 << bit))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        while (g_wait)
            usleep(10);
        bit++;
    }
}

static void	send(int pid, char *string)
{
	int	i;

    i = 0;
	while (string[i])
    {
        send_char(pid, string[i]);
        i++;
    }
    send_char(pid, 0);
}

static void	recieve(int signum, siginfo_t *info, void *context)
{
	(void)context;
    if (signum == SIGUSR2)
        ft_printf("Messaged received by server %d\n", info->si_pid);
    g_wait = 0;
}

int	main(int argc, char *argv[])
{
    struct sigaction	s_sigaction;
    
	if (argc != 3)
		return (write(2, "Usage: ./client <PID> <message>\n", 32), 1);
    s_sigaction.sa_sigaction = recieve;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
    sigaction(SIGUSR2, &s_sigaction, NULL);
	//send(ft_atoi(argv[1]), argv[2]);
	return (0);
}
