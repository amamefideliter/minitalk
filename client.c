/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:07:53 by dzubkova          #+#    #+#             */
/*   Updated: 2024/02/27 19:10:44 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	parse_string(char *string, pid_t pid);
static int	send_charachter(char *tmp, int idx, pid_t pid);

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*string;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	string = argv[2];
	parse_string(string, pid);
	return (0);
}

static void	parse_string(char *string, pid_t pid)
{
	int		ascii_value;
	int		idx;
	char	tmp[7];

	while (*string)
	{
		idx = 0;
		ascii_value = *string;
		while (ascii_value)
		{
			if (ascii_value % 2 == 0)
				tmp[idx++] = '0';
			else
				tmp[idx++] = '1';
			ascii_value /= 2;
		}
		while (idx < 7)
			tmp[idx++] = '0';
		send_charachter(tmp, idx, pid);
		string++;
	}
}

static int	send_charachter(char *tmp, int idx, pid_t pid)
{
	while (idx >= 0)
	{
		if (tmp[idx] == '0')
		{
			if (kill(pid, SIGUSR1))
				return (1);
		}
		else if (tmp[idx] == '1')
		{
			if (kill(pid, SIGUSR2))
				return (1);
		}
		idx--;
		usleep(200);
	}
	return (0);
}
