#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
void my_routine( );

int main( ) {
	
	signal(SIGFPE, my_routine);
	int a = 4;
	a = a/0;
	
	printf("Can’t get here\n");
}


void my_routine( ) {
	printf("Caught a SIGFPE\n");
	exit(0);
}
