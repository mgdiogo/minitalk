/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:38:05 by sark              #+#    #+#             */
/*   Updated: 2023/04/19 01:23:40 by sark             ###   ########.fr       */
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

void	handle_sigusr1(int pid)
{
	if (pid == SIGUSR1)
		write (1, "test", 5);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handle_sigusr1;
	sigaction(SIGUSR1, &sa, NULL);
	write (1, "Server PID: ", 13);
	ft_putnbr(getpid());
	write (1, "\n", 1);
	while (1)
		usleep(100);
	return (0);
}
