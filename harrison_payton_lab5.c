#include <stdio.h>

/* Payton Harrison
 * Lab 5, CSCI 112
 * 10/24/18
*/

//helper method to "sort" that actually swaps two components in array
int swap(char *a, char *b){
	
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;	

	//exit without errors
	return(0);
}

//method to sort the characters in alphabetical order
//implements selection sort
int SelectionSort(char letters[], int size){

	//set enum values to each character

	//print statement
	printf("Sorted array:\n");

	//Sort algorithm
	int i, j;

	for(i = 0; i < size; i++){
		for(j = i + 1; j < size; j++){
			//if the next element is "greater" than the previous one, swap
			if(letters[i] < letters[j]){
				//call to helper method
				swap(&letters[i], &letters[j]);
			}
		}
	//print statement to see output array on screen
	printf("%c ",letters[i]);
	}
	printf("\n");
		
	//exit without errors
	return(0);
}

//main method that reads in from the input file, stores values in array, 
//and calls submethods
int main(void){

	//define array
	char letters[100];	//arbitrary size value
	int i = 0;
	int size;

	//for loop to populate array with text file characters
	for(i = 0; i < 100; i++){
		scanf(" %c\n",&letters[i]);
		
		//if value is not sentinel, add to size count
		if(letters[i] != '0'){

			//keeps track of actual size of array to pass to sort method
			size++;
		}	
		//if value IS sentinel, exit loop
		else if(letters[i] == '0'){
			break;
		}
	}

	//call submethod
	SelectionSort(letters, size);

	//exit without errors
	return(0);
}

