/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:18:45 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/08 15:42:17 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include "libft/libft.h"

static void	ft_action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static int 				n = 0;

	(void) context;
	n = info->si_pid;
	if (info->si_pid == n)
	{
		i++;
		c <<= 1;
		if (sig == SIGUSR1)
			c |= 1;
		if (i == 8)
		{
			if (c == 0)
				kill(info->si_pid, SIGUSR2);
			else
				ft_putchar_fd(c, 1);
			i = 0;
			c = 0;
		}
		usleep(40);
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = ft_action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sigaction.sa_mask);
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
