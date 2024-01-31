/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:48:10 by jroulet           #+#    #+#             */
/*   Updated: 2024/01/17 16:52:18 by jroulet          ###   ########.fr       */
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
//	size_t len;
	int i;
	int j;
	int k;

	if (str == NULL)
		return ;
//	len = ft_strlen(str);
	j = 0;
	while(str[j])
	{
		i = 0;
		while (i < 8)
		{
			if (((char)(str[j] >> (7 - i)) & 1) == 0)
			{
				ft_printf("0");
				k = kill(pid, SIGUSR1);
				if (k < 0)
				{
					ft_printf("Error while sending message");
					return ;
				}

			}
			else if (((char)(str[j] >> (7 - i)) & 1) == 1)
			{
				ft_printf("1");
				k = kill(pid, SIGUSR2);
				if (k < 0)
				{
					ft_printf("error while sending message");
					return ;
				}
			}
			i++;
			usleep (100);
		}
		j ++;
		ft_printf(" ");
	}
}

int main(int arc, char **arv)
{

	if (arc != 3)
	{
		ft_printf("pls enter a PID" );
	}
	else 
	{
		pid_t	pid;

		pid = ft_atoi(arv[1]);	
		str_to_binary(arv[2], pid);

	}
	return (0);
}
