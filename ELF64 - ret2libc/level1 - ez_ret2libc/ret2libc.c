#include<stdio.h>

void init()
{
	setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
	setvbuf(stderr,0,2,0);
}

void gadget() {
    __asm__("pop %rdi;ret");
}

void vuln()
{
	char buf[0x50];
	puts("RET2LIBC >_<");
	read(0, buf, 0x80);
	return;
}

int main()
{
	init();
	vuln();
	return 0;
}