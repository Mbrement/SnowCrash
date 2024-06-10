#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(void){
	int fd = open("./token", O_RDONLY);
	char buffer[2048];
	int max = read(fd, &buffer, 2048);
	buffer[max - 1] = '\0';
	for (int i = 0; buffer[i]; i++)
		buffer[i]-= i;
	printf("'%s'\n", buffer);
}