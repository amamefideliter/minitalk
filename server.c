/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:07:58 by dzubkova          #+#    #+#             */
/*   Updated: 2024/02/27 19:08:36 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sighandler(int signum);
static void	get_character(int value);

static int	g_val = 1;

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = sighandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	pid = getpid();
	ft_putstr_fd(ft_itoa(pid), 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1
			|| sigaction(SIGUSR2, &sa, NULL) == -1)
			return (1);
	}
	return (0);
}

static void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		g_val = (g_val << 1) | 0;
	else if (signum == SIGUSR2)
		g_val = (g_val << 1) | 1;
	if (g_val >= 128)
		get_character(g_val - 128);
}

static void	get_character(int value)
{
	char	ch;

	ch = value;
	ft_putchar_fd(ch, 1);
	g_val = 1;
}
