#include <iostream>
using std::cin;
using std::cout;
using std::endl;]
using std::strlen;

// Prototypes
void getSentence(char sentence[]);
int getSum(const char sentence[]);
int computeHash(int sum);
void runTestCases();
bool test(const char sentence[], int expectedValue);
bool isValid(const char sentence[]);

// main
int main()
{
	/* ***Comment in to run test cases*** */
	//runTestCases();

	while (true)
	{
		// variables
		char sentence[150];
		int sum = 0;
		int hashNo = 0;
		cout << "Press [Enter] to quit" << endl;
		// Prompt user for a sentence.
		getSentence(sentence);

		if (strlen(sentence) > 0)
		{
			// if valid...
			if (isValid(sentence))
			{
				// Get sum, compute hash, display results
				sum = getSum(sentence);
				hashNo = computeHash(sum);
				cout << "the hash is: " << hashNo << endl;
				cout << endl;
			}
			else
			{
				cout << "**cough... Indigestible input." << endl;
				cout << endl;
				continue;
			}
		}
		else
		{
			//Break out of loop: user pressed enter
			break;
		}
	} // end while

	// fin.
	system("pause");
	return 0;
//  ____________________
}// |_____end main_____|


/* Function Definitions */
void getSentence(char sentence[])
{
	cout << "Please enter a sentence: ";
	cin.getline(sentence, 150);
	cout << endl;
}
int getSum(const char sentence[])
{
	int sum = 0;
	int letterCode = 0;

	for (int i = 0; i < strlen(sentence); i++)
	{
		letterCode = (sentence[i] == ' ') ? 31 : ((toupper(sentence[i]) - 'A') + 1);
		sum += letterCode;

	}

	return sum;
}
int computeHash(int sum)
{
		return (sum % 31);
}
bool isValid(const char sentence[])
{
	for (int i = 0; i < strlen(sentence); i++)
	{
		//Capital letters: 65 – 90
		//Space: 32
		if ((toupper(sentence[i]) >= 65 && toupper(sentence[i]) <= 90) || (sentence[i] == 32))
		{
			continue;
		}
		else { return false; }
	}

	return true;
}
void runTestCases()
{
	char letters[] = { "a" };

	// Test some sentences
	test("My name is Gabrielle", 15);
	test("Weber State is the best", 8);
	test("The quick brown fox jumps over the lazy dog", 8);
	test("How quickly daft jumping zebras vex", 15);
	test("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test("abcdefghijklmnopqrstuvwxyz", 10);

	// Test each letter in the alphabet
	for (int i = 0; i < 26; ++i)
	{
		test(letters, i + 1);
		letters[0] = ++letters[0];
	}

	// Test invalid sentences - should cough it out
	test("q345df df 4 4523 asdf", 400);
	test("Here's a punctuated sentence.", 400);
	test("`", 400);
	test("~", 400);
	test("!", 400);
	test("@", 400);
	test("#", 400);
	test("$", 400);
	test("%", 400);
	test("^", 400);
	test("&", 400);
	test("*", 400);
	test("(", 400);
	test(")", 400);
	test("-", 400);
	test("_", 400);
	test("=", 400);
	test("+", 400);

	// Test outputs of 0, and 27-30
	test("Ooa", 0);
	test("Yaa", 27);
	test("Yaaa", 28);
	test("Yaaaa", 29);
	test("Yaaaaa", 30);

	cout << endl;
}
bool test(const char sentence[], int expectedValue)
{
	int sum;
	int actualValue;

	if (isValid(sentence))
	{
		sum = getSum(sentence);
		actualValue = computeHash(sum);
	}
	else
	{
		cout << "**cough... Indigestible input." << endl;
		cout << endl;
		return true;
	}


	if (actualValue == expectedValue)
	{
		cout << "PASSED - " << sentence << "\nExpected: " << expectedValue << 
			" Actual: " << actualValue << endl;
		cout << endl;
		return true;
	}
	else
	{
		cout << "****FAILED**** \t" << sentence << endl;
		cout << "Expected: " << expectedValue << ", Actual: " << actualValue << endl;
		return false;
	}
}
