// FINAL PROJECT 
/* Name      : Kevin Kurnia Santosa
   ID        : 2001585253
   Major     : Computer Science
   Program   : Quick Count Game */

#include <iostream>  
#include <ctime>   // Given time for user to input
#include <cstdlib> // For seed rand (Generate random number)
#include <iomanip> // Setw
#include <string>
#include <fstream>
#include <conio.h> // kbhit
#include <windows.h>

using namespace std;

// Declare functions
int practice(); 
int questionPractice(int, int, int, int, string, int);
void displayPoints(int);
int endOptionsPractice();
int play();
int playLevel1(int, int, int, int);
int playLevel2(int, int, int, int, int, int);
int playLevel3(int, int, int, int, int, int);
int questionPlay(int, int, int ,int , string[], int);
void timer(int);
void displayHighscore(int);
int endOptionsPlay();
void count();


int main () { 			// Start main function
	
	int inputOptions;
	string userName;
	
	cout << "\n\t\tQUICK COUNT GAME";  // Title of the Program
	cout << "\n\n\n\tWelcome !\n\tEnter your name : ";  
	getline (cin, userName);   // Store username
	
	system ("CLS");
	cout << "\n\t\tQUICK COUNT GAME" << "\n\n\t"; 
	for (int line = 1; line <= 33; line++) {
	cout << "=";
	}
	cout << endl << endl << "  Hello " << userName << "!!";
	cout << endl << endl << "\t1. Play" ;
	cout << endl << "\t2. Practice";
	cout << endl << "\t3. Exit";
	cout << endl << endl << "\tPlease enter your choices (1, 2, 3) : ";
	cin >> inputOptions;
	
	switch (inputOptions)
	{
		case 1 :
		play ();
		break;
		case 2 :
		practice ();
		break;
		case 3 :
		return 0;
		default :
		cout << endl << "\tYou enter the wrong option.\n\n" << "\t";
		system("PAUSE");
		main();
	}
	getchar ();
	return 0;
}

int practice () {	
	char optionPractice;
	unsigned s = time(0);
	srand(s);
	int formula;
	string symbol;
	int point = 0;
	
	cout << endl << endl << "   a. Addition";
	cout << endl << "   b. Subtraction";
	cout << endl << "   c. Multiplication";
	cout << endl << "   d. Exit the program";
	cout << endl << endl << "  Which operations do you want to choose ? ";
	cin >> optionPractice;
	
	if (optionPractice == 'a' || optionPractice == 'A'){ 
		system ("CLS");
		for (int number = 1; number <= 10; number++) {
			int n1 = (rand()%(50-10+1))+10;
			int n2 = (rand()%(50-10+1))+10;
			formula = n1 + n2;
			symbol = "   ____+";
			point = questionPractice (number, formula, n1, n2, symbol, point);
		}
		displayPoints(point);
		endOptionsPractice ();
	}
	
	else if (optionPractice == 'b' || optionPractice == 'B') {
		system ("CLS");
		for (int number = 1; number <= 10; number++) {
			int n1 = (rand()%(100-60+1))+60;
			int n2 = (rand()%(60-10+1))+10;
			formula = n1 - n2;
			symbol = "   ____-";
			point = questionPractice (number, formula, n1, n2, symbol, point);
		}
		displayPoints(point);
		endOptionsPractice ();
	}
	
	else if (optionPractice == 'c' || optionPractice == 'C') {
		system ("CLS");
		for (int number = 1; number <= 10; number++) {
			int n1 = (rand()%(12-1+1))+1;
			int n2 = (rand()%(10-1+1))+1;
			formula = n1 * n2;
			symbol = "   ____x";
			point = questionPractice (number, formula, n1, n2, symbol, point);
		}
		displayPoints(point);
		endOptionsPractice ();
	}
	
	else if (optionPractice == 'd' || optionPractice == 'D'){
		return 0;
	}
	
	else {
		cout << endl << " You choose the wrong option.\n\n" << " ";
		system("PAUSE");
		system("CLS");
		practice();
	}
}

int questionPractice (int number, int answer, int n1, int n2, string symbol, int points) {
	int input;
	
		cout << endl << setw(2) << number << ".";
		cout << " " << n1 << endl;
		cout << "    " << n2 << endl;
		cout << symbol << endl << "    ";
		cin >> input;
		
		if (input != answer) {
			points = points + 0;
			cout << endl << " WRONG!! Right answer : " << answer << endl;
		}
		else if (input = answer) {
			points = points + 10;
			cout << endl << " RIGHT!!" << endl;
		}
		
	return points;
}

