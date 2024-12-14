#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>
#include <signal.h>

#define INPUT_LEN 64
#define ENCODED_LEN 128
#define REFERENCE_LEN 50
const char base32_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

void init()
{
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
}

void wr1te(int fd,char *cont,int len)
{
    write(fd,cont,len);
}

int backd00r() {
	system("/bin/sh");
}

void handler(int sig) {
    char banner00[] = "\nTime is up!\n";
    wr1te(1,banner00,strlen(banner00));
    _exit(0);
}

int gift() {
	char buf[32];
	gets(buf);
	printf(buf);
	fflush(stdout);
	gets(buf);
}

void chal1(char *input, size_t size) {
    alarm(2);
    char banner01[] = "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";
    char banner02[] = "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";
    char banner03[] = "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";
    char banner04[] = "░░░░███████▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓██▒░░▓██▒░░░░░░░░░░░▒██▒░░░░░░░░░░░███░░░░░░░░▒▒▒░░░░░░░▒▓█████▒▓████████▓░███████▒░░\n";
    char banner05[] = "░░░░███░░▒███▒░▓▓▓▓█░░▓▓▓█▓▓▒░░░▓▓██▓▓▒░░▒▓▓█▓▓░░░▓▓▓▒▓█▓▓░░░░░░███░▒███░░░▒▓▓▒▓██▓░░▒▓▓░░░▒▓▓██▓▓░░███▓▓█▓▒░▒▓███▓░░░░░███▓▒░░░░░░░▓██▓░░░▒███░░░░░░░\n";
    char banner06[] = "░░░▒██▓░░░▒██▓░███▓▒░░▒▒▒▓███░▓██▓▒▓██▓░███▒▒▓██▒░███▓▒███▒░░░░░███▒███░░░░▓███▒▓██▓░▓██░░███▒▒███░░███▓▒███▒░▓██▓▒░░░░▒███░░░░░░░░░▓██▒░░░▒██████▒░░░\n";
    char banner07[] = "░░░▒██▓░░▒███▒░███░░░▓██▓▓██▓░███░░▓██▒░███░░▒██▓░███░░▒██▒░░░░░███░▒███░░░███░░▒██▓░▓██░▒██▒░░███░░██▓░░▓██░░▓██▒░░░░░░███▒░░░░░░░░███▒░░░▒██▓░░░░░░░\n";
    char banner08[] = "░░░▓███████▓░░░██▓░░░███▓▒██▓░▒███████▒░▒██████▓░░██▓░░▓██▒░░░░▒███░░▒███▒░███░░▒██▒░███░░▓███████░▒██▒░░███░░▓████░░░░░░▓██████░░░░███░░░░▓██▓░░░░░░░\n";
    char banner09[] = "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒███▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒░▒███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";
    char banner010[] = "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓███▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▓████▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";
    char banner011[] = "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";
    char banner012[] = "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";
    char banner013[] = "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";
    char banner014[]="Are you ready to complete my quiz? \nPlease give me your token: ";
    wr1te(1,banner01,strlen(banner01));
    wr1te(1,banner02,strlen(banner02));
    wr1te(1,banner03,strlen(banner03));
    wr1te(1,banner04,strlen(banner04));
    wr1te(1,banner05,strlen(banner05));
    wr1te(1,banner06,strlen(banner06));
    wr1te(1,banner07,strlen(banner07));
    wr1te(1,banner08,strlen(banner08));
    wr1te(1,banner09,strlen(banner09));
    wr1te(1,banner010,strlen(banner010));
    wr1te(1,banner011,strlen(banner011));
    wr1te(1,banner012,strlen(banner012));
    wr1te(1,banner013,strlen(banner013));
    wr1te(1,banner014,strlen(banner014));
    fgets(input, size, stdin);
    alarm(0);
    input[strcspn(input, "\n")] = 0;
}

