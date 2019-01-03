#include <stdio.h>
#include <math.h>	//access Math Library

/* Payton Harrison
 * Lab 3, CSCI 112
 * 9/26/18
*/

//method to do all calculations to the passed in array
int calculate(int arr[], int n){

	//variables that will be printed in program
	int min, max, range;
	double avg, stanDev;
	
	//variables for calculation for loop
	int sum = 0;
	max = arr[0];
	min = arr[0];
	int sum_squares = 0;

	//for loop that calculates average, max, min, and standard deviation
	int i;
	for(i = 0; i < n; i++){
		//calculate average
		sum = sum + arr[i];

		//calculate standard deviation
		sum_squares = sum_squares + (arr[i] * arr[i]);
	
		//update maximum value in array
		if(arr[i] > max){	
			max = arr[i];
		}
	
		//update minimun value in array
		if(arr[i] < min){
			min = arr[i];
		}
		
	}
	//finish calculating average here
	avg = (double)sum / n;
	
	//use sqrt() function here to finish calculating stanDev
	stanDev = sqrt((((double)(sum_squares)) /n) - (avg*avg));

	//calculate the range
	range = max - min;

	//print statements
	printf("\n");
	printf("The smallest number in the set of numbers is: %d\n", min);
	printf("The largest number in the set of numbers is: %d\n", max);
	printf("The average of the numbers is: %.2lf\n", avg);
	printf("The range of the numbers is: %d\n", range);
	printf("The standard deviation of the numbers is: %.2lf\n", stanDev);
	printf("\n");

	//exit without errors
	return(0);
}



//main method that reads in the array from the text file and calls submethod
int main(void){
	
	//scan in first int from text file: this is the size of the array
	int n;
	scanf("%d\n",&n);

	//define array
	int arr[n]; 
	int i = 0;
	//for loop to populate array with text file integers
	for(i = 0; i < n; i ++){
		scanf("%d\n",&arr[i]);
	} 			

	//call submethod
	calculate(arr,n);
	
	//exit without errors
	return(0);
}
