#include <stdio.h>

/* Payton Harrison
 * Lab 2, CSCI 112
 * 9/17/18
 */

//function declaration
int getInput(void);
int calculate(int houseCost, int annualFuelCost, double taxRate);

//main method to call submethods
int main(void){
	
	//call submethod
	getInput();

	//exit with no errors
	return(0);
}

//method to get numerical values from the user regarding the house
int getInput(void){
	
	//instructions to the user about input formatting
	printf("\n");
        printf("Please provide the following inputs: house cost, annual fuel cost, and tax rate.\n");
        printf("Provide house cost and fuel costs as an integer - no commas.\n");
        printf("Provide tax rate as a decimal value with 0 followed by a .\n");
        printf("Example - 2 and a half percent - 0.025\n");
        printf("\n");

	//variables
	int houseCost;
	int annualFuelCost;
	double taxRate;

	//Ask for the user input for each variable
	printf("House cost: ");
	scanf("%d", &houseCost);

	printf("Annual fuel cost: ");
	scanf("%d", &annualFuelCost);

	printf("Tax rate: ");
	scanf("%lf", &taxRate);
	
	//call calculate function with stored user input
	calculate(houseCost, annualFuelCost, taxRate);

	return(0);
}	

//method to use values from user and calculate total house cost after 5 years
int calculate(int houseCost, int annualFuelCost, double taxRate){


	//calculations
	taxRate = houseCost*taxRate;
	houseCost = (houseCost + (annualFuelCost * 5)) + (taxRate * 5);	

	//print statements to show output
	printf("\n");
	printf("The house cost after 5 years is : $%d.00 \n", houseCost);
	printf("\n");

	return(0);
}

