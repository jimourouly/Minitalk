/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:48:10 by jroulet           #+#    #+#             */
/*   Updated: 2024/01/14 16:30:06 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	1. client takes 2 arguments. The Messages and the PID of the server
 *	2. transform str to bit 
 *	3. Send the message to the server
 *
 * BONUS :
 * 	1. The Server confirm the good reception of the message
 * 	2. Support UNIX characters
 *
 *
 * */

#include "minitalk.h"
/*
void send_to_server(int pid, int signum)
{
	printf("sendind %d %d \n", signum, (signum % 2));
	kill(pid, signum);
}
*/
void str_to_binary(char *str, int pid)
{
	size_t len;
	int i;
	int j;

	if (str == NULL)
		return ;
	len = ft_strlen(str);
	j = 0;
	while(str[j])
	{
		i = 0;
		while (i < 8)
		{
			if (((char)(str[j] >> (7 - i)) & 1) == 0)
			{
				printf("0");
				kill(pid, SIGUSR1);
			}
			else if (((char)(str[j] >> (7 - i)) & 1) == 1)
			{
				printf("1");
				kill(pid, SIGUSR2);
			}
				i++;
		}
		j ++;
		printf(" ");
	}
}

int main(int arc, char **arv)
{

	if (arc != 3)
	{
		printf("pls enter a PID" );
	}
	else 
	{
		pid_t	pid;

		pid = ft_atoi(arv[1]);	
		str_to_binary(arv[2], pid);

	}
	return (0);
}
