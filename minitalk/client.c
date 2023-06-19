/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdurai <dabdurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:19:13 by dabdurai          #+#    #+#             */
/*   Updated: 2023/01/24 22:28:18 by dabdurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_putstr_fd("Invalid arguments!\n", 1);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
		{
			ft_putstr_fd("Invalid pid\n", 1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		exit (EXIT_FAILURE);
	while (argv[2][i])
		convert_char(argv[2][i++], pid);
	exit(EXIT_SUCCESS);
}
