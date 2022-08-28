#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 80; // Global Variable

// Function prototypes
void append(char[]); // This function will allow the user to append (add) a specified string at the end of the worked-on string
void find(char[]); // This function with search the word
void insert(char[]); // This function will allow the user to search for a specified string in the worked-on string. If the string is found, it will display the starting index (position) of the searched string in the worked-on string. This option will allow the user to insert a string at a specified index in the worked-on string.
void replace(char[]); // This function will allow the user to replace an existing string in the worked-on string with a specified string
void deleter(char[]); // This function will search for a specified string in the worked-on string. If the specified string is found, it will eliminate it from the worked-on string.
int search(char sourceString[], char targetString[]);

int main()
{
	char option;
	char buffer[SIZE];

	string menu = "s-search, i-insert, a-append, r-replace, d-delete, e-exit"; // Creating the menu

	cout << "Enter a string you would like to edit " << endl; // Asking the user on which word he/she would like to edit
	cin.getline(buffer, SIZE);

	cout << menu << endl; // Outputing the menu for the user to see

	cin >> option; // Inputing the option from the menu
	cin.ignore();


	while (option != 'e') // Loop statement that will keep on repeating until the user presses "e" to exit
	{
		switch (option)
		{
		case 's': find(buffer); // Case 's' will search the word
			break;
		case 'i': insert(buffer); // Case 'i" will insert the word into the sentence
			break;
		case 'a': append(buffer); // Case 'a' will add a string into the sentence
			break;
		case 'd': deleter(buffer); // Case 'd' will delete the string from the sentence
			break;
		case 'r': replace(buffer); // Case 'r' will replace the string in the sentence for another word
			break;
		default: cout << "Invalid" << endl;
		}
		cout << menu << endl;
		cin >> option;
		cin.ignore();
	}
	return 0;
}

void append(char buffer[]) // Function definition for append
{
	char toappend[SIZE];
	char empty[SIZE] = " ";

	cout << "Enter the string to be appended " << endl; // Asking the user which word he/she would like to replace
	cin.getline(toappend, SIZE);

	strcat(buffer, empty);
	strcat(buffer, toappend);

	cout << "The new string is " << buffer << endl; // Producing the new sentence with the newley added word
}

void find(char buffer[]) //  Function definition for find
{
	char tosearch[SIZE];
	int found;

	cout << "Enter a substring to saerch" << endl; // Asking the user which word to search
	cin.getline(tosearch, SIZE); 

	found = search(buffer, tosearch);

	if (found == -1)
	{
		cout << "The substring is not found" << endl; // If the word is not found, it will loop. The word has to be the same, meaning if it is non-capitalized, the word must not be capitalized as well.
	}
	else
	{
		cout << "The substring is found at the position " << found << endl; 
		cout << endl;
	}

	cout << "The new string is " << buffer << endl;
}

void insert(char buffer[]) // Function definition for insert
{
	char toinsert[SIZE];
	char empty[SIZE] = " ";
	int position;
	char temp[SIZE];

	cout << "Enter a string to insert " << endl; // Asking the user what word he/she would like to insert
	cin.getline(toinsert, SIZE);

	cout << "At which position should it be inserted?" << endl; // Asking the user where the new word should be inserted
	cin >> position;
	cin.ignore();

	strcpy(temp, &buffer[position]);
	buffer[position] = '\0';
	strcat(buffer, empty);
	strcat(buffer, toinsert);
	strcat(buffer, temp);

	cout << "The new string is " << buffer << endl; // Producing the new sentence 
}

void deleter(char buffer[]) // Function definition of deleter
{
	char todelete[SIZE];
	int position;
	char empty[SIZE] = " ";
	char temp[SIZE];

	cout << "Enter a string to be deleted" << endl; // Asking the user which word he/she wants to delete
	cin.getline(todelete, SIZE);
	position = search(buffer, todelete);

	if (position == -1)
	{
		cout << "The substring is not in the string" << endl;
	}
	else
	{
		strcpy(temp, &buffer[position + strlen(todelete)]);
		buffer[position] = '\0';
		strcat(buffer, temp);
		cout << "The updated string is " << buffer << endl; // Producing the sentence after the word has been deleted
	}
}

void replace(char buffer[]) // Function definintion for replace
{
	char toreplace[SIZE];
	char newsubstring[SIZE];
	char temp[SIZE];
	int found;
	char empty[SIZE] = " ";

	cout << "Enter a substring to be replaced" << endl; // Asking the user which word is to be replaced
	cin.getline(toreplace, SIZE);

	cout << "Enter the new substring " << endl; // Asking the user the word that will replace the previous word
	cin.getline(newsubstring, SIZE);

	found = search(buffer, toreplace);

	if (found == -1) // Confirmation loop
	{
		cout << "The string you want to replace does not exist" << endl;
	}
	else
	{
		strcpy(temp, &buffer[found + strlen(toreplace)]);
		buffer[found] = '\0';
		strcat(buffer, empty);
		strcat(buffer, newsubstring);
		strcat(buffer, temp);

		cout << "The updated string is " << buffer << endl; // Producing the sentence after the word has been replaced
	}
}

int search(char sourceString[], char targetString[]) // Function definintion of search
{
	int sourceLength, targetLength, index, returnValue;

	sourceLength = strlen(sourceString);
	targetLength = strlen(targetString);

	index = -1;

	for (int i = 0; i < (sourceLength - (targetLength - 1)); i++) 
	{
		returnValue = strncmp(&sourceString[i], targetString, targetLength);

		if (returnValue == 0)
		{
			index = i;
			break;
		}
	}
	return index;
}