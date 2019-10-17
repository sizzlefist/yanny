#include <common/stdio.h>
#include <common/stdlib.h>
#include <common/stdarg.h>
#include <kernel/uart.h>

char getc(void) {
    return uart_getc();
}

void putc(char c) {
    uart_putc(c);
}

void puts(const char * str) {
    int i;
    for (i = 0; str[i] != '\0'; i ++)
        putc(str[i]);
}

void gets(char * buf, int buflen) {
    int i;
    char c;

    // Leave a spot for null char in buffer
    for (i = 0; (c = getc()) != '\r' && buflen > 1; i++, buflen--) {
        //putc(c);
        buf[i] = c;
    }

    //putc('\n');
    if (c == '\n') {
        buf[i] = '\0';
    }
    else
        buf[buflen-1] = '\0';
}

int printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int n = 0;

    int state = 0;

    while(format[n] != '\0')
    {
        switch(state)
        {
            case 0:
                if(format[n] != '%')
                    putc(format[n]);
                else
                    state = 1;
                break;
            case 1:
                if(format[n] == '%')
                {
                    putc('%');
                    state = 0;
                }
                else
                {
                    switch(format[n])
                    {
                        case 's':
                            break;
                        case 'd':
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 2:
                break;
            case 3:
                break;
        }

        n++;
    }

    va_end(args);

    return 0;
}