#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func(int key){
	char buf[16];
	printf("Overflow me : ");
	gets(buf);	// Overflow me!
	if(key == 0xd093d093){
		system("/bin/sh");
	}
	else{
		printf("Try again...\n");
	}
}
int main(){
	func(0xdeadbeef);
	return 0;
}
