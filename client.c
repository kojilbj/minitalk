/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:41:01 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/16 15:48:55 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	}
	if (usleep(50) != 0)
		exit_err("usleep\n");
}

void	send_zero(int pid, int digits)
{
	while (digits < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			exit_err("Wrong Process ID\n");
		digits++;
		if (usleep(50) != 0)
			exit_err("usleep\n");
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
	int	pid;

	if (ac != 3)
		exit_err("Invalid argument\n");
	pid = ft_atoi(av[1]);
	while (*av[1])
	{
		if(!('0' <= *av[1] && *av[1] <= '9'))
			exit_err("Invalid Process ID\n");
		av[1]++;
	}
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