int endOptionsPractice () {
	string yesno;
	int backMenu;
	
	cout << endl;
	cout << endl << "  Try again ? \n  Yes/No ? ";
	cin >> yesno;
	if (yesno == "Yes" || yesno == "yes" || yesno == "y"){
		system ("CLS");
		practice ();
	}
	else if (yesno == "No" || yesno == "no" || yesno == "n"){
		system("CLS");
		cout << endl << "  1. Back to menu.";
		cout << endl << "  2. Exit the program.";
		cout << endl << "  Choose 1 or 2 : ";
		cin >> backMenu;
		if (backMenu == 1){
			main();
		}
		else if (backMenu == 2){
			return 0;
		}
		else {
			cout << "\n  Wrong option.";
			return 0;
		}
	}
	else {
		cout << endl << " You choose the wrong option.";
		return 0;
	}
}

void displayPoints (int practiceScore) {
	cout << endl << " Score : " << practiceScore;
	
	if (practiceScore == 100){
		cout << endl << " Excellent!! You got perfect score!!";
	}
	else if (practiceScore >= 60 && practiceScore <= 100){
		cout << endl << " Good work!!";
	}
	else {
		cout << endl << " You need more practice.";
	}
}

int play() {
	unsigned s = time(0);
	srand(s);
	int score = 0;
	
	system ("CLS");
	count();
	
	for (int no = 1; no <= 10; no++) {
		// First level : there are 1 operations with 2 possible signs (addition and subtraction) and 2 random numbers
		int operation = (rand()%(2-1+1))+1;		// Generate random number between 1 and 2
		int n1 = (rand()%(10-1+1))+1;			// Generate random number between 1 and 10
		int n2 = (rand()%(10-1+1))+1;			// Generate random number between 1 and 10
		playLevel1(n1, n2, operation, score);   // Go to function questionPlay1 (First level)
		score = score + 10;
	}
	 
	cout << endl << "\tCongratulations reaching the first level!" << endl << endl << "\t";
	system ("PAUSE");
	system ("CLS");
	 
	for (int no = 1; no <= 10; no++) {
		// Second level : there are 2 operations with 2 possible signs (addition and subtraction) and 3 random numbers
		int operation1 = (rand()%(2-1+1))+1;				 	// Generate random number between 1 and 2
		int operation2 = (rand()%(2-1+1))+1;	 			 	// Generate random number between 1 and 2
		int n1 = (rand()%(10-1+1))+1;			 				// Generate random number between 1 and 10
		int n2 = (rand()%(10-1+1))+1;			 				// Generate random number between 1 and 10
		int n3 = (rand()%(10-1+1))+1;			 				// Generate random number between 1 and 10
		playLevel2(n1, n2, n3, operation1, operation2, score); 	// Go to function questionPlay2 (Second level)
		score = score + 10;
	}
	
	cout << endl << "\tCongratulations reaching the second level!" << endl << endl << "\t";
	system ("PAUSE");
	system ("CLS");
	
	for (int no = 1; no <= 500; no++) {
		// Third Level : there are 2 operations with 3 possible signs(addition, subtraction, and multiplication) and 3 random numbers 	
		int operation1 = (rand()%(2-1+1))+1;					// Generate random number between 1 and 2
		int operation2 = (rand()%(2-1+1))+1;					// Generate random number between 1 and 2
		int n1 = (rand()%(10-1+1))+1;							// Generate random number between 1 and 10
		int n2 = (rand()%(10-1+1))+1;							// Generate random number between 1 and 10
		int n3 = (rand()%(10-1+1))+1;							// Generate random number between 1 and 10
		playLevel3(n1, n2, n3, operation1, operation2, score);			// Go to function questionPlay3 (Third level)
		score = score + 10;
	}
	
}

// function to do the math
int playLevel1(int num1, int num2, int operations, int scores)
{
    int formula;
    int answer;
  	string sign;
  
 	if (operations == 1) {
 		formula = num1 + num2;
 		sign = " + ";
	}
 	else if (operations == 2) {
 		formula = num1 - num2;
 		sign = " - ";
 	}
 
   	cout << endl << "\tTimer : 3 sec" << endl;
    cout << "\t" << num1 << sign << num2 << " = ";
    timer(scores);
    cin >> answer; 
    system ("CLS");
  
  	if (answer != formula) {
   		cout << endl << "\tTimer : 3 sec" << endl;
   		cout << "\tTry Again!" << endl;
   		cout << "\t" << num1 << sign << num2 << " = ";
   		timer(scores);
   		cin >> answer;
   		system ("CLS");
    		if (answer != formula) {
    			cout << endl << "\tTimer : 3 sec" << endl;
    			cout << "\tTry Again!" << endl;
    			cout << "\t" << num1 << sign << num2 << " = ";
    			timer(scores);
    			cin >> answer;
    			system("CLS");
     				if (answer != formula) {
      					cout << endl << "\tGAME OVER!!\n  You have wrong 3 times!\n\n\t";
      					cout << "Score : " << scores << endl << endl;
      					Sleep(2000);
      					system("PAUSE");
      					endOptionsPlay(); 
     					exit(0);  
 	}}}
 
 	return 0;
}

