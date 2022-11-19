/* Copyright 2022 Sergey Ivanov */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char buf[512];
    memset(buf, 0, sizeof(buf));

    while (1) {
        ssize_t n = read(STDIN_FILENO, buf, sizeof(buf) / 2);

        if (n < 0) {
            return 0;
        }

        for (size_t i = 0; i < (size_t)n; ++i) {
            if (buf[i] == 'r') {
                buf[i] = 'w';
            } else if (buf[i] == ' ') {
                if (i % 7 == 0) {
                    memmove(&buf[i+5], &buf[i+1], sizeof(buf)/2 - i);
                    const char uwu[] = " UwU ";
                    memcpy(&buf[i], &uwu, 5);
                    n += 5;
                    i += 5;
                } else if (i % 15 == 0) {
                    memmove(&buf[i+5], &buf[i+1], sizeof(buf)/2 - i);
                    const char uwu[] = " OwO ";
                    memcpy(&buf[i], &uwu, 5);
                    n += 5;
                    i += 5;
                }
            }
        }

        write(STDOUT_FILENO, buf, n);
    }
}

