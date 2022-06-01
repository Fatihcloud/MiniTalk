/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbulut <fbulut@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:00:24 by fbulut            #+#    #+#             */
/*   Updated: 2022/05/31 17:09:07 by fbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_transform(char y, int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((y >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(42);
	}
}

int	main(int argc, char **argv)
{
	char	*messege;
	int		i;
	int		pid;

	pid = ft_atoi(argv[1]);
	i = 0;
	if (argc == 3)
	{
		messege = argv[2];
		while (messege[i])
		{
			ft_transform(messege[i], pid);
			i++;
		}
		if (*messege)
			ft_transform('\n', pid);
	}
	else
		ft_printf("good luck but try again");
	return (0);
}
