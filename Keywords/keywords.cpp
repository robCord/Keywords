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
	enum fields {WORD, HINT, NUM_FIELDS};
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
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD]; //word guess
	string theHint = WORDS[choice][HINT];//corresponding hint

	string jumble = theWord; //variable for scrambled version of word
	int length = jumble.size();
	for (int i = 0; i < length; i++)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
}