#include <stdio.h>
#include <unistd.h>

void init()
{
    setvbuf(stdin, 0, 2, 0); 
    setvbuf(stdout, 0, 2, 0); 
    setvbuf(stderr, 0, 2, 0); 
}

void gadget()
{
	__asm__("pop %rdi;ret");
}

void vuln()
{
    char buf[0x30];
    puts("Do you know Stack_Pivoting?");
    read(0, buf, 0x40); 
}

int main()
{
    init();
    vuln();

    return 0;
}