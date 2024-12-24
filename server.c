/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:38:11 by kokamoto          #+#    #+#             */
/*   Updated: 2024/12/24 18:47:14 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <limits.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define CHUNK_SIZE 256

static void sig_handler(int sig)
{
    static int          bit = 7;
    static int          i = 0;
    static unsigned char buf[BUFFER_SIZE] = {0};

    // ビット操作
    if (sig == SIGUSR1)
        buf[i] |= (1 << bit);
    if (sig == SIGUSR2)
        buf[i] &= ~(1 << bit);

    bit--;
    if (bit == -1)
    {
        bit = 7;
        if (buf[i] == '\0' || i >= BUFFER_SIZE - 1)
        {
            write(1, buf, i);
            write(1, "\n", 1);
            memset(buf, 0, BUFFER_SIZE);
            i = 0;
        }
        else
        {
            i++;
            // CHUNK_SIZEバイトたまったら出力
            if (i >= CHUNK_SIZE)
            {
                write(1, buf, i);
                // 出力後はバッファをクリア
                memset(buf, 0, BUFFER_SIZE);
                i = 0;
            }
        }
    }
}

void    ft_putint_fd(int n, int fd)
{
    char    c;

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
    pid_t           pid;
    struct sigaction    act;

    // シグナルハンドラの設定
    act.sa_handler = sig_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    pid = getpid();
    ft_putint_fd(pid, 1);
    write(1, "\n", 1);

    if (sigaction(SIGUSR1, &act, NULL) == -1 ||
        sigaction(SIGUSR2, &act, NULL) == -1)
    {
        return (1);
    }

    while (1)
    {
        pause();
    }
    return (0);
}
