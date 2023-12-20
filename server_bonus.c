/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:40:52 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/16 15:49:47 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	server_signal_handler(int signum, siginfo_t *info, void *old)
{
	static int	bit_count = 0;
	static char	c = 0;

	old = NULL;
	if (old != NULL)
		ft_printf("%d", old);
	bit_count++;
	c = (c << 1) + (signum - 30);
	usleep(25);
	if (bit_count == 8)
	{
		bit_count = 0;
		if (c == 0)
		{
			kill(info->si_pid, SIGUSR2);
			ft_printf("\n");
		}
		else
		{
			ft_printf("%c", c);
			c = 0;
			kill(info->si_pid, SIGUSR1);
		}
	}
	else
		kill(info->si_pid, SIGUSR1);
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
