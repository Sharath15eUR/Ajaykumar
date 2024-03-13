#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

// Function for printing 'Hello'
void* helloFunction() {
	printf("Hello ");
	pthread_exit(NULL);
}

// Function for printing 'World'
void* worldFunction() {
	printf("World\n");
	pthread_exit(NULL);
}


int main() {
	// Declaring thread ID's
	pthread_t t1, t2;

	// Create hello thread
	if (pthread_create(&t1, NULL, &helloFunction, NULL)) {
		printf("Error creating hello thread\n");
		return 1;
	}
	// Create world thread
	if (pthread_create(&t2, NULL, &worldFunction, NULL)) {
		printf("Error creating world thread\n");
		return 1;
	}
	// Wait for hello thread to finish
	if (pthread_join(t1, NULL)) {
		printf("Error joining hello thread\n");
		return 1;
	}
	// Wait for world thread to finish
	if (pthread_join(t2, NULL)) {
		printf("Error joining world thread\n");
		return 1;
	}
	return 0;
}
