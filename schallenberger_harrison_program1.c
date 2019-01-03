#include <stdio.h>
#include <math.h> //includes math library, used for a power function

/* Zachary Schallenberger, Payton Harrison
 * Program 1, CSCI 112
 * Description: Program takes in user input for an amount borrowed, annual
 * 	interest rate, and the number of payments and the program prints out
 *	a list of all the payments with the
 * 10/11/18
*/

//method to collect input values from user and call calculate subfunction
void getInput(void){
	
	//instructions to the user about input formatting
	printf("\nPlease provide the following inputs: amount borrowed (principal), annual interest rate, and the number of payments.\n");
	printf("Please provide the amount borrowed and the number of payments as integers - no commas.\n");
	printf("Provide the annual interest rate as a decimal value with a 0 followed by a .\n");
	printf("For example, 2 percent would be 0.02\n");
	printf("\n");

	//variables 
	double principal;
	double numPayments;
	double annualInterest;

	//Scan for user input
	printf("Principal: ");
	scanf("%lf", &principal);

	printf("Annual interest: ");
	scanf("%lf", &annualInterest);

	printf("Term (months): ");
	scanf("%lf", &numPayments);

	//call calculate function with stored user input
	calculate(principal, annualInterest, numPayments);

	//exit without errors	
	return;
}

//method to calculate how much interest and payments are per month
int calculate(double principal, double annualInterest, double numPayments){

	//variables
	double i = ((1.0/12) * annualInterest);	
	double bottomPower = pow((1 + i),(-1.0*numPayments));
	double payment;
	double currPrincipal;
	
	//calculations
	payment = ((i*principal)/(1 - bottomPower));    
	                        
	//print statements to show output
	printf("Payment amount:  $%.2lf\n", payment);                              
  
	//for loop here to calculate the interest and principal remaining  per month
	printf("\nPayment	Interest	Principal	Principal Balance");
	printf("\n_______________________________________________________________");
	int j;
	for(j = 1; j <= numPayments; j++){
		annualInterest = i * principal;
	
		currPrincipal = payment - annualInterest;
		principal = principal - currPrincipal;
		printf("\n%d	%.2lf		 %.2lf		 %.2lf", j, annualInterest, currPrincipal, principal);   	
		//if the last month's payment is being calculated, print the final payment as well
		if(j == numPayments){
			printf("\n");
			printf("\nFinal payment: $%.2lf", (annualInterest + currPrincipal));
			printf("\n");
		}
	}

	//exit without errors
	return(0);
}

//main method that calls submethods
int main(void){

	getInput();

	//exit without errors
	return(0);
}
