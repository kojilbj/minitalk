/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:21:55 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 00:21:58 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	exit_err(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
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
