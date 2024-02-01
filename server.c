/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:48:26 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/01 17:51:55 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static int	j;
	int			nb;

	(void)context;
	if (signum == SIGUSR1)
		nb = 0;
	else
		nb = 1;
	j = (j << 1) + nb;
	i++;
	if (i == 8)
	{
		if (j == 0)
		{
			kill(info->si_pid, SIGUSR1);
		}
		else
			write (1, &j, 1);
		i = 0;
		j = 0;
	}
}

int	main(void)
{
	struct sigaction	signal_received;
	int	pid;

	pid = getpid();
	ft_printf("PID = %d\n", getpid());
	signal_received.sa_sigaction = signal_handler;
	signal_received.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
	{
		usleep(42);
	}
	return (0);
}
