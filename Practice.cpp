#include <iostream>  
#include <ctime>   // Given time for user to input
#include <cstdlib> // For seed rand (Generate random number)
#include <iomanip> // Setw
#include <string>  // String

using namespace std;

// Declare function prototypes
int main();
int practice(); 

class Practice {
	private :
		int formula;
		string symbol;
		int point = 0;
	public :
		void addPractice () 
		{ 
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
	
		void subPractice () 
		{
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

		void mulPractice ()
		{
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

		int questionPractice (int number, int answer, int n1, int n2, string symbol, int points) 
		{
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
		
		int endOptionsPractice () 
		{
			string yesno;
			int backMenu;
	
			cout << endl;
			cout << endl << "  Try again ? \n  Yes/No ? ";
			cin >> yesno;
			
			if (yesno == "Yes" || yesno == "yes" || yesno == "y") {
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
					exit(0);
				}
				else {
					cout << "\n  Wrong option.";
					exit(0);
				}
			}
			
			else {
				cout << endl << " You choose the wrong option." << endl << endl;
				system("PAUSE");
				system("CLS");
				endOptionsPractice();
			}
		}
	
		void displayPoints (int practiceScore) 
		{
			cout << endl << " Score : " << practiceScore;
	
			if (practiceScore == 100)
				cout << endl << " Excellent!! You got perfect score!!";
			
			else if (practiceScore >= 60 && practiceScore <= 100)
				cout << endl << " Good work!!";
			
			else 
				cout << endl << " You need more practice.";
		}
};


int practice () 
{	
	char optionPractice;
	unsigned s = time(0);
	srand(s);
	Practice exercise;
	
	cout << endl << endl << "   a. Addition";
	cout << endl << "   b. Subtraction";
	cout << endl << "   c. Multiplication";
	cout << endl << "   d. Exit the program";
	cout << endl << endl << "  Which operations do you want to choose (a, b, c, d) ? ";
	cin >> optionPractice;
	
	switch (optionPractice) 
	{
		case 'a' :
			system("CLS");
			exercise.addPractice();
			break;
		case 'b' :
			system("CLS");
			exercise.subPractice();
			break;
		case 'c' :
			system("CLS");
			exercise.mulPractice();
			break;
		case 'd' :
			exit(0);
		default :
			cout << endl << " You choose the wrong option.\n\n" << " ";
			system("PAUSE");
			system("CLS");
			practice();
			break;
	}
}





