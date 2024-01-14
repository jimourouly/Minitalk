/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:48:10 by jroulet           #+#    #+#             */
/*   Updated: 2024/01/14 13:52:59 by jroulet          ###   ########.fr       */
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


int str_to_binary(char *str)
{
	size_t len;
	char *binary;
	int i;
	int j;

	str = "Salut";
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
				printf ("0");
			else if (((char)(str[j] >> (7 - i)) & 1) == 1)
				printf("1");
			i++;
		}
		printf("\t %c", str[j]);
		j ++;
		printf("\n");
	}
	return (1);
}

int main(int arc, char **arv)
{

	if (arc != 2)
		printf("Enter PID to kill");
	else 
	{
		pid_t	pid;

		pid = ft_atoi(arv[1]);
		//printf("%d", pid);
		str_to_binary(arv[1]);

	}
	return (0);
}
