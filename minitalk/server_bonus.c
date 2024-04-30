/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:40:46 by crebelo-          #+#    #+#             */
/*   Updated: 2023/12/11 10:40:46 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	siginfo_handler(int num, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	i = 0;

	(void)context;
	if (num == SIGUSR1)
		c = (c << 1) | 1;
	else if (num == SIGUSR2)
		c = (c << 1);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = siginfo_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		return (ft_error_exit("Error\nIssue with sigaction.\n"));
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
