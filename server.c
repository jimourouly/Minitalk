/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:48:26 by jroulet           #+#    #+#             */
/*   Updated: 2024/01/17 16:40:22 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	1. The server print his PID
 *	2. The server wait for the reception of the full message
 *	3. Print the full message
 *	4. The server can get multiple source's messages
 *
 *	BONUS
 *	1. The server confirm the good reception of the message
 *	2. Can support UNIX characers
 *
 *
 * */


#include "minitalk.h"

void bit_to_text(int bit, int ending)
{
	if (ending == 8)
	{
		printf("end of letter\n");
	}
	else
	{
		printf("bit {%d} %d\n", bit, ending);
	}
}

//will choose what to do when SIGUSR1 or SIGUSR2 is receive
void signal_handler(int signum)
{
	static int i;
	if (i == 8)
	{
		bit_to_text(signum, i);
		i = 0;
	}
	else
	{
		bit_to_text(signum, i);
		i++;
	}
}

int main(void)
{
	struct sigaction	signal_received;

	printf("PID = %d\n", getpid());
	signal_received.sa_handler = signal_handler;
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	
	while(1)
	{
		usleep(100);
	}
	//pause();
	return (0);
}
