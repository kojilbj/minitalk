/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:41:01 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 00:24:18 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	client_signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		usleep(25);
		return ;
	}
	if (signum == SIGUSR2)
		exit(EXIT_SUCCESS);
}

void	send_bit(int pid, unsigned char bin)
{
	if (bin != 0)
		send_bit(pid, bin / 2);
	if (bin != 0)
	{
		if (bin % 2 == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit_err("Wrong Process ID\n");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit_err("Wrong Process ID\n");
		}
		sleep_one_second();
	}
}

void	send_zero(int pid, int digits)
{
	while (digits < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			exit_err("Wrong Process ID\n");
		digits++;
		sleep_one_second();
	}
}

int	count_bin_digits(unsigned char bin)
{
	int	digits;

	digits = 0;
	while (bin != 0)
	{
		bin /= 2;
		digits++;
	}
	return (digits);
}

int	main(int ac, char *av[])
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = client_signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (ac != 3)
		exit_err("Invalid argument\n");
	if (process_id_validate(av[1]) == 1)
		exit_err("Invalid Process ID\n");
	pid = modified_atoi(av[1]);
	if (pid < 1)
		exit_err("Invalid Process ID\n");
	while (*av[2])
	{
		send_zero(pid, count_bin_digits(*av[2]));
		send_bit(pid, *av[2]);
		av[2]++;
	}
	send_zero(pid, count_bin_digits(0));
	return (0);
}
