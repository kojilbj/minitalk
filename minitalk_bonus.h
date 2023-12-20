# ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "libft/libft.h"
# include <signal.h>

//utils_bonus.c
void	exit_err(char *msg);
void	sleep_one_second(void);
int	process_id_validate(char *arg);

//modified_atoi.c
int	modified_atoi(const char *str);

//client_bonus.c
void	client_signal_handler(int signum);
void	send_bit(int pid, unsigned char bin);
void	send_zero(int pid, int digits);
int	count_bin_digits(unsigned char bin);

//server_bonus.c
void	server_signal_handler(int signum, siginfo_t *info, void *old);

# endif
