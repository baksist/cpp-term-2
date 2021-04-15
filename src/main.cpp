#include <iostream>
#include <limits>
#include "menu.h"

using namespace std;

int main()
{
	int x;
	my_list* foo = NULL;
	cout << "Welcome! Choose an option:\n";
	while(true)
	{
		cout << "1. Enter data from keyboard\n";
		cout << "2. Read data from file\n";
		cout << "3. Add an entry\n";
		cout << "4. Edit an entry\n";
		cout << "5. Delete an entry\n";
		cout << "6. Print all entries\n";
		cout << "7. Print sort result\n";
		cout << "8. Save data to a file\n";
		cout << "0. Exit\n";
		cout << "Enter number(0-9): ";
		while (!(cin >> x))
		{
    			cin.clear();
    			cin.ignore(numeric_limits<streamsize>::max(), '\n');
    			cout << "Invalid data! Try again:\n";
		}
		foo = menu(x, foo);
	}
	return 0;
}