void encode(const char *input, char *output) {
    int inputLen = strlen(input);
    int outputIndex = 0;
    int bitBuffer = 0;
    int bitsLeft = 0;
    int mask = 0x1F; // Binary mask of 5 bits

    for (int i = 0; i < inputLen; i++) {
        int temp = input[i] ^ 0xFF; // XOR operation
        bitBuffer = (bitBuffer << 8) | (temp & 0xFF);
        bitsLeft += 8;
        while (bitsLeft >= 5) {
            output[outputIndex++] = base32_alphabet[(bitBuffer >> (bitsLeft - 5)) & mask];
            bitsLeft -= 5;
        }
    }

    if (bitsLeft > 0) {
        output[outputIndex++] = base32_alphabet[(bitBuffer << (5 - bitsLeft)) & mask];
    }

    output[outputIndex] = '\0'; // Null-terminate the string
}

int compare(const char *encoded, const char *correct, size_t len) {
    for (size_t i = 0; i < len; i++) {
        if ((unsigned char)encoded[i] != correct[i]) {
            return 0; // Not a match
        }
    }
    return 1; // Match
}

uint8_t lfsr_h(uint8_t lfsr) {
    uint8_t lsb = lfsr & 0x01;
    lfsr >>= 1;
    if (lsb == 1) {
        lfsr ^= 0xB8; // 二进制10111000
    }
    return lfsr;
}

int main() {
    init();

    signal(SIGALRM, handler);

    int steps = 160;
    uint8_t lfsr = 0xff, num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    char input[INPUT_LEN];
    char calc[20];
    char encoded[ENCODED_LEN];
    char token[] = {0x58, 0x4F, 0x57, 0x33, 0x4A, 0x50, 0x46, 0x4C, 0x58, 0x47, 0x43, 0x4B, 0x37, 0x54, 0x57, 0x4D,
                    0x58, 0x36, 0x47, 0x4D, 0x5A, 0x49, 0x47, 0x4F, 0x54, 0x4B, 0x37, 0x5A, 0x4A, 0x49, 0x45, 0x4C,
                    0x53, 0x36, 0x35, 0x4B, 0x42, 0x48, 0x55, 0x33, 0x54, 0x4F, 0x47, 0x32, 0x42, 0x54, 0x34, 0x5A,
                    0x55, 0x44, 0x45, 0x4A, 0x50, 0x47, 0x56, 0x41, 0x54, 0x53, 0x37, 0x4A, 0x44, 0x50, 0x56, 0x4E,
                    0x51, 0x32, 0x51, 0x4C, 0x37, 0x45, 0x4D, 0x33, 0x55, 0x43, 0x48, 0x5A, 0x4E, 0x47, 0x55, 0x43};
    
    // lfsr prepare
    srand(time(NULL));
    lfsr = rand() % 256;

    // input
    chal1(input, sizeof(input));
    if (strlen(input) > REFERENCE_LEN) {
        char banner1[]="Out of length.\n";
        wr1te(1,banner1,strlen(banner1));
        exit(EXIT_FAILURE); // Exit the program with an error status
    }

    // decode
    encode(input, encoded);

    // lfsr
    for (int i = 0; i < steps; i++) {
        lfsr = lfsr_h(lfsr);
        if (i == steps - 4) num4 = lfsr;
        if (i == steps - 3) num3 = lfsr;
        if (i == steps - 2) num2 = lfsr;
        if (i == steps - 1) num1 = lfsr;
    }

    // compare
    if (compare(encoded, token, sizeof(token))) {
        char banner2[]="Right!\n";

        alarm(2);
        
        wr1te(1,banner2,strlen(banner2));
        char banner3[]="Please solve this calculation:\n";
        
        int result = (num1 - num2) * num3 % num4;
        printf("(( %d - %d ) * %d ) %% %d=?\n", num1, num2, num3, num4);
        
        fgets(calc, sizeof(calc), stdin);
        alarm(0);

        int ca1c = atoi(calc);
        if ( ca1c != result )
        {
            printf("You input:%d , but answer:%d", ca1c, result);
            exit(EXIT_FAILURE);
        }
        else{
            char banner4[]="Right! Here's your gift:\n";
            wr1te(1,banner4,strlen(banner4));
            gift();
        }
    } else {
        printf("Not Right\n");
    }
    return 0;
}

__attribute__((naked)) void func() {
    __asm__("pop %rdi");
    __asm__("ret");
}