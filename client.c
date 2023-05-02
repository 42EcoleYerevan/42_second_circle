#include <stdio.h>
#include <signal.h>
#include "./libft/libft.h"

int ok;

static void ft_action(int sig, siginfo_t *info, void *context)
{
	(void) context;
	(void) info;
	if (sig == SIGUSR1)
		ok = 0;
	else
		ok = 1;
}

static void send_string(int pid, char *str)
{
	char c;
	int i;

	while (*str)
	{
		c = *str++;
		i = 7;
		while (i >= 0)
		{
			if ((c >> i) % 2)
			{
				kill(pid, SIGUSR1);
				usleep(100);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(100);
			}
			if (ok == 1)
			{
				pause();
			}
			else
				i--;
		}
	}
	i = 8;
	while (--i >= 0)
		kill(pid, SIGUSR2);
}

int main(int argc, char **argv)
{
	int pid;
	struct sigaction s_sigaction;

	if (argc == 3)
	{
		ok = 1;
		s_sigaction.sa_flags = SA_SIGINFO;
		s_sigaction.sa_sigaction = ft_action;
		sigaction(SIGUSR1, &s_sigaction, 0);
		sigaction(SIGUSR2, &s_sigaction, 0);
		pid = ft_atoi(argv[1]);
		send_string(pid, argv[2]);
	}
	return (0);
}
