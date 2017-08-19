// Twin Prime Conjecture.c : Defines the entry point for the console application.
//
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>

void calculate(int num);

void main(){
	int number = 1;
	time_t start_t, end_t;

	printf("Enter how many pairs you need: ");
	scanf_s("%d", &number); //scan in the numbers 

	time(&start_t); //start
	calculate(number); //send it
	time(&end_t);//end

	printf("Execution time: %f\n", difftime(end_t, start_t)); //show time
	system("pause");//pause
}
void calculate(int num){
	int lastPrime = 1, twinPrimeCount = 0;

	for(int counter = 1; counter <= INT_MAX; counter++){ //loop until it's no longer possible

		int count = 0;//store number of perfect divisions
		for(int i=1;i<=counter;i++){ //loop until current number
			if(counter%i==0){ //if it divides perfectly
				count++;
			}		
		}

		if(count==2){//if it only divisible twice (1 and N)
			printf("Prime found: %d\n", counter);
			
			if(counter - lastPrime == 2){
				twinPrimeCount++;//increment twin prime count
				printf("Twin prime found: %d and %d, found: %d\n", lastPrime, counter, twinPrimeCount);		
			}	
			lastPrime = counter;
		}	

		if(twinPrimeCount == num){ //if all have been found
			break;
		}
	}
}