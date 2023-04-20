/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:38:05 by sark              #+#    #+#             */
/*   Updated: 2023/04/20 02:28:35 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	ft_putnbr(int nbr)
{
	char	temp;

	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	temp = nbr % 10 + '0';
	write(1, &temp, 1);
}

void	handle_signal(int pid)
{
	if (pid == SIGUSR1)
		write (1, "SIGUSR1\n", 8);
	else if (pid == SIGUSR2)
		write (1, "SIGUSR2\n", 8);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write (1, "Server PID: ", 13);
	ft_putnbr(getpid());
	write (1, "\n", 1);
	while (1)
		usleep(100);
	return (0);
}
