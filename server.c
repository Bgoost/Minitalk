/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:51:19 by crmanzan          #+#    #+#             */
/*   Updated: 2024/01/25 14:28:45 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
//#include "../libft/libft.h"
#include <unistd.h>

void NOSECOMOSELLAMA(int signal, siginfo_t *info, void *context){

}






int main (int argc, char *argv[]) {
	
	pid_t pid;
	pid = getpid();
	struct sigaction s_sigaction;
	if( argc != 2 ){
		return (0);
		//tuputamadrteasdzdslfkjemklnef
	}
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);

	s_sigaction.sa_sigaction = NOSECOMOSELLAMA;
	//s_sigaction.isa_sighandler = nosecomosellama;





	printf("PID: %i\n", pid);
	while(1){
		pause();
	}



	return 0;
}


