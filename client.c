/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:00:11 by crmanzan          #+#    #+#             */
/*   Updated: 2024/01/25 14:10:53 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send(int pid, char *string)
{
    int i = 0;
    int bit = 0;

    while(string[i]){
        bit = 0;
        while(bit < 8)
        {
            //mascara de bits lo que hace es que pone todo lo que nosta en la posicion "bit" en 0
            if (string[i] & (1 << bit))
                kill(pid, SIGUSR1); // 1
            else
                kill(pid, SIGUSR2); // 0
            usleep(250);
            bit++;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    if(argc != 3)
        return (write(2, "Usage: ./client <PID> <message>\n", 33), 1);
    send(ft_atoi(argv[1]), argv[2]);
    return (0);
}