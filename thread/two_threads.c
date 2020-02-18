#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t idAdd[2];
int a, b, c, d;

void* add(void *arg) {
	pthread_t idSelf = pthread_self();
	if (pthread_equal(idSelf, idAdd[0])) {
		printf("[Thread1] :: Sum = %d\n", a+b);
	} else if (pthread_equal(idSelf, idAdd[1])) {
		printf("[Thread2] :: Sum = %d\n", c+d);
	}
}

int main() {
	int i=0, err;
	
	printf("Enter two numbers for Thread 1\n");
	scanf("%d %d", &a, &b);

	printf("Enter two numbers for Thread 1\n");
	scanf("%d %d", &c, &d);

	err = pthread_create(&idAdd[0], NULL, &add, NULL);
	if (err != 0) {
		printf("Cant create thread 1 : [%s]\n", strerror(err));
	} else {
		printf("Thread 1 created successfully\n");
	}

	err = pthread_create(&idAdd[1], NULL, &add, NULL);
	if (err != 0) {
		printf("Cant create thread 2 : [%s]\n", strerror(err));
	} else {
		printf("Thread 2 created successfully\n");
	}

	err = pthread_join(idAdd[0], NULL);
	if (err != 0) {
		printf("Cant join thread 1 : [%s]\n", strerror(err));
	} else {
		printf("Thread 1 finished successfully\n");
	}
	err = pthread_join(idAdd[1], NULL);
	if (err != 0) {
		printf("Cant join thread 2 : [%s]\n", strerror(err));
	} else {
		printf("Thread 2 finished successfully\n");
	}
	return 0;
}
