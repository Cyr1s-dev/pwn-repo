#include <stdio.h>
#include <string.h>
#include <unistd.h>

void init()
{
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
}

void backdoor()
{
    system("/bin/sh");
}

int main()
{
    char buf[64];
    init();
    char banner[] = "Can u ret2text?\n";
    write(1, banner, strlen(banner));
    gets(buf);

    return 0;
}
