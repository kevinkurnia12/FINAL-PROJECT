#include <iostream>  
#include <ctime>     // Given time for user to input
#include <cstdlib>   // For seed rand (Generate random number)
#include <string>  	 // String
#include <conio.h>   // kbhit
#include <windows.h> // Sleep

using namespace std;

// Declare function prototypes
int main();
int play();

// Class for play section
class Play {
	private :
		int formula;
		string signs;
   		string sign[2];
   		int answer;
	public :
   		void level1(int num1, int num2, int operations, int scores)
	 	{
 			if (operations == 1) {
 				formula = num1 + num2;
 				signs = " + ";
			}
			
 			else if (operations == 2) {
 				formula = num1 - num2;
 				signs = " - ";
 			}
 
   			cout << endl << "\tTimer : 3 sec" << endl;
    		cout << "\t" << num1 << signs << num2 << " = ";
    		timer(scores);
    		cin >> answer; 
    		system ("CLS");
  
  			if (answer != formula) {
   				cout << endl << "\tTimer : 3 sec" << endl;
   				cout << "\tTry Again!" << endl;
   				cout << "\t" << num1 << signs << num2 << " = ";
   				timer(scores);
   				cin >> answer;
   				system ("CLS");
   				
    				if (answer != formula) {
    					cout << endl << "\tTimer : 3 sec" << endl;
    					cout << "\tTry Again!" << endl;
    					cout << "\t" << num1 << signs << num2 << " = ";
    					timer(scores);
    					cin >> answer;
    					system("CLS");
    					
     						if (answer != formula) {
      							cout << endl << "\tGAME OVER!!\n  You have wrong 3 times!\n\n\t";
      							cout << "Score : " << scores << endl << endl;
      							Sleep(1500);
      							system("PAUSE");
      							endOptionsPlay(); 
     							exit(0);  
 			}}}
		}

		void level2(int num1, int num2, int num3, int operations1, int operations2, int score)
		{
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
		}

		void level3(int num1, int num2, int num3, int operations1, int operations2, int score) 
		{
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
		}

		void questionPlay(int num1, int num2, int num3, int formula, string sign[], int scores)
		{
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
								Sleep(1500);
								system("PAUSE");
								endOptionsPlay(); 
								exit(0);		
			}}}
		}

		void timer(int scores) 
		{
			clock_t start = clock();
	
			while (!kbhit()) {		 // Check if user hit the keyboard
        		if (((clock () - start) / CLOCKS_PER_SEC ) >= 3) {    // Check if the timer runs out or not
            		cout << "\n\n\tGAME OVER!!\n    THE TIME HAS RUN OUT!" << endl << endl << "\t"; 		  // If the time runs out, then game over
            		cout << "Score : " << scores << endl << endl;
					system("PAUSE"); 
					Sleep(1500);
					system("CLS");
					endOptionsPlay();							// Function
					exit(0);				 			 
 				}	                       				                         
			}
		}
		
		void endOptionsPlay() 
		{
			int menu;
	
			system("CLS");
			cout << endl << "  1. Play again.";
			cout << endl << "  2. Back to main menu.";
			cout << endl << "  Choose 1 or 2 : ";
			cin >> menu;
	
			if (menu == 1) 
				play();
			
			else if (menu == 2) 
				main();
	
			else {
				cout << "\n  Wrong option." << endl << endl << endl;
				system("PAUSE");
				endOptionsPlay();
			}
		}

		void count() 
		{
			for (int countdown = 3; countdown >= 0; countdown--) {
				cout << endl << "\t  " << countdown;
				Sleep(1000);
				system("CLS");
			}
		}
};


int play(){
	unsigned s = time(0);
	srand(s);
	int score = 0;
	Play play;
	
	system ("CLS");
	play.count();
	
	for (int no = 1; no <= 10; no++) {
		// First level : there are 1 operations with 2 possible signs (addition and subtraction) and 2 random numbers
		int operation = (rand()%(2-1+1))+1;			// Generate random number between 1 and 2
		int n1 = (rand()%(10-1+1))+1;				// Generate random number between 1 and 10
		int n2 = (rand()%(10-1+1))+1;				// Generate random number between 1 and 10
		play.level1(n1, n2, operation, score);   	// Go to function questionPlay1 (First level)
		score = score + 10;
	}
	 
	cout << endl << "\tCongratulations reaching the first level!" << endl << endl << "\t";
	system ("PAUSE");
	system ("CLS");
	 
	for (int no = 1; no <= 10; no++) {
		// Second level : there are 2 operations with 2 possible signs (addition and subtraction) and 3 random numbers
		int operation1 = (rand()%(2-1+1))+1;				 		// Generate random number between 1 and 2
		int operation2 = (rand()%(2-1+1))+1;	 			 		// Generate random number between 1 and 2
		int n1 = (rand()%(10-1+1))+1;			 					// Generate random number between 1 and 10
		int n2 = (rand()%(10-1+1))+1;			 					// Generate random number between 1 and 10
		int n3 = (rand()%(10-1+1))+1;			 					// Generate random number between 1 and 10
		play.level2(n1, n2, n3, operation1, operation2, score); 	// Go to function questionPlay2 (Second level)
		score = score + 10;
	}
	
	cout << endl << "\tCongratulations reaching the second level!" << endl << endl << "\t";
	system ("PAUSE");
	system ("CLS");
	
	for (int no = 1; no <= 500; no++) {
		// Third Level : there are 2 operations with 3 possible signs(addition, subtraction, and multiplication) and 3 random numbers 	
		int operation1 = (rand()%(2-1+1))+1;						// Generate random number between 1 and 2
		int operation2 = (rand()%(2-1+1))+1;						// Generate random number between 1 and 2
		int n1 = (rand()%(10-1+1))+1;								// Generate random number between 1 and 10
		int n2 = (rand()%(10-1+1))+1;								// Generate random number between 1 and 10
		int n3 = (rand()%(10-1+1))+1;								// Generate random number between 1 and 10
		play.level3(n1, n2, n3, operation1, operation2, score);		// Go to function questionPlay3 (Third level)
		score = score + 10;
	}
	
}





		
