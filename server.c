/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:48:26 by jroulet           #+#    #+#             */
/*   Updated: 2024/01/17 18:17:56 by jroulet          ###   ########.fr       */
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

void bin_to_txt(int bit, int end)
{
	char word[8];

	if(end == 8)
	{
		ft_printf("%s", word);
		//TODO 
		return ;
	}
	else if (end != 8 )
	{
		word[end] = bit;
		//TODO
		return ;
	}
	
}

//will choose what to do when SIGUSR1 or SIGUSR2 is receive
void signal_handler(int signum)
{
	char digit;
	static int i;

	digit =  signum + 18;

	//if i = 8, end of the word
	if (i == 8)
	{
		bin_to_txt((digit), i);
//		write(1, " ", 1);
		i = 0;
	}
	else 
	{
		bin_to_txt((digit), i);
//		write(1, &digit, 1);
	}
	i++;
}

int main(void)
{
	struct sigaction	signal_received;

	ft_printf("PID = %d\n", getpid());
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
