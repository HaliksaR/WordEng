#include <stdio.h>
#include <unistd.h>

int main() {
	char buf[128];
	getlogin_r(buf,128);
	printf("%s\n", buf);
	return 0;
}
