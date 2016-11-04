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
#include <unistd.h>
#include <conio.h> // kbhit

using namespace std;

struct highScore {
	string name;
	string score;
	string rank;
};

// Declare functions
int practice(); 
int addPractice();
int subPractice();
int mulPractice();
int endOptionsPractice();
void displayPoints(int);
int play();
int questionPlay1(int, int, int);
int questionPlay2(int, int, int, int, int);
int questionPlay3(int, int, int, int, int);
void timer1();
void timer2();
int endOptionsPlay();
void displayHighscore(int);


int main () { 			// Start main function
	
	int inputOptions;
	string userName;
	
	cout << "\n\t\tQUICK COUNT GAME";  // Title of the Program
	cout << "\n\n\n\tWelcome !\n\tEnter your name : ";  
	getline (cin, userName);   // Store username
	system ("CLS");
	
	cout << "\n\t\tQUICK COUNT GAME" << "\n\n\t"; 
	for (int line = 1; line <= 33; line++){
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
		cout << endl << "You enter the wrong option.";
		return 0;
	}
	getchar ();
	return 0;
}

int practice () {	
	char optionPractice;
	
	cout << endl << endl << "   a. Addition";
	cout << endl << "   b. Subtraction";
	cout << endl << "   c. Multiplication";
	cout << endl << "   d. Exit the program";
	cout << endl << endl << "  Which operations do you want to choose ? ";
	cin >> optionPractice;
	
	if (optionPractice == 'a' || optionPractice == 'A'){
		system ("CLS");
		addPractice ();
	}
	else if (optionPractice == 'b' || optionPractice == 'B'){
		system ("CLS");
		subPractice ();
	}
	else if (optionPractice == 'c' || optionPractice == 'C'){
		system ("CLS");
		mulPractice ();
	}
	
	else if (optionPractice == 'd' || optionPractice == 'D'){
		return 0;
	}
	else {
		cout << endl << " You choose the wrong option.";
		return 0;
	}
}

int addPractice () {
	unsigned s = time(0);
	srand(s);
	int addAnswer;
	int add;
	int points = 0;
	
	for (int number = 1; number <= 10; number++){
		int n1 = (rand()%(50-10+1))+10;
		int n2 = (rand()%(50-10+1))+10;
		cout << endl << setw(2) << number << ".";
		cout << " " << n1 << endl;
		cout << "    " << n2 << endl;
		cout << "   ____+" << endl << "    ";
		add = n1 + n2;
		cin >> addAnswer;
		
		if (addAnswer != add){
			points = points + 0;
			cout << endl << " WRONG!! Answer : " << add << endl;
		}
		else if (addAnswer = add){
			points = points + 10;
			cout << endl << " RIGHT!!" << endl;
		}
	}
	displayPoints (points);
    endOptionsPractice ();
}

int subPractice () {
	unsigned s = time(0);
	srand(s);
	int subAnswer;
	int sub;
	int points = 0;
	
	for (int number = 1; number <= 10; number++){
		int n1 = (rand()%(100-60+1))+60;
		int n2 = (rand()%(60-10+1))+10;
		cout << endl << setw(2) << number << ".";
		cout << " " << n1 << endl;
		cout << "    " << n2 << endl;
		cout << "   ____-" << endl << "    ";
		sub = n1 - n2;
		
		cin >> subAnswer;
		
		if (subAnswer != sub){
			points = points + 0;
			cout << endl << " WRONG!! Answer : " << sub << endl;
		}
		else if (subAnswer = sub){
			points = points + 10;
			cout << endl << " RIGHT!!" << endl;
		}
	}
	displayPoints (points);
	endOptionsPractice ();
}

