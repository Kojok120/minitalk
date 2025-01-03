/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:38:11 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/02 21:53:17 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

static void	sig_handler(int sig)
{
	static int				bit = 7;
	static int				i = 0;
	static unsigned char	buf[BUFFER_SIZE] = {0};

	if (sig == SIGUSR1)
		buf[i] |= (1 << bit);
	if (sig == SIGUSR2)
		buf[i] &= ~(1 << bit);
	bit--;
	if (bit == -1)
	{
		bit = 7;
		i++;
		if (buf[i - 1] == '\0' || i >= BUFFER_SIZE)
		{
			write(1, buf, i);
			ft_memset(buf, 0, BUFFER_SIZE);
			i = 0;
		}
	}
}

void	ft_putint_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
		return ;
	}
	else
	{
		c = n % 10 + '0';
		n = n / 10;
		ft_putint_fd(n, fd);
		write(fd, &c, 1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;

	act.sa_handler = sig_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	pid = getpid();
	ft_putint_fd(pid, 1);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &act, NULL) == -1 || sigaction(SIGUSR2, &act,
			NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}
