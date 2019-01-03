#include <stdio.h>
#include <math.h>	//for absolute value function
/*Payton Harrison
 * Lab 4, CSCI 112
 * 10/17/18
*/

//method to scan parameters and store as x and y arrays, and array max size
//fills array with data from the file
int get_corners(int n){

	//set size of arrays
	double arrX[n];
	double arrY[n];

	//for loop to populate array with text file integers
	int i= 0;
	for(i = 0; i < n; i++){
		scanf("%lf %lf\n", &arrX[i], &arrY[i]);
	}
	printf("\n");

	//call output corners function to print (x,y) coordinates as two columns
	output_corners(arrX, arrY, n);
	
	//call caculate poygon area function, passing in arrays and sizes
	polygon_area(arrX, arrY, n);

	//exit without errors
	return(0);
}

//outputs to the file the two double arrays' contents
int output_corners(double arrX[], double arrY[], int n){
	
	//print statements for the output file that build the (x,y) table
	printf("\n");
	printf("Table of (X,Y) coordinates for the polygon:\n");
	printf("\n");
	printf("X\tY\n");
	printf("------------\n");

	//for loop to print contents of arrays as coordinates
	int i;
	for(i = 0; i < n; i++){

		//checks to see if input file has reached an empty line, prints contents until that is true
		if((int)arrX[i] != 0){
			printf("\n%.2lf\t%.2lf\n", arrX[i], arrY[i]);
		}
	}

	//exit without errors
	return(0);
}

//takes in both arrays and returns the area of the polygon
int polygon_area(double arrX[], double arrY[], int n){

	double area = 0;
	int i;
	for(i = 0; i < (n - 2); i++){
		double xVal = (arrX[i+1] + arrX[i]);
		double yVal = (arrY[i+1] - arrY[i]);

		area = area + (xVal * yVal);
	}
	//take absolute value of half of the current "area" value
	area = fabs((0.5 * area));
	printf("\nThe area of this polygon is %.2lf square units.\n", area);

	//exit without errors
	return(0);
}

//main method that calls submethods
int main(void){

	//call subfunction
	//sending in 20 as the size of the arrays
	get_corners(20);

	//exit without errors
	return(0);
}
