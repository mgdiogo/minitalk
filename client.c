/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:38:34 by sark              #+#    #+#             */
/*   Updated: 2023/04/19 00:09:53 by sark             ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	id;

	if (argc != 2)
	{
		write (1, "Invalid arguments\n", 19);
	}
	else
	{
		id = ft_atoi(argv[1]);
		printf("Connected to server: %d\n", id);
		kill(id, SIGUSR1);
	}
	return (0);
}
