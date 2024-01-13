/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:48:26 by jroulet           #+#    #+#             */
/*   Updated: 2024/01/13 20:19:58 by jroulet          ###   ########.fr       */
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
 * 	SIGUSR1 = client
 * 	SIGUSR2 = server
 * */


#include "minitalk.h"

int main(void)
{
	pid_t pid;

	pid = getpid();

	while(1)
	{
		sleep(5);
		printf("PID = :%d:\n", pid);
	}



}
