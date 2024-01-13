/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:48:10 by jroulet           #+#    #+#             */
/*   Updated: 2024/01/13 19:01:03 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int arc, char **arv)
{

	if (arc != 2)
		printf("Enter PID to kill");
	else 
	{
		pid_t	pid;

		pid = ft_atoi(arv[1]);
		printf("%d", pid);
		kill(pid, SIGKILL);
	}
	return (0);
}
