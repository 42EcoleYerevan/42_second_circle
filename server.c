#include <stdio.h>
#include <signal.h>
#include "libft/libft.h"

static void ft_action(int sig, siginfo_t *info, void *context)
{
	static int i = 0;
	static unsigned char	c = 0;

	(void) context;
	(void) info;
	i++;
	c <<= 1;
	if (sig == SIGUSR1)
		c |= 1;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
}

int main(void)
{
	struct sigaction s_sigaction;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = ft_action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
