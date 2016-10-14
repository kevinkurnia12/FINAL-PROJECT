// FINAL PROJECT 
/* Name      : Kevin Kurnia Santosa
   ID       : 2001585253
   Major    : Computer Science
   Program  : Quick Count Game */

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>

// Declare functions
int questionPractice (int); 
int questionPlay (int);
void displayHighscore ();
int addPractice ();
int subPractice ();
int mulPractice ();
int divPractice ();

using namespace std;

int main () 
{
	int inputOptions;
	
	cout << "\n\t\tQUICK COUNT GAME" << "\n\n\t";  // Title of the Program
	
	for (int line = 1; line <= 33; line++)
	{
	cout << "=";
	}
	cout << endl << endl << "\t1. Play" ;
	cout << endl << "\t2. Practice";
	cout << endl << "\t3. Highscore";
	cout << endl << endl << "\tPlease enter your choices : ";
	cin >> inputOptions;
	
	switch (inputOptions)
	{
		case 1 :
		questionPlay ();
		break;
		case 2 :
		questionPractice ();
		break;
		case 3 :
		displayHighscore ();
	}
	getchar ();
	return 0;
}

int questionPractice (int practice)
{	
	char optionPractice;
	
	cout << endl << "a. Addition";
	cout << endl << "b. Subtraction";
	cout << endl << "c. Multiplication";
	cout << endl << "d. Division";
	cout << endl << "e. Exit the program"
	cout << endl << endl << "Which operations do u want to choose ? ";
	cin >> optionPractice;
	
	if (optionPractice == a){
		addPractice ();
	}
	else if (optionPractice == b){
		subPractice ();
	}
	else if (optionPractice == c){
		mulPractice ();
	}
	else if (optionPractice == d){
		divPractice ();
	}
	else if (optionPractice == e){
		return 0;
	}
	else {
		cout << "You're choose the wrong option.";
		return 0;
	}
	
	return 0;
}


   
