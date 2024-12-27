all:
	gcc -o attachment main.c -fPIE -pie -fstack-protector-all -D_FORTIFY_SOURCE=2 -Wl,-z,relro -Wl,-z,now -D_GLIBCXX_ASSERTIONS -lseccomp