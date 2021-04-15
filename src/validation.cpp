#include <iostream>
#include <limits>
#include "validation.h"

using namespace std;

bool check_birthdate(unsigned short day, unsigned short month, unsigned short year)
{
	if (day == 0 || month == 0)
	{
		return false;
	}
	if (year < 1940 || year > 2020)
	{
		return false;
	}
	switch (month)
	{
		case 1:
			if (day > 31)
			{
				return false;
			}
			break;
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			{
				if (day > 29)
				{
					return false;
				}
			}
			else
			{
				if (day > 28)
				{
					return false;
				}
			}
			break;
		case 3:
			if (day > 31)
			{
				return false;
			}
			break;
		case 4:
			if (day > 30)
			{
				return false;
			}
			break;
		case 5:
			if (day > 31)
			{
				return false;
			}
			break;
		case 6:
			if (day > 30)
			{
				return false;
			}
			break;
		case 7:
			if (day > 31)
			{
				return false;
			}
			break;
		case 8:
			if (day > 31)
			{
				return false;
			}
			break;
		case 9:
			if (day > 30)
			{
				return false;
			}
			break;
		case 10:
			if (day > 31)
			{
				return false;
			}
			break;
		case 11:
			if (day > 30)
			{
				return false;
			}
			break;
		case 12:
			if (day > 31)
			{
				return false;
			}
			break;
	}
	return true;
}

bool check_sex(char input)
{
	return (input == 'M' || input == 'F');
}

bool check_enroll_year(unsigned short input)
{
	return (input >= 1947);
}

bool check_mark(unsigned short input)
{
	return (input >= 2 && input <= 5);
}

void clearbuf()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void input_error()
{
	 cout << "Invalid data! Try again:\n";
}
