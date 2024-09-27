#include<stdio.h>

void init()
{
	setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
	setvbuf(stderr,0,2,0);
}

void magic() {
    __asm__("pop %rdi");
}

void vuln()
{
	char buf[100];
	gets(buf);
}

int main()
{
	init();
	vuln();
	return 0;
}