//keywords assignment
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//start main function
int main()
{
	//set the words into a list along with corresponding hints
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel you're banging your head against something"},
		{"glasses", "These might help you see answer."},
		{"labored", "Going slowly, is it"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."},
		{"knife", "This will help with cutting of loose ends."},
		{"water", "Stay hydrated."},
		{"compass", "Find your way."},
		{"wallet", "Comes with some dollar bills and your ID."},
		{"watch", "Helps keep track of time."},
	};

	//picking a random word from the choices 
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < 3; i++) {
		int choice = (rand() % NUM_WORDS);
		string theWord = WORDS[choice][WORD]; //word guess
		string theHint = WORDS[choice][HINT];//corresponding hint

		string jumble = theWord; //variable for scrambled version of word
		int length = jumble.size();
		for (int j = 0; j < length; j++)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}
		string guess;
		int guessCounter = 0;
		do
		{
			cout << "This is the keyword " << jumble << endl;
			cout << "Enter guess ";
			cin >> guess;

			guessCounter++;
			
			if (guess == theWord)
			{
				cout << "guess was correct" << endl;
			}
			
			else if(guess == "hint")
			{
				cout << theHint << endl;
				guessCounter--;
			}
			else if (guess == "quit")
			{
				cout << "quitting round" << endl;
			}
			else
			{
				cout << "guess was incorrect " << endl;
			}
			
		} while (guess != theWord && guess != "quit");

		if (guess == "quit")
		{
			break;
		}
		else
		{
			cout << "You got it! Here are your stats:" << endl;
			cout << "Number of guesses: "<< guessCounter << "\n\n";
		}
	}
}