/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:48:10 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/02 14:58:14 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	eof(int pid)
{
	int	i;

	i = 1;
	while(i <= 8)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(42);
	}

}

void	str_to_binary(char *str, int pid)
{
	int	i;
	int	j;
	int	k;

	if (str == NULL)
		return ;
	j = 0;
	while (str[j])
	{
		i = 0;
		while (i < 8)
		{
			if (((char)(str[j] >> (7 - i)) & 1) == 0)
				k = kill(pid, SIGUSR1);
			else if (((char)(str[j] >> (7 - i)) & 1) == 1)
				k = kill(pid, SIGUSR2);
			i++;
			usleep (100);
		}
		j++;
	}
	if (k < 0)
		write(1, "message can't be send", 21);

}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR2 || signum == SIGUSR1)
		write(1, "message transmitted", 19);
}

int	main(int arc, char **arv)
{
	pid_t				pid;
	int					send;
	struct sigaction	signal_received;


	send = 0;
	pid = 0 ;
	if (arc != 3)
		ft_printf("USE : ./client -server's PID- and ''message''");
	else
	{
		pid = ft_atoi(arv[1]);
		str_to_binary(arv[2], pid);
		send = 1;
	}
	signal_received.sa_sigaction = signal_handler;
	signal_received.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	if (send == 1)
		eof(pid);
	return (0);
}
