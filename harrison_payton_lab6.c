#include <stdio.h>
#include <string.h>	//string library

/* Payton Harrison
 * Lab 6, CSCI 112
 * 10/31/18
*/


//method to get input from user
int getInput(void){
	
	//instructions to user about what to input
	printf("\n");
	printf("Please enter a noun in its singular form to find out what its plural is.\n");
	printf("Enter the word 'stop' to stop the program\n");
	printf("\n");

	char inputWord[100];	//arbitrary string size
	//flag for while loop condition
	int stop = 0;

	//while loop to keep collecting words until "STOP" "stop" or "Stop" is entered	
	while(stop != 1){

		//print statement for context	
		printf("Word:   ");

		//scan for string, save to char array
		scanf("%s",&inputWord);
	
		//check to see if stop is entered, capital or lowercase
		if(inputWord[0] != 'S' && inputWord[0] != 's' && inputWord[1] != 'T' && inputWord[1] != 't' && inputWord[2] != 'O' && inputWord[2] != 'o' && inputWord[3] != 'P' && inputWord[3] != 'p'){
			//call subfunction
			pluralizeNoun(inputWord);
		}
		//if the word stop is entered, set flag to "1" so that loop stops collecting words
		else{
			stop = 1;
		}	
	}
	//exit without errors
	return(0);
}

//method to alter string to make it plural
int pluralizeNoun(char inputWord[]){

	//variables to save information about the length of the  array
	int length;
	length = strlen(inputWord);
	
	//if word ends in y, subtract y and add ies
	if(inputWord[length - 1]  == 'y'){
		inputWord[length - 1] = 'i';
		inputWord[length] = 'e';
		inputWord[length + 1] = 's';
		//uses zero character to indicate the termination of the string
		//so that longer words that came before it aren't included in this string
		inputWord[length + 2] = '\0';
	}
	//if word ends in s, ch, or sh, add es
	else if(inputWord[length - 1] == 's' || (inputWord[length - 2] == 'c' && inputWord[length - 1] == 'h') || (inputWord[length - 2] == 's' && inputWord[length - 1] == 'h')){
		//strcat appends the string at the end to the string at the beginning
		strcat(inputWord, "es");
	}
	//in all other cases, add s
	else{
		strcat(inputWord, "s");
	}
	//print statement to reveal output
	printf("Plural: %s\n",inputWord);

	//exit without errors
	return(0);
}

//main method that calls submethods
int main(void){
	
	//call subfunction
	getInput();

	//exit without errors
	return(0);
}