int mulPractice () {
	unsigned s = time(0);
	srand(s);
	int mulAnswer;
	int mul;
	int points = 0;
	
	for (int number = 1; number <= 10; number++){
		int n1 = (rand()%(12-1+1))+1;
		int n2 = (rand()%(10-1+1))+1;
		cout << endl << setw(2) << number << ".";
		cout << " " << n1 << endl;
		cout << "    " << n2 << endl;
		cout << "   ____x" << endl << "    ";
		mul = n1 * n2;
		cin >> mulAnswer;
		
		if (mulAnswer != mul){
			points = points + 0;
			cout << endl << " WRONG!! Answer : " << mul << endl;
		}
		else if (mulAnswer = mul){
			points = points + 10;
		cout << endl << " RIGHT!!" << endl;
		}
	}
	displayPoints (points);
	endOptionsPractice();
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

void displayPoints (int point) {
	cout << endl << " Score : " << point;
	 if (point == 100){
		cout << endl << " Excellent!! You got perfect score!!";
	}
	else if (point > 60 && point < 100){
		cout << endl << " Good work!!";
	}
	else {
		cout << endl << " You need more practice.";
	}
}

int play(){
	unsigned s = time(0);
	srand(s);
	system ("CLS");
	
	for (int no = 1; no <= 10; no++){
		int operation = (rand()%(2-1+1))+1;		// Generate random number between 1 and 2
		int n1 = (rand()%(10-1+1))+1;			// Generate random number between 1 and 10
		int n2 = (rand()%(10-1+1))+1;			// Generate random number between 1 and 10
		questionPlay1(n1, n2, operation);   	// Go to function questionPlay1 (First level)
	}
	 // klo brhasil lnjut lvl brikut
	cout << endl << "\tCongratulations reaching the first level!" << endl << endl << "\t";
	system ("PAUSE");
	system ("CLS");
	 
	for (int no = 1; no <= 10; no++){
		// For the next one there are 2 operations and 3 numbers
		int operation1 = (rand()%(2-1+1))+1;				 	// Generate random number between 1 and 2
		int operation2 = (rand()%(2-1+1))+1;	 			 	// Generate random number between 1 and 2
		int n1 = (rand()%(10-1+1))+1;			 				// Generate random number between 1 and 10
		int n2 = (rand()%(10-1+1))+1;			 				// Generate random number between 1 and 10
		int n3 = (rand()%(10-1+1))+1;			 				// Generate random number between 1 and 10
		questionPlay2(n1, n2, n3, operation1, operation2); 		// Go to function questionPlay2 (Second level)
	}
	
	cout << endl << "\tCongratulations reaching the second level!" << endl << endl << "\t";
	system ("PAUSE");
	system ("CLS");
	
	for (int no = 1; no <= 500; no++){
		// For the third one there are 2 operations and 3 numbers 	
		int operation1 = (rand()%(3-1+1))+1;					// Generate random number between 1 and 3
		int operation2 = (rand()%(3-1+1))+1;					// Generate random number between 1 and 3
		int n1 = (rand()%(10-1+1))+1;							// Generate random number between 1 and 10
		int n2 = (rand()%(10-1+1))+1;							// Generate random number between 1 and 10
		int n3 = (rand()%(10-1+1))+1;							// Generate random number between 1 and 10
		questionPlay3(n1, n2, n3, operation1, operation2);		// Go to function questionPlay3 (Third level)
	}
	
	return 0;
}

// function to do the math
int questionPlay1(int num1, int num2, int operations)
{
   	int add, sub;
   	int answer;
   	int score;
	
   	if (operations == 1){
   		add = num1 + num2;
		
		cout << endl << "\tTimer : 2 sec" << endl;
   		cout << "\t" << num1 << " + " << num2 << " = ";
   		timer1();
   		cin >> answer; 
   		system ("CLS");
		
		if (answer != add){
			cout << endl << "\tTimer : 2 sec" << endl;
			cout << "\tTry Again!" << endl;
			cout << "\t" << num1 << " + " << num2 << " = ";
			timer1();
			cin >> answer;
			system ("CLS");
				if (answer != add){
				cout << endl << "\tTimer : 2 sec" << endl;
				cout << "\tTry Again!" << endl;
				cout << "\t" << num1 << " + " << num2 << " = ";
				timer1();
				cin >> answer;
				system ("CLS");
					if (answer != add){
						cout << endl << "\tGame Over!! You have wrong 3 times!" << endl;
						endOptionsPlay(); 
						exit(0);		
	}}}
	score = score + 10;
	displayHighscore(score);
	}

    else if (operations ==2){
    	sub = num1 - num2;
    	
    	cout << endl << "\tTimer : 2 sec" << endl;
    	cout << "\t" << num1 << " - " << num2 << " = ";
    	timer1();
   		cin >> answer;
   		system ("CLS");
		
		if (answer != sub){
			cout << endl << "\tTimer : 2 sec" << endl;
			cout << "\tTry Again!" << endl;
			cout << "\t" << num1 << " - " << num2 << " = ";
			timer1();
			cin >> answer;
			system ("CLS");
				if (answer != sub){
				cout << endl << "\tTimer : 2 sec" << endl;
				cout << "\tTry Again!" << endl;
				cout << "\t" << num1 << " - " << num2 << " = ";
				timer1();
				cin >> answer;
				system ("CLS");
					if (answer != sub){
						cout << endl << "\tGame Over!! You have wrong 3 times!" << endl;
						endOptionsPlay(); 
						exit(0);		
	}}}
	score = score + 10;
	displayHighscore(score);
	}
	
	return 0;
}

int questionPlay2(int num1, int num2, int num3, int operations1, int operations2){
	
	int addAdd, addSub, subAdd, subSub;
   	int answer;
   	int score=0;
	
	if (operations1 == 1 && operations2 == 1){
		addAdd = num1 + num2 + num3;
		
		cout << endl << "\tTimer : 3 sec" << endl;
		cout << "\t" << num1 << " + " << num2 << " + " << num3 << " = ";
		timer2();
		cin >> answer;
		system ("CLS");
	
		if (answer != addAdd){
			cout << endl << "\tTimer : 3 sec" << endl;
			cout << "\tTry Again!" << endl;
			cout << "\t" << num1 << " + " << num2 << " + " << num3 << " = ";
			timer2();
			cin >> answer;
			system ("CLS");
				if (answer != addAdd){
				cout << endl << "\tTimer : 3 sec" << endl;
				cout << "\tTry Again!" << endl;
				cout << "\t" << num1 << " + " << num2 << " + " << num3 << " = ";
				timer2();
				cin >> answer;
				system ("CLS");
					if (answer != addAdd){
						cout << endl << "\tGame Over!! You have wrong 3 times!" << endl;
						endOptionsPlay(); 
						exit(0);		
	}}}
	score = score + 10;
	displayHighscore(score);
	}
	
	else if (operations1 == 1 && operations2 == 2){
		addSub = num1 + num2 - num3;
		
		cout << endl << "\tTimer : 3 sec" << endl;
		cout << "\t" << num1 << " + " << num2 << " - " << num3 << " = ";
		timer2();
		cin >> answer;
		system ("CLS");
	
		if (answer != addSub){
			cout << endl << "\tTimer : 3 sec" << endl;
			cout << "\tTry Again!" << endl;
			cout << "\t" << num1 << " + " << num2 << " - " << num3 << " = ";
			timer2();
			cin >> answer;
			system ("CLS");
				if (answer != addSub){
				cout << endl << "\tTimer : 3 sec" << endl;
				cout << "\tTry Again!" << endl;
				cout << "\t" << num1 << " + " << num2 << " - " << num3 << " = ";
				timer2();
				cin >> answer;
				system ("CLS");
					if (answer != addSub){
						cout << endl << "\tGame Over!! You have wrong 3 times!" << endl;
						endOptionsPlay(); 	
						exit(0);	
	}}}
	score = score + 10;
	displayHighscore(score);
	}
	
	else if (operations1 == 2 && operations2 == 1){
		subAdd = num1 - num2 + num3;
		
		cout << endl << "\tTimer : 3 sec" << endl;
		cout << "\t" << num1 << " - " << num2 << " + " << num3 << " = ";
		timer2();
		cin >> answer;
		system ("CLS");
	
		if (answer != subAdd){
			cout << endl << "\tTimer : 3 sec" << endl;
			cout << "\tTry Again!" << endl;
			cout << "\t" << num1 << " - " << num2 << " + " << num3 << " = ";
			timer2();
			cin >> answer;
			system ("CLS");
				if (answer != subAdd){
				cout << endl << "\tTimer : 3 sec" << endl;
				cout << "\tTry Again!" << endl;
				cout << "\t" << num1 << " - " << num2 << " + " << num3 << " = ";
				timer2();
				cin >> answer;
				system ("CLS");
					if (answer != subAdd){
						cout << endl << "\tGame Over!! You have wrong 3 times!" << endl;
						endOptionsPlay(); 		
						exit(0);
	}}}
	score = score + 10;
	displayHighscore(score);
	}
	
	
	else if (operations1 == 2 && operations2 == 2){
		subSub = num1 - num2 - num3;
		
		cout << endl << "\tTimer : 3 sec" << endl;
		cout << "\t" << num1 << " - " << num2 << " - " << num3 << " = ";
		timer2();
		cin >> answer;
		system ("CLS");
	
		if (answer != subSub){
			cout << endl << "\tTimer : 3 sec" << endl;
			cout << "\tTry Again!" << endl;
			cout << "\t" << num1 << " - " << num2 << " - " << num3 << " = ";
			timer2();
			cin >> answer;
			system ("CLS");
				if (answer != subSub){
				cout << endl << "\tTimer : 3 sec" << endl;
				cout << "\tTry Again!" << endl;
				cout << "\t" << num1 << " - " << num2 << " - " << num3 << " = ";
				timer2();
				cin >> answer;
				system ("CLS");
					if (answer != subSub){
						cout << endl << "\tGame Over!! You have wrong 3 times!" << endl;
						endOptionsPlay(); 		
						exit(0);
	}}}
	score = score + 10;
	displayHighscore(score);
	}	
   		
   	return 0;
}

int questionPlay3(int num1, int num2, int num3, int operations1, int operations2){
	
	int addMul, subMul, mulAdd, mulSub;
   	int answer;
   	int score=0;
	
	if (operations1 == 1 && operations2 == 3){
		addMul = num1 + num2 * num3;
		
		cout << endl << "\tTimer : 3 sec" << endl;
		cout << "\t" << num1 << " + " << num2 << " x " << num3 << " = ";
		timer2();
		cin >> answer;
		system ("CLS");
	
		if (answer != addMul){
			cout << endl << "\tTimer : 3 sec" << endl;
			cout << "\tTry Again!" << endl;
			cout << "\t" << num1 << " + " << num2 << " x " << num3 << " = ";
			timer2();
			cin >> answer;
			system ("CLS");
				if (answer != addMul){
				cout << endl << "\tTimer : 3 sec" << endl;
				cout << "\tTry Again!" << endl;
				cout << "\t" << num1 << " + " << num2 << " x " << num3 << " = ";
				timer2();
				cin >> answer;
				system ("CLS");
					if (answer != addMul){
						cout << endl << "\tGame Over!! You have wrong 3 times!" << endl;
						endOptionsPlay(); 		
						exit(0);
	}}}
	score = score + 10;
	displayHighscore(score);
	}
	
	else if (operations1 == 2 && operations2 == 3){
		subMul = num1 - num2 * num3;
		
		cout << endl << "\tTimer : 3 sec" << endl;
		cout << "\t" << num1 << " - " << num2 << " x " << num3 << " = ";
		timer2();
		cin >> answer;
		system ("CLS");
	
		if (answer != subMul){
			cout << endl << "\tTimer : 3 sec" << endl;
			cout << "\tTry Again!" << endl;
			cout << "\t" << num1 << " - " << num2 << " x " << num3 << " = ";
			timer2();
			cin >> answer;
			system ("CLS");
				if (answer != subMul){
				cout << endl << "\tTimer : 3 sec" << endl;
				cout << "\tTry Again!" << endl;
				cout << "\t" << num1 << " - " << num2 << " x " << num3 << " = ";
				timer2();
				cin >> answer;
				system ("CLS");
					if (answer != subMul){
						cout << endl << "\tGame Over!! You have wrong 3 times!" << endl;
						endOptionsPlay(); 		
						exit(0);
	}}}
	score = score + 10;
	displayHighscore(score);
	}
	
	else if (operations1 == 3 && operations2 == 1){
		mulAdd = num1 * num2 + num3;
		
		cout << endl << "\tTimer : 3 sec" << endl;
		cout << "\t" << num1 << " x " << num2 << " + " << num3 << " = ";
		timer2();
		cin >> answer;
		system ("CLS");
	
		if (answer != mulAdd){
			cout << endl << "\tTimer : 3 sec" << endl;
			cout << "\tTry Again!" << endl;
			cout << "\t" << num1 << " x " << num2 << " + " << num3 << " = ";
			timer2();
			cin >> answer;
			system ("CLS");
				if (answer != mulAdd){
				cout << endl << "\tTimer : 3 sec" << endl;
				cout << "\tTry Again!" << endl;
				cout << "\t" << num1 << " x " << num2 << " + " << num3 << " = ";
				timer2();
				cin >> answer;
				system ("CLS");
					if (answer != mulAdd){
						cout << endl << "\tGame Over!! You have wrong 3 times!" << endl;
						endOptionsPlay(); 		
						exit(0);
	}}}
	score = score + 10;
	displayHighscore(score);
	}
	
	else if (operations1 == 3 && operations2 == 2){
		mulSub = num1 * num2 - num3;
		
		cout << endl << "\tTimer : 3 sec" << endl;
		cout << "\t" << num1 << " x " << num2 << " - " << num3 << " = ";
		timer2();
		cin >> answer;
		system ("CLS");
	
		if (answer != mulSub){
			cout << endl << "\tTimer : 3 sec" << endl;
			cout << "\tTry Again!" << endl;
			cout << "\t" << num1 << " x " << num2 << " - " << num3 << " = ";
			timer2();
			cin >> answer;
			system ("CLS");
				if (answer != mulSub){
				cout << endl << "\tTimer : 3 sec" << endl;
				cout << "\tTry Again!" << endl;
				cout << "\t" << num1 << " x " << num2 << " - " << num3 << " = ";
				timer2();
				cin >> answer;
				system ("CLS");
					if (answer != mulSub){
						cout << endl << "\tGame Over!! You have wrong 3 times!" << endl;
						endOptionsPlay(); 	
						exit(0);
	}}}
	score = score + 10;
	displayHighscore(score);
	}
	
   	return 0;
}

void timer1(){
	clock_t start = clock();
	
	while (!kbhit()) {		 // Check if user hit the keyboard
        if (((clock () - start) / CLOCKS_PER_SEC ) >= 2) {    // Check if the timer runs out or not
            cout << "\n\n\tGAME OVER!! The Time runs out!" << endl << endl << "\t"; 		  // If the time runs out, then game over
			system("PAUSE"); 
			system("CLS");
			endOptionsPlay();							// Function
			exit(0);				 			 
 		}	                       				                         
	}
}
				    
void timer2(){
	clock_t start = clock();  
	
	while (!kbhit()) { 		// Check if user hit the keyboard
    	if (((clock () - start) / CLOCKS_PER_SEC ) >= 3) {   // Check if the timer runs out or not
            cout << "\n\n\tGAME OVER!! The Time runs out!" << endl << endl << "\t";			 // If the time runs out, then game over
			system("PAUSE");
			system("CLS");
    		endOptionsPlay(); 							// Function
			exit(0);				 	  	  				                    						                           
        }
    }
}

int endOptionsPlay(){
	int menu;
	
	cout << endl << "  1. Play again.";
	cout << endl << "  2. Back to main menu.";
	cout << endl << "  Choose 1 or 2 : ";
	cin >> menu;
	
	if (menu == 1){
		play();
	}
	else if (menu == 2){
		main();
	}
	else {
		cout << "\n  Wrong option.";
		return 0;
	}
}

void displayHighscore(int hs) {
	cout << endl << endl << "Highscore : " << hs;
}







   
