#include <pthread.h> 
#include <stdio.h> 
void * thread1(void * ptr);
void * thread2(void * ptr);

int main(){
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("Hello from the main thread\n");


}


void * thread1(void * ptr) {
	//pthread_detach(pthread_self());
	sleep(5);
	printf("Hello from thread 1\n");
 	pthread_exit(NULL);	
}

void * thread2(void * ptr) {
	//pthread_detach(pthread_self());
	sleep(5);
	printf("Hello from thread 2\n");
 	pthread_exit(NULL);
}
