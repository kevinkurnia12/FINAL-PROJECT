// FINAL PROJECT 
/* Name      : Kevin Kurnia Santosa
   ID       : 2001585253
   Major    : Computer Science
   Program  : Quick Count Game */

#include <iostream>  
#include <ctime>   // Given time for user to input
#include <cstdlib> // For seed rand (Generate random number)
#include <iomanip> // Setw
#include <string>
#include <fstream>

// Declare functions
int practice (); 
int play ();
void displayHighscore ();
int addPractice ();
int subPractice ();
int mulPractice ();
int divPractice ();
int endOptionsPractice ();
int endOptionsPlay ();
void displayPoints (int point);

using namespace std;

int main () // Start main function
{
	system("COLOR 8E");
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
	cout << endl << "\t3. Highscore";
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
		displayHighscore ();
		break;
		default :
		cout << endl << "You enter the wrong option.";
		return 0;
	}
	getchar ();
	return 0;
}

int practice ()
{	
	char optionPractice;
	
	cout << endl << endl << "   a. Addition";
	cout << endl << "   b. Subtraction";
	cout << endl << "   c. Multiplication";
	cout << endl << "   d. Division";
	cout << endl << "   e. Exit the program";
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
		system ("CLS");
		divPractice ();
	}
	else if (optionPractice == 'e' || optionPractice == 'E'){
		return 0;
	}
	else {
		cout << endl << " You choose the wrong option.";
		return 0;
	}
	return 0;
}

int addPractice ()
{
	unsigned s = time(0);
	srand(s);
	int addAnswer;
	int add;
	int points = 0;
	
	for (int number = 1; number <= 10; number++){
		int n1 = (rand()%(100-10+1))+10;
		int n2 = (rand()%(100-10+1))+10;
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

int subPractice ()
{
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

int mulPractice ()
{
	unsigned s = time(0);
	srand(s);
	int mulAnswer;
	int mul;
	int points = 0;
	
	for (int number = 1; number <= 10; number++){
		int n1 = (rand()%(20-1+1))+1;
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

int divPractice () // unfinished
{
	unsigned s = time(0);
	srand(s);
	float divAnswer;
	float div;
	int points = 0;
		
	for (int number = 1; number <= 10; number++){
		int n1 = (rand()%(81-10+1))+10;
		int n2 = (rand()%(9-1+1))+1;
		cout << endl << setw(2) << number << ".";
		cout << " " << n1 << endl;
		cout << "     " << n2 << endl;
		cout << "   ____:" << endl << "    ";
		div = n1 / n2;
		cin >> divAnswer;
		
		if (divAnswer != div){
			points = points + 0;
			cout << endl << " WRONG!! Answer : " << div << endl;
		}
		else if (divAnswer = div){
			points = points + 10;
			cout << endl << " RIGHT!!" << endl;
		}
	}
	displayPoints (points);
	endOptionsPractice ();
}

void displayHighscore ()
{
	
}

int play ()
{
	return 0;
}

int endOptionsPractice ()
{
	string yesno;
	int backMenu;
	
	cout << endl;
	cout << endl << " Try again ? \n Yes/No ? ";
	cin >> yesno;
	if (yesno == "Yes" || yesno == "yes" || yesno == "y"){
		system ("CLS");
		practice ();
	}
	else if (yesno == "No" || yesno == "no" || yesno == "n"){
		cout << endl << "  1. Back to menu.";
		cout << endl << "  2. Exit the program.";
		cout << endl << " Choose 1 or 2 : ";
		cin >> backMenu;
		if (backMenu == 1){
			main();
		}
		else if (backMenu == 2){
			return 0;
		}
		else {
			cout << "Wrong option.";
			return 0;
		}
	}
	else {
		cout << endl << " You choose the wrong option.";
		return 0;
	}
}

void displayPoints (int point)
{
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




   
