/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:40:52 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/09 13:13:10 by watanabekoj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

void	signal_handler(int signum)
{
	int			bin;
	static int	bit_count = 0;
	static char	c = 0;

	bit_count++;
	bin = signum - 30;
	c = c << 1;
	c += bin;
	if (bit_count == 8)
	{
		bit_count = 0;
		if (c == 0)
			ft_printf("\n");
		ft_printf("%c", c);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("sigaction\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("sigaction\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	pid = getpid();
	ft_printf("Server is running!\nProcess ID is \"%d\"\n", pid);
	while (1)
	{
		pause();
		usleep(250);
	}
	return (0);
}
