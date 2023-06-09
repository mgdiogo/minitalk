/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:38:05 by sark              #+#    #+#             */
/*   Updated: 2023/05/12 17:59:56 by mpedroso         ###   ########.fr       */
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

int	bit_to_char(int pos)
{
	int	res;

	res = 1;
	if (pos == 0)
		return (res);
	else
	{
		while (pos > 0)
		{
			res *= 2;
			pos--;
		}
	}
	return (res);
}

void	handle_signal(int pid)
{
	static int		i;
	static int		res;
	int				bit;

	if (pid == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	if (bit == 1)
		res += bit_to_char(i);
	i++;
	if (i == 8)
	{
		write (1, &res, 1);
		i = 0;
		res = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write (1, "Server is up and running on PID: ", 34);
	ft_putnbr(getpid());
	write (1, "\n", 1);
	while (1)
		pause();
	return (0);
}
