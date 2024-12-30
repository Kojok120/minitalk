/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:37:59 by kokamoto          #+#    #+#             */
/*   Updated: 2024/12/29 22:20:03 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <signal.h>
#include <unistd.h>

void send_char(pid_t pid, unsigned char *c, size_t len)
{
    size_t byte_index;
    int bit;
    
    byte_index = 0;
    while (byte_index < len)
    {
        bit = 7;
        while (bit >= 0)
        {
            if (c[byte_index] & (1 << bit))
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(1000);
            bit--;
        }
        byte_index++;
    }
}

void send_str(pid_t pid, char *str)
{
    size_t i;
    size_t len;
    unsigned char *ustr;

	i = 0;
	ustr = (unsigned char *)str;
    while (ustr[i])
    {
        if ((ustr[i] & 0x80) == 0)
            len = 1;
        else if ((ustr[i] & 0xE0) == 0xC0)
            len = 2;
        else if ((ustr[i] & 0xF0) == 0xE0)
            len = 3;
        else if ((ustr[i] & 0xF8) == 0xF0)
            len = 4;
        else
        {
            i++;
            continue;
        }
        send_char(pid, &ustr[i], len);
        i += len;
    }
    send_char(pid, '\0', 1);
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
