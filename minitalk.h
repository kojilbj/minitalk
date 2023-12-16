# ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>

//modified_atoi.c
int	modified_atoi(const char *str);

//client.c
void	exit_err(char *msg);
void	send_bit(int pid, unsigned char bin);
void	send_zero(int pid, int digits);

//server.c
void	signal_handler(int signum);

# endif
