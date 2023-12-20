/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:22:04 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 00:22:06 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	exit_err(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	sleep_one_second(void)
{
	int	i;

	i = 0;
	i = sleep(1);
	if (i == 0)
		exit_err("No respond\n");
}

int	process_id_validate(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!('0' <= arg[i] && arg[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
