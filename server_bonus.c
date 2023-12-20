/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:40:52 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 00:37:30 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_respond(pid_t pid, char c)
{
	if (c == 0)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit_err("Missed kill\n");
		ft_printf("\n");
	}
	else
	{
		ft_printf("%c", c);
		if (kill(pid, SIGUSR1) == -1)
			exit_err("Missed kill\n");
	}
}

void	server_signal_handler(int signum, siginfo_t *info, void *old)
{
	static int	bit_count = 0;
	static char	c = 0;

	(void)old;
	bit_count++;
	c = (c << 1) + (signum - 30);
	usleep(25);
	if (bit_count == 8)
	{
		send_respond(info->si_pid, c);
		c = 0;
		bit_count = 0;
	}
	else
	{
		if (kill(info->si_pid, SIGUSR1) == -1)
			exit_err("Missed kill\n");
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = server_signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit_err("sigaction\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit_err("sigaction\n");
	pid = getpid();
	ft_printf("Bonus Server is running!\nProcess ID is \"%d\"\n", pid);
	while (1)
	{
		pause();
		usleep(5);
	}
	return (0);
}
