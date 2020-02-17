#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t idAdd;

void* add(void *arg) {
	int a, b;
	printf("Enter two numbers : ");
	scanf("%d %d", &a, &b);
	printf("Sum = %d\n", a+b);
}

int main() {
	int i=0, err;
	err = pthread_create(&idAdd, NULL, &add, NULL);
	if (err != 0) {
		printf("Cant create thread : [%s]\n", strerror(err));
	} else {
		printf("Thread created successfully\n");
	}
	err = pthread_join(idAdd, NULL);
	if (err != 0) {
		printf("Cant joining thread : [%s]\n", strerror(err));
	} else {
		printf("Thread finished successfully\n");
	}
	return 0;
}
