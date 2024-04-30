/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 09:21:57 by crebelo-          #+#    #+#             */
/*   Updated: 2023/12/03 09:21:57 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message successfully received\n");
	else
		ft_printf("Error: Message was not received properly.\n");
}

int	send_message(int PID, char *msg)
{
	int				bits;
	unsigned char	c;

	while (*msg)
	{
		bits = 8;
		c = *msg;
		while (bits--)
		{
			if (c >> bits & 1)
			{
				if (kill(PID, SIGUSR1) == -1)
					return (ft_error_exit("Error\nUnable to send signal."));
			}
			else
			{
				if (kill(PID, SIGUSR2) == -1)
					return (ft_error_exit("Error\nUnable to send signal."));
			}
			usleep(1000);
		}
		msg++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					i;

	sa.sa_flags = 0;
	sa.sa_handler = handle_signal;
	i = 0;
	sigemptyset(&sa.sa_mask);
	if (argc != 3)
		return (ft_error_exit("Error\nInvalid number of arguments.\n"));
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) == 0)
			return (ft_error_exit("Error\nInvalid PID number."));
		i++;
	}
	if (!argv[2][0])
		return (ft_error_exit("Error\nEmpty message."));
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		(ft_error_exit("Error\nIssue with sigaction.\n"));
	if (send_message(ft_atoi(argv[1]), argv[2]) != 0)
		return (1);
	if (send_message(ft_atoi(argv[1]), "\n") != 0)
		return (1);
	return (EXIT_SUCCESS);
}
