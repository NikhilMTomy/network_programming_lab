#include <stdio.h>
#include <unistd.h>

int main() {
	int pid, i, n;
	printf("Enter limit : ");
	scanf("%d", &n);
	pid = fork();
	if (pid == 0) {
		for (i=0; i<n; i++) {
			if (i%2 == 1) {
				printf("[PARENT] :: %d\n", i);
			}
		}
	}
	else {
		printf("PARENT PID : %d\n", getppid());
		printf("CHILD PID : %d\n", getpid());
		for (i=0; i<n; i++) {
			if (i%2 == 0) {
				printf("[CHILD] :: %d\n", i);
			}
		}
	}
}
