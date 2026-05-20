/*j0ey-code
C Programming [Fundamentals]
Build-a-Burger Game Project
November 2023*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define FALSE 0
#define TRUE 1

int PlayRound();
int RandomDecider();
int GenerateRandomBurger(int ticket[]);
int BuildBurger(int size, int ticket[]);
void InitArray(int size, int val, int arr[]);
void PrintBurger(int size, int arr[]); 
void ClearScreen();
int CompareBurgers(int size, int ticket[], int burger[]);
int CalculateTotals(int size, int arr[], int isCorrect);
int RoundUp(double yz);

//Loop to Run Game and Continue Playing Rounds until User Decides to Quit
int main() {
	srand(time(0));

	char exitCond[16] = {'S','a','m','p','l','e','C','h','a','r','A','r','r','a','y','\0'};
	char loopCtrl[16] = {'S','a','m','p','l','e','C','h','a','r','A','r','r','a','y','\0'};
	char exitCondKey;
	char loopCtrlKey;
	int finalScore;

	do {
		finalScore = finalScore + PlayRound();
		sleep(5);
		printf("Would you like to play another round / keep cookin'?\nEnter response (Yes/No) || [Y/N]?: ");
		scanf("%s", loopCtrl);
		fflush(stdout);
		loopCtrlKey = loopCtrl[0];
		loopCtrlKey = toupper(loopCtrlKey);
		if (loopCtrlKey != 'Y') {
			printf("\nAre you sure you'd like to quit?\nEnter response (Yes/No) || [Y/N]?: ");
			scanf("%s", exitCond);
			fflush(stdout);
			exitCondKey = exitCond[0];
			exitCondKey = toupper(exitCondKey);

		}
	} while (loopCtrlKey == 'Y' || exitCondKey != 'Y');

	printf("\nYour final, frycookin' score is: %i!!\n", finalScore);

	return finalScore;

}

//Starts a Round of the Game and Saves / Returns the Score for that Single Round / Order
int PlayRound() {
	int order[11];
	InitArray(11, -1, order);
	
	int count = GenerateRandomBurger(order);
	
	PrintBurger(count, order);
	
	printf("\nMemorize the order frycook!!\n");
	fflush(stdout);
	
	ClearScreen();

	int burgah[count];

	BuildBurger(count, burgah);

	puts("Customer's Order");
	PrintBurger(count, order);
	puts(" ");
	puts("User's Burger"); 
	PrintBurger(count, burgah); 

	int test = CompareBurgers(count, order, burgah);
	//printf("Testing... %i \n", test);

	if (test == 0) {
		printf("\nBurger does not match customer's order!\nCost / points brought down to $2 flat rate!\n\n");

	} else {
		printf("\nBurger matches customer's order!! Good job!\nCost / points rounded up to nearest whole number for tip!\n\n");

	}

	puts("Calculating points for round...");
	sleep(5);

	int score = CalculateTotals(count, burgah, test);
	printf("\nRound Score: %i\n\n", score);

	return score;

}

//Random Number Generator for Binary / Boolean Condition Value (0 or 1)
int RandomDecider() {
	return rand() % 2;

}

//Initializes / Fills Burger Arrays with Meaningless, Foobar Placeholder Values before Actual Ingredients Generated or Inputted
void InitArray(int size, int val, int arr[]) {
	int i;
	for (i = 0; i < size; i++) {
		arr[i] = val;

	}

}

//Generates Order
int GenerateRandomBurger(int arr[]) {
	int h;
	int counter = 0;
	for (h = 0; h < 11; h++) {
		if (RandomDecider() == 1) {
			arr[counter] = h;
			counter++;

		} 

	}
	return counter;	

}

//Initialize User's Burger Array and Read-in User Input One Line at a Time
int BuildBurger(int size, int ticket[]) {
	int j;
	InitArray(size, -1, ticket);
	//printf("%i \n\n", size);
	printf("Enter the ingredient numbers one at a time, each on a separate line \nfollowed by the Return / Enter key, as you remember them... \n");
	fflush(stdout);
	for (j = 0; j < size; j++) {
		scanf("%i%*c", &ticket[j]);
		puts(" ");
		fflush(stdout);

	}
	return size;

}

//Function to Handle Printing Burger Arrays, whether Order or Final Product
void PrintBurger(int size, int arr[]) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%i ", arr[i]);

	}
	puts(" ");

}

//sleep() Functions Added for Character; Allows User Time to Memorize Order (10 Secs Total) before Screen Clear
void ClearScreen() {
	sleep(3);
	puts("...");
	sleep(3);
	puts("...");
	sleep(3);
	puts("...");
	sleep(1);
	int i;
	for (i = 0; i < 50; i++) {
		puts(" ");
		fflush(stdout);

	}

}

int CompareBurgers(int size, int ticket[], int burger[]) {
	int x;
	for (x = 0; x < size; x++) {
		if (ticket[x] != burger[x]) {
			return 0;

		} 
	} 
	return 1;

}

//Switch Statement Usage to Tally Ingredient Costs / Points
//Point Modifiers for Special Burger Conditions Below Switch Cases
int CalculateTotals(int size, int arr[], int isCorrect) {
	double pts = 6.99;
	int x;
	for (x = 0; x < size; x++) {
		switch (arr[x]) {

		case 0: 
			break;

		case 1:
		case 2:
		case 3:
			pts = pts + 0.39;
			break;

		case 4: 
		case 5: 
		case 6: 
		case 7:
			pts = pts + 0.69;
			break;

		case 8:
			pts = pts + 1.29;

		case 9:
		case 10:
			break;

		default:
			break;

		}
	}

//Mascot Special Condition
	if (size == 11) {
		pts = pts + 2;
		printf("\nBrave Knight Burger special comin' up!\nTwo dollars extra added for Mascot Special condition.\n");

	}

//Veggie Special Condition
	int v;
	int veg = 1;
	for (v = 0; v < size; v++) {
		if (size < 3 || arr[v] == 9) {
			veg = 0;

		} 

	}
	if (veg == 1) {
		pts = pts - 2;
		printf("\nTriple L Burger (Lawrence's Leeks and Lettuce) special comin' up!\nTwo dollars subtracted for Veggie Special condition.\n");
		
	}

//Gluten-Free Special Condition
	int b;
	int gf = 1;
	for (b = 0; b < size; b++) {
		if (arr[b] == 0 || arr[b] == 10) {
			gf = 0;

		} 

	}
	if (gf == 1) {
		pts = pts - 1;
		printf("\nThe Lazy Bureaucrat Burger special comin' up!\nOne dollar substracted for Gluten-Free Special condition.\n");
		
	}

	int ptsFin;

	if (isCorrect == 1) {
		ptsFin = RoundUp(pts);

	} else {
		ptsFin = 2;

	}
	return ptsFin;

}


//Custom Written Function for Rounding Up; ceil() from math.h refused to work with compiler for some reason??
int RoundUp(double yz) {
	int wholeNum = yz + 1;
	return wholeNum;

}



