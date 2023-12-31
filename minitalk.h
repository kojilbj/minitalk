/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:19:13 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 00:20:23 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>

//utils.c
void	exit_err(char *msg);
int		process_id_validate(char *arg);

//modified_atoi.c
int		modified_atoi(const char *str);

//client.c
void	send_bit(int pid, unsigned char bin);
void	send_zero(int pid, int digits);
int		count_digits(unsigned char bin);
//server.c
void	signal_handler(int signum);

#endif
