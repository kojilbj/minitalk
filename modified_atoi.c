/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watanabekoji <watanabekoji@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:44:06 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/16 15:42:23 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	exit_err(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static long	modified_strtol(const char *str, int sign)
{
	int	result;
	int	tmp;

	result = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		tmp = result;
		result = result * 10 + *str - '0';
		if (result < tmp)
		{
			if (sign == -1)
				exit_err("Process ID must be INT\n");
			else
				exit_err("Process ID must be INT\n");
		}
		str++;
	}
	return (result * sign);
}

int	modified_atoi(const char *str)
{
	long	result;
	int		sign;
	int		sign_fg;

	sign_fg = 0;
	result = 0;
	sign = 1;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		if (sign_fg == 1)
			return (result);
		sign_fg = 1;
		str++;
	}
	return ((int)(modified_strtol(str, sign)));
}
