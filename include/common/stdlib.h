#ifndef STDLIB_H
#define STDLIB_H

typedef int bool;

#define true 1
#define false 0

void memcpy(void * dest, void * src, int bytes);

void bzero(void * dest, int bytes);

char * itoa(int i);

int itoa2(int num, char * str, int base);

#endif
