#include <stdio.h>
#include <unistd.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int trim(char buff[]) {
	buff[strcspn(buff, "\r\n")] = 0;
}

int main() {
	int fd, i, n, rno, found=0;
	char buff[32];
	fd = open("students.txt", O_RDWR | O_CREAT | O_TRUNC, 0755);
	printf("Enter number of students : ");
	fgets(buff, 32, stdin);
	trim(buff);
	n = atoi(buff);
	for (i=0; i<n; i++) {
		printf("Student %d\n", i+1);

		printf("Enter rno : ");
		fgets(buff, 32, stdin);
		trim(buff);
		write(fd, buff, sizeof(buff));

		printf("Enter name : ");
		fgets(buff, 32, stdin);
		trim(buff);
		write(fd, buff, sizeof(buff));

		printf("Enter branch : ");
		fgets(buff, 32, stdin);
		trim(buff);
		write(fd, buff, sizeof(buff));
		printf("\n");
		
	}
	lseek(fd, 0, SEEK_SET);
	printf("Enter rno of student to read : ");
	fgets(buff, 32, stdin);
	rno = atoi(buff);
	printf("\n");
	for(i=0; i<n; i++) {
		read(fd, buff, sizeof(buff));
		if (atoi(buff) == rno) {
			found = 1;
			printf("STUDENT FOUND\n");
			read(fd, buff, sizeof(buff));
			printf("Name : %s\n", buff);
			read(fd, buff, sizeof(buff));
			printf("Branch : %s\n", buff);
			break;
		} else {
			lseek(fd, 64, SEEK_CUR);
		}
	}
	if (!found) {
		printf("STUDENT NOT FOUND\n");
	}
	close(fd);
	return 0;
}
