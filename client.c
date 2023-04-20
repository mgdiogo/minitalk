/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:38:34 by sark              #+#    #+#             */
/*   Updated: 2023/04/20 02:22:12 by sark             ###   ########.fr       */
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

void	convert_char(int pid, char c)
{
	int	i;
	int	chr;
	int	bit_array[8];

	i = 7;
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
	while (i < 8)
	{
		if (bit_array[i] == 0)
			kill(pid, SIGURG);
		else if (bit_array[i] == 1)
			kill(pid, SIGUSR2);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	id;

	if (argc != 3)
	{
		write (1, "Invalid arguments\n", 19);
	}
	else
	{
		id = ft_atoi(argv[1]);
		printf("Message sent to %d\n", id);
		convert_char(id, *argv[2]);
	}
	return (0);
}
