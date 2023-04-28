#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main()
{
	int fd[2];
	char buf1[25] = "just a test\n";
	char buf2[50];
	fd[0] = open("file1", O_RDWR); // O_RDWR-open for reading and writing
	fd[1] = open("file2", O_RDWR);
	write(fd[0], buf1, strlen(buf1)); // strlen-determines the length of string excluding the ending null character
	printf("\n Enter the text now..."); // print
	scanf("\n %s", buf1); // taking input
	
	printf("\n Cat file1 is\n hai"); // print
	write(fd[0], buf1, strlen(buf1));
	lseek(fd[0], SEEK_SET, 0); // lseek-changes the current file offset to a new position in the file
	read(fd[0], buf2, sizeof(buf1));
	write(fd[1], buf2, sizeof(buf2));
	close(fd[0]);
	close(fd[1]);
	printf("\n");
	return 0;
}
