#include <stdio.h>
#include <signal.h>
#include "./libft/libft.h"

static void send_string(int pid, char *str)
{
	char c;
	int i;

	while (*str)
	{
		c = *str++;
		i = 8;
		while (--i >= 0)
		{
			if ((c >> i) % 2)
			{
				kill(pid, SIGUSR1);
				usleep(10);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(10);
			}
		}
	}
}

int main(int argc, char **argv)
{
	ft_putstr_fd("Client PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);

	if (argc == 3)
	{
		int pid = ft_atoi(argv[1]);
		send_string(pid, argv[2]);
	}
	return (0);
}
