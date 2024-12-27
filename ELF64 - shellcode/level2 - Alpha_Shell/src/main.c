#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <seccomp.h>

void init() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

void sandbox() {
    scmp_filter_ctx ctx;

    ctx = seccomp_init(SCMP_ACT_ALLOW);
    seccomp_rule_add(ctx, SCMP_ACT_KILL_PROCESS, SCMP_SYS(open), 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL_PROCESS, SCMP_SYS(read), 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL_PROCESS, SCMP_SYS(readv), 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL_PROCESS, SCMP_SYS(write), 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL_PROCESS, SCMP_SYS(writev), 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL_PROCESS, SCMP_SYS(execve), 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL_PROCESS, SCMP_SYS(execveat), 0);
    seccomp_load(ctx);
}

int main(int argc, char **argv) {
    void *addr;
    int len;
    int i;
    char buf[0x200];

    init();

    __asm__("jnz code;");
	__asm__("jz code;");
	__asm__(".byte 0xe8");
	__asm__("code:");

    void *mapped_mem = mmap((void *)0x100000000, 0x1000, PROT_READ | PROT_WRITE | PROT_EXEC, 
                MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mapped_mem == MAP_FAILED) {
        puts("It seems that something wrong happened!");
        exit(1);
    } else {
        puts("Radiant powers, deadly tech. Here we go!");
        len = read(0, buf, 0x150);
        for (i = 0; i < len; ++i) {
            if (!((buf[i] > 0x2f && buf[i] < 0x3a) ||   // 数字 0-9
                (buf[i] > 0x40 && buf[i] < 0x5b) ||   // 大写字母 A-Z
                (buf[i] > 0x60 && buf[i] < 0x7b))) {  // 小写字母 a-z
                puts("Invalid character detected!");
                exit(1);
            }
        }
        sandbox();
        memcpy(mapped_mem, buf, 0x150);
        ((void (*)())mapped_mem)();
        return 0;
    }
}