int playLevel2(int num1, int num2, int num3, int operations1, int operations2, int score)
{
	int formula;
   	string sign[2];
	
	if (operations1 == 1 && operations2 == 1) {
		formula = num1 + num2 + num3;
		sign[0] = " + ";
		sign[1] = " + ";
	}

	else if (operations1 == 1 && operations2 == 2) {
		formula = num1 + num2 - num3;
		sign[0] = " + ";
		sign[1] = " - ";
	}
	
	else if (operations1 == 2 && operations2 == 1) {
		formula = num1 - num2 + num3;
		sign[0] = " - ";
		sign[1] = " + ";
	}
	
	else if (operations1 == 2 && operations2 == 2) {
		formula = num1 - num2 - num3;
		sign[0] = " - ";
		sign[1] = " - ";
	}
	
	questionPlay(num1, num2, num3, formula, sign, score);
	
   	return 0;
}

int playLevel3(int num1, int num2, int num3, int operations1, int operations2, int score) 
{
	int formula;
   	string sign[2];
	
	if (operations1 == 1 && operations2 == 1) {
		formula = num1 + num2 * num3;
		sign[0] = " + ";
		sign[1] = " x ";
	}

	else if (operations1 == 1 && operations2 == 2) {
		formula = num1 - num2 * num3;
		sign[0] = " - ";
		sign[1] = " x ";
	}
	
	else if (operations1 == 2 && operations2 == 1) {
		formula = num1 * num2 + num3;
		sign[0] = " x ";
		sign[1] = " + ";
	}
	
	else if (operations1 == 2 && operations2 == 2) {
		formula = num1 * num2 - num3;
		sign[0] = " x ";
		sign[1] = " - ";
	}
	
	questionPlay(num1, num2, num3, formula, sign, score);
	
   	return 0;
}

int questionPlay(int num1, int num2, int num3, int formula, string sign[], int scores){
	int answer;
	
	cout << endl << "\tTimer : 3 sec" << endl;
	cout << "\t" << num1 << sign[0] << num2 << sign[1] << num3 << " = ";
	timer(scores);
	cin >> answer;
	system ("CLS");
	
	if (answer != formula) {
		cout << endl << "\tTimer : 3 sec" << endl;
		cout << "\tTry Again!" << endl;
		cout << "\t" << num1 << sign[0] << num2 << sign[1] << num3 << " = ";
		timer(scores);
		cin >> answer;
		system ("CLS");
			if (answer != formula) {
				cout << endl << "\tTimer : 3 sec" << endl;
				cout << "\tTry Again!" << endl;
				cout << "\t" << num1 << sign[0] << num2 << sign[1] << num3 << " = ";
				timer(scores);
				cin >> answer;
				system("CLS");
					if (answer != formula) {
						cout << endl << "\tGAME OVER!!\n  You have wrong 3 times!\n\n\t";
						cout << "Score : " << scores << endl << endl;
						Sleep(2000);
						system("PAUSE");
						endOptionsPlay(); 
						exit(0);		
	}}}
}

void timer(int scores) {
	clock_t start = clock();
	
	while (!kbhit()) {		 // Check if user hit the keyboard
        if (((clock () - start) / CLOCKS_PER_SEC ) >= 3) {    // Check if the timer runs out or not
            cout << "\n\n\tGAME OVER!!\n    THE TIME HAS RUN OUT!" << endl << endl << "\t"; 		  // If the time runs out, then game over
            cout << "Score : " << scores << endl << endl;
			system("PAUSE"); 
			Sleep(2000);
			system("CLS");
			endOptionsPlay();							// Function
			exit(0);				 			 
 		}	                       				                         
	}
}

int endOptionsPlay() {
	int menu;
	
	system("CLS");
	cout << endl << "  1. Play again.";
	cout << endl << "  2. Back to main menu.";
	cout << endl << "  Choose 1 or 2 : ";
	cin >> menu;
	
	if (menu == 1) {
		play();
	}
	else if (menu == 2) {
		main();
	}
	else {
		cout << "\n  Wrong option." << endl << endl << endl;
		system("PAUSE");
		endOptionsPlay();
	}
}

void count() {
	
	for (int countdown = 3; countdown >= 0; countdown--) {
		cout << endl << "\t  " << countdown;
		Sleep(1000);
		system("CLS");
		}

}

	



