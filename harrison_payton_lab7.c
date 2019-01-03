#include <stdio.h>
#include <string.h>	//string library

/* Payton Harrison
 * Lab 7, CSCI 112
 * 11/7/18
*/

//method to get input from the user
int getInput(void){
	
	//Instructions to user about what to input
	printf("\n");
	printf("Please enter a word to check whether or not it is a palindrome.\n");
	printf("Enter the word 'stop' to stop the program.\n");
	printf("\n");

	char inputWord[100];	//arbitrary string size
	//flag for while loop condition
	int stop = 0;

	//while loop to keep collecting words until "STOP" "stop" or "Stop" is entered
	while(stop != 1){
	
		//print statement for context
		printf("Word: ");

		//scan for string, save to char array
		scanf("%s",&inputWord);

		//check to see if stop is entered, capital or lowercase
		if(strcmp(inputWord, "STOP") == 0 ||	//if value is 0, that means s1 and s2 are equal
		   strcmp(inputWord, "stop") == 0 ||
		   strcmp(inputWord, "Stop") == 0){
			
			//if stop is entered, set flag to "1" so that loop stops collecting words
			stop = 1;			
		}
		//if word is not stop, call subfunction
		else{
			//call subfunction
			int n = strlen(inputWord);
			checkPalindrome(inputWord, 0, (n-1));	//word and index start/end number
		}
	}
	//exit  without errors
	return(0);
}

//method to check if string is a palindrome
int checkPalindrome(char inputWord[], int start, int end){

	//base case: if there is only one character or 2 characters left (odd or even word)
	if(start == end || (start + 1) == end){
		printf("      %s IS a palindrome.\n",inputWord);
	}

	//if the first and last characters do not match
	else if(inputWord[start] != inputWord[end]){
		printf("      %s is NOT a palindrome.\n",inputWord);
	}

	//if there are more than 2 characters, check if middle substring is also palindrome or not
	else if(start < end){
		//recusrive call
		checkPalindrome(inputWord, (start + 1), (end - 1));
	}

	//exit without errors
	return(0);
}

//main method to call submethods
int main(void){

	//call subfunction
	getInput();

	//exit without errors
	return(0);
}
