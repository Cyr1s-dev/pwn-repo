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
	while(i = 2){
		int i=0;
		char buf[100];
		write(1,"Input:\n",7);
		read(0,buf,124);
		printf("%s",buf);
		i += 1;
	}
}

int main()
{
	init();
	vuln();
	return 0;
}