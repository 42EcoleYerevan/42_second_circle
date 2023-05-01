#include <stdio.h>
#include <signal.h>
#include "LIBFT/libft.h"

int main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(SIGUSR1, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(SIGUSR2, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
