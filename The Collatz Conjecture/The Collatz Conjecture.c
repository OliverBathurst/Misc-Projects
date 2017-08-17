// The Collatz Conjecture.c : Defines the entry point for the console application.
//
#include <stdio.h>
#include <conio.h>

int compute(int n);
int number = 0, steps = 0; //declare two vars, the number being used and no. of steps

void main(){
	printf("Enter your number: ");
	while(number < 1){ //loop while the inputted is above 1
		scanf_s("%d", &number); //scan it
	}
	printf("TOTAL NUMBER OF STEPS: %d", compute(number)); //display
	getch(); //pause
}
int compute(int n){
	if(n!=1){ //if it hasn't finished
		if(n % 2 == 0){ //if even
			n = n / 2;	//divide number by two	
		}else{
			n = ((3*n) + 1); // n= 3n+1 as an odd is present
		}
		printf("Number: %d, Step count: %d\n", n, steps++); //update the user, increment steps
		compute(n); //recur
	}//if n==1, function finishes and control goes back to main
	return steps;
}
