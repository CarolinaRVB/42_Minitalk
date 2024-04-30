/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:29:21 by crebelo-          #+#    #+#             */
/*   Updated: 2023/12/13 12:29:21 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	int	i;

	i = 0;
	if (argc != 3)
		return (ft_error_exit("Error\nInvalid number of arguments."));
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) == 0)
			return (ft_error_exit("Error\nInvalid PID number."));
		i++;
	}
	if (!argv[2][0])
		return (ft_error_exit("Error\nEmpty message."));
	if (send_message(ft_atoi(argv[1]), argv[2]) != 0)
		return (1);
	if (send_message(ft_atoi(argv[1]), "\n") != 0)
		return (1);
	return (EXIT_SUCCESS);
}
