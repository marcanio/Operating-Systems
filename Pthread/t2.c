/* t2.c
   synchronize threads through mutex and conditional variable 
   To compile use: gcc -o t2 t2.c -lpthread 
*/ 

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* hello();    // define two routines called by threads    
void* world();         	
void* again(); 	//Define again
/* global variable shared by threads */
pthread_mutex_t mutex;  		// mutex
pthread_cond_t done_hello; 	// conditional variable

int done = 0;      	// testing variable

pthread_cond_t done_world; //conditional for world to be done 
int done2 =0;		//varible to wait for world

int main (){
    pthread_t tid_hello, tid_world, tid_again; // thread id
	
    /*  initialize mutex and cond variable  */ 
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&done_hello, NULL); 

    pthread_cond_init(&done_world, NULL);// Cond varible for world to be done
    
    pthread_create(&tid_hello, NULL, hello, NULL); //thread creation
    pthread_create(&tid_world, NULL, world, NULL); //thread creation 
    pthread_create(&tid_again, NULL, again, NULL); //thread creation 

    /* main waits for the two threads to finish */
    pthread_join(tid_hello, NULL);  
    pthread_join(tid_world, NULL);
    pthread_join(tid_again, NULL);

    printf("\n");
    return 0;
}


void* hello() {
    pthread_mutex_lock(&mutex);
    printf("hello ");
    fflush(stdout); 	// flush buffer to allow instant print out
    done = 1;
    pthread_cond_signal(&done_hello);	// signal world() thread
    pthread_mutex_unlock(&mutex);	// unlocks mutex to allow world to print
}


void* world() {

    pthread_mutex_lock(&mutex);

    /* world thread waits until done == 1. */
    while(done == 0) 
		pthread_cond_wait(&done_hello, &mutex);

    printf("world ");
    fflush(stdout);

    done2 = 1;
    pthread_cond_signal(&done_world);
    pthread_mutex_unlock(&mutex); // unlocks mutex
}

void* again() {
	
	pthread_mutex_lock(&mutex);

/* again thread waits until done2== 1. */
	while(done2 == 0) 
		pthread_cond_wait(&done_world,&mutex);

	printf("Again!"); //Print  out again
	fflush(stdout); 

	pthread_mutex_unlock(&mutex); // unlocks mutex
}
