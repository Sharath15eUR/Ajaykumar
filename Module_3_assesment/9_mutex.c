// 9. Write a C program to demonstrate the use of Mutexes in threads synchronization 

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h> 

// Variable to keep track of the jobs processed
int counter; 
// Mutex lock to ensure mutual exclusion while accessing shared resources
pthread_mutex_t lock; 

// Function executed by each thread
void* fun(void* arg) {
	pthread_mutex_lock(&lock);  // Lock the mutex to ensure mutual exclusion
	counter++; 
	printf("\n Job %d started\n", counter); 
	sleep(1);
	printf("\n Job %d finished\n", counter);
	pthread_mutex_unlock(&lock);  // Unlock the mutex
	return NULL; 
} 

int main(void) {
    // Declare thread ID's
    pthread_t t1, t2;

    // Initialize mutex lock
	if (pthread_mutex_init(&lock, NULL) != 0) { 
		printf("\n mutex init has failed\n"); 
		return 1; 
	} 

    // Create first thread
    if (pthread_create(&t1, NULL, &fun, NULL)) {
        printf("Error creating thread\n");
		return 1;
    }

    // Create second thread
    if (pthread_create(&t2, NULL, &fun, NULL)) {
        printf("Error creating thread\n");
		return 1;
    }

    // Wait for first thread to finish
	if (pthread_join(t1, NULL)) {
        printf("Error joining\n");
		return 1;
    } 

    // Wait for second thread to finish
	if (pthread_join(t2, NULL)) {
        printf("Error joining\n");
		return 1;
    }

    // Destroy the mutex lock
	pthread_mutex_destroy(&lock); 
	return 0; 
} 
