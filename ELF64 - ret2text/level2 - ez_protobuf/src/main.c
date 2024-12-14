#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "magic.pb-c.h" // 根据 message.proto 生成的头文件

#define BUFFER_SIZE 64 // buf缓冲区大小
#define PROTO_BUF_SIZE 0x1010 // protobuf数据缓冲区大小

// 初始化函数
void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

// 后门函数
void backdoor() {
    system("/bin/sh");
}

int main() {
    char buf[BUFFER_SIZE];
    char proto_buf[PROTO_BUF_SIZE];  // 使用堆而不是栈

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
    if (magic_message->magic_content.data != NULL) {  // 修改：检查data字段
        memcpy(buf, magic_message->magic_content.data,   // 修改：使用data字段
               magic_message->magic_content.len);         // 修改：使用len字段
        printf("Content copied to buf: %s\n", buf);
    } else {
        puts("No content found in Protobuf message!");
    }
}
