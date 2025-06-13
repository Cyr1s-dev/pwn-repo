#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "magic.pb-c.h" // 根据 message.proto 生成的头文件

#define BUFFER_SIZE 64 
#define PROTO_BUF_SIZE 0x1010 

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void backdoor() {
    system("/bin/sh");
}

int main() {
    char buf[BUFFER_SIZE];
    char proto_buf[PROTO_BUF_SIZE];

    init(); 
    
    memset(proto_buf, 0, 0x1000);
    
    puts("Can u ret2text with Protobuf?");
    
    ssize_t bytes_read = read(STDIN_FILENO, proto_buf, PROTO_BUF_SIZE);

    // Protobuf 反序列化
    Magic__Message *magic_message = magic__message__unpack(NULL, bytes_read, (uint8_t *)proto_buf);
    if (magic_message == NULL) {
        puts("Protobuf Parse Error!");

        return 1;
    }

    // 将magic_content写入buf变量中
    if (magic_message->magic_content.data != NULL) {
        memcpy(buf, magic_message->magic_content.data,
               magic_message->magic_content.len);
        printf("Content copied to buf: %s\n", buf);
    } else {
        puts("No content found in Protobuf message!");
    }
}
