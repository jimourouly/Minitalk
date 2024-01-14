/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:48:10 by jroulet           #+#    #+#             */
/*   Updated: 2024/01/14 14:05:50 by jroulet          ###   ########.fr       */
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


int str_to_binary(char *str, int pid)
{
	size_t len;
	char *binary;
	int i;
	int j;

	if (str == NULL)
		return (0);
	len = ft_strlen(str);
	binary = malloc((len * 8) + 1);
	binary[0] = '\0';
	j = 0;
	while(str[j])
	{
		i = 0;
		while (i < 8)
		{
			if (((char)(str[j] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((char)(str[j] >> (7 - i)) & 1) == 1)
				kill(pid, SIGUSR2);
			i++;
		}
		j ++;
	}
	return (1);
}

int main(int arc, char **arv)
{

	if (arc != 2)
		printf("pls enter a pid");
	else 
	{
		pid_t	pid;

		pid = ft_atoi(arv[1]);	
		str_to_binary(arv[1], pid);

	}
	return (0);
}
