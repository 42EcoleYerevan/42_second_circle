/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:18:41 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/02 18:20:33 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include "./libft/libft.h"

static void	ft_action(int sig, siginfo_t *info, void *context)
{
	(void) context;
	(void) info;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("ok!\n", 1);
		exit(0);
	}
	else
		exit(1);
}

static void	send_char(int pid, char c)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if ((c >> i) % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

static void	send_string(int pid, char *str)
{
	char	c;

	while (*str)
	{
		c = *str++;
		send_char(pid, c);
	}
	send_char(pid, '\0');
	pause();
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	s_sigaction;

	if (argc == 3)
	{
		s_sigaction.sa_flags = SA_SIGINFO;
		s_sigaction.sa_sigaction = ft_action;
		sigaction(SIGUSR1, &s_sigaction, 0);
		pid = ft_atoi(argv[1]);
		send_string(pid, argv[2]);
	}
	return (0);
}
