/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:18:41 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/03 15:16:44 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include "./libft/libft.h"

static void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
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
}

int	main(int argc, char **argv)
{
	int					pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_string(pid, argv[2]);
	}
	return (0);
}
