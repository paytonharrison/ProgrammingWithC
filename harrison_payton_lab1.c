#include <stdio.h>   //printf, scanf definitions

/*Payton Harrison
 * Lab 1, CSCI 112
 * 9/5/18
 */

//This program converts a number from feet to miles
#define FEET_PER_MILE 5280  //conversion constant

//main method to collect user input, convert it, and return new value
int main(int argc, char** argv){
	//variables
	int feet; //distance in feet
	double miles; //equivalent distance in miles

	//get the distance in feet
	printf("Hello, please enter a distance value in feet: ");
	scanf("%d", &feet);

	//convert the distance to miles
	miles = (double)feet / FEET_PER_MILE;

	//display the distance in kilometers
	printf("%d feet equals %.2lf miles.\n", feet, miles);	
	//.2 before the lf allows 2 decimal places to be printed
	
	//exit with no errors
	return(0);	
}

