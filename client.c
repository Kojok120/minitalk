/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:37:59 by kokamoto          #+#    #+#             */
/*   Updated: 2024/12/24 18:14:49 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <signal.h>
#include <unistd.h>

static void	send_char(pid_t pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit != -1)
	{
		if (c & (1 << bit))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		bit--;
		usleep(1000);
	}
}

static void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign * num > LONG_MAX / 10 || (sign * num * 10 > LONG_MAX - (str[i]
					- '0')))
			return ((int)LONG_MAX);
		if (sign * num < LONG_MIN / 10 || (sign * num * 10 < LONG_MIN + (str[i]
					- '0')))
			return ((int)LONG_MIN);
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (sign * num);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

   if (argc != 3)
   {
       write(2, "Usage: ./client [server_pid] [string]\n", 37);
       return (1);
   }

	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_str(pid, str);
	return (0);
}
