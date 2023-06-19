/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdurai <dabdurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:19:20 by dabdurai          #+#    #+#             */
/*   Updated: 2023/01/24 22:42:08 by dabdurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_message(int signum)
{
	static int	power;
	static int	byte;

	if (signum == SIGUSR1)
		byte += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		ft_putchar_fd(byte, 1);
		if (byte == '\0')
			exit (EXIT_SUCCESS);
		power = 0;
		byte = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("server PID [", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("]\n", 1);
	signal(SIGUSR1, convert_message);
	signal(SIGUSR2, convert_message);
	while (1)
		pause();
}
