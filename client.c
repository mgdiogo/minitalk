/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:38:34 by sark              #+#    #+#             */
/*   Updated: 2023/05/12 19:41:50 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	ft_atoi(char *str)
{
	long	nb;
	int		len;
	int		i;

	len = 0;
	while (str && str[len])
		len++;
	i = 0;
	nb = 0;
	while (i < len)
		nb = (nb * 10) + (str[i++] - 48);
	return (nb);
}

void	char_to_bit(int pid, char c)
{
	int	i;
	int	chr;
	int	bit_array[7];

	i = 6;
	chr = c;
	while (i >= 0)
	{
		if ((chr & 1) == 0)
			bit_array[i] = 0;
		else if ((chr & 1) == 1)
			bit_array[i] = 1;
		if (chr > 0)
			chr >>= 1;
		i--;
	}
	i = 7;
	while (i-- >= 0)
	{
		if (bit_array[i] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	id;

	if (argc != 3)
		write (1, "Please use two arguments only: './client string'\n", 50);
	else
	{
		id = ft_atoi(argv[1]);
		while (argv[2] && *argv[2])
			char_to_bit(id, *argv[2]++);
		char_to_bit(id, 10);
	}
	return (0);
}
