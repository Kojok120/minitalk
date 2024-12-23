/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:38:11 by kokamoto          #+#    #+#             */
/*   Updated: 2024/12/23 22:08:44 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <signal.h>
#define MAX_STR_LENGTH 10000000

static void	sig_handler(int sig)
{
	static char	buf[MAX_STR_LENGTH] = {'\0', };
	static int	bit = 7;
	static int	i = 0;

	if (sig == SIGUSR1)
		buf[i] |= (1 << bit);
	if (sig == SIGUSR2)
		buf[i] &= ~(1 << bit);
	bit--;
	if (bit == -1)
	{
		bit = 7;
		if (buf[i] == '\0')
		{
			write(1, buf, i);
			i = 0;
		}
		else
		{
			i++;
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

int main(void)
{
    pid_t pid;
    struct sigaction act;

    // sigaction構造体の初期化
    act.sa_handler = sig_handler;     // シグナルハンドラの設定
    sigemptyset(&act.sa_mask);        // シグナルマスクの初期化
    act.sa_flags = 0;                 // フラグの設定

    pid = getpid();
    ft_putint_fd(pid, 1);
    write(1, "\n", 1);

    // シグナルハンドラの設定（ループの前に1回だけ）
    if (sigaction(SIGUSR1, &act, NULL) == -1 || 
        sigaction(SIGUSR2, &act, NULL) == -1)
    {
        return (1);    // エラーハンドリング
    }

    while (1)
    {
        pause();
    }
    return (0);
}
