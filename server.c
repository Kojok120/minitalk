/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:38:11 by kokamoto          #+#    #+#             */
/*   Updated: 2024/12/29 22:16:29 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <limits.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

static void sig_handler(int sig)
{
    static int bit = 7;
    static int byte_index = 0;
    static unsigned char buf[BUFFER_SIZE] = {0};
    static int utf8_bytes_remaining = 0;

    // ビットを設定
    if (sig == SIGUSR1)
        buf[byte_index] |= (1 << bit);
    if (sig == SIGUSR2)
        buf[byte_index] &= ~(1 << bit);
    bit--;

    // 1バイト完成
    if (bit == -1)
    {
        bit = 7;

        // 新しい文字の開始時にUTF-8バイト数を判定
        if (utf8_bytes_remaining == 0)
        {
            if ((buf[byte_index] & 0x80) == 0)          // ASCII
                utf8_bytes_remaining = 0;
            else if ((buf[byte_index] & 0xE0) == 0xC0)  // 2バイト文字
                utf8_bytes_remaining = 1;
            else if ((buf[byte_index] & 0xF0) == 0xE0)  // 3バイト文字
                utf8_bytes_remaining = 2;
            else if ((buf[byte_index] & 0xF8) == 0xF0)  // 4バイト文字
                utf8_bytes_remaining = 3;
        }
        else
            utf8_bytes_remaining--;

        byte_index++;

        // バッファが一杯になるか、文字列終端に達したら出力
        if (buf[byte_index - 1] == '\0' || byte_index >= BUFFER_SIZE)
        {
            write(1, buf, byte_index - 1);
            memset(buf, 0, BUFFER_SIZE);
            byte_index = 0;
            utf8_bytes_remaining = 0;
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

    act.sa_handler = sig_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    pid = getpid();
    ft_putint_fd(pid, 1);
    write(1, "\n", 1);

    if (sigaction(SIGUSR1, &act, NULL) == -1 ||
        sigaction(SIGUSR2, &act, NULL) == -1)
        return (1);
    while (1)
        pause();
    return (0);
}
