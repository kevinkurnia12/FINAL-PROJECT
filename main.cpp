// FINAL PROJECT 
/* Name      : Kevin Kurnia Santosa
   ID        : 2001585253
   Major     : Computer Science
   Program   : Quick Count Game */

#include <iostream>  
#include <ctime>     // Given time for user to input
#include <cstdlib>   // For seed rand (Generate random number)
#include <iomanip>   // Setw
#include <string>    // String
#include <conio.h> 	 // kbhit
#include <windows.h> // Sleep function

// Include the separated file ( Play and Practice )
#include "Practice.cpp"
#include "Play.cpp"

using namespace std;

int main ()  // Start main function
{ 			
	int inputOptions;
	string userName;
	
	system("COLOR 0F");
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
			exit(0);
		default :
			cout << endl << "\tYou enter the wrong option.\n\n" << "\t";
			system("PAUSE");
			main();
			break;
	}
	getchar ();
}


