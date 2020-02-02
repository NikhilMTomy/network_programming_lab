#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 32

struct student {
	int rno;
	char name[BUFF_SIZE];
	char branch[BUFF_SIZE];
} s;

int trim(char buff[]) {
	buff[strcspn(buff, "\r\n")] = 0;
}

int main() {
	int fd, i, n, rno, found=0;
	char buff[BUFF_SIZE];
	//struct student* s = &students;

	fd = open("students.txt", O_RDWR | O_CREAT | O_TRUNC, 0755);
	printf("Enter number of students : ");
	fgets(buff, BUFF_SIZE, stdin);
	trim(buff);
	n = atoi(buff);

	for (i=0; i<n; i++) {
		printf("Student %d\n", i+1);

		printf("Enter rno : ");
		fgets(buff, BUFF_SIZE, stdin);
		trim(buff);
		s.rno = atoi(buff);

		printf("Enter name : ");
		fgets(s.name, BUFF_SIZE, stdin);
		trim(s.name);

		printf("Enter branch : ");
		fgets(s.branch, BUFF_SIZE, stdin);
		trim(s.branch);

		write(fd, (char*)&s, sizeof(struct student));
		printf("\n");
		
	}

	lseek(fd, 0, SEEK_SET);
	printf("Enter rno of student to read : ");
	fgets(buff, BUFF_SIZE, stdin);
	rno = atoi(buff);
	printf("\n");

	for(i=0; i<n; i++) {
		read(fd, (char*)&s, sizeof(struct student));
		if (s.rno == rno) {
			found = 1;
			printf("STUDENT FOUND\n");
			printf("Name : %s\n", s.name);
			printf("Branch : %s\n", s.branch);
			break;
		}
	}
	if (!found) {
		printf("STUDENT NOT FOUND\n");
	}

	close(fd);
	return 0;
}
