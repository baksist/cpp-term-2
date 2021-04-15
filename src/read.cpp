#include <iostream>
#include "read.h"
#include "my_list.h"
#include "validation.h"

using namespace std;

student read_student(my_list* data)
{
	string lastname;
	cout << "Enter last name: ";
	cin.clear();
	getline(cin, lastname);

	string firstname;
	cout << "Enter first name: ";
	cin.clear();
	getline(cin, firstname);

	string middlename;
	cout << "Enter middle name: ";
	cin.clear();
	getline(cin, middlename);

	unsigned short date[3];
	cout << "Enter date of birth\n";
	do
	{
		
		cout << "Day: ";
		while(!(cin >> date[0]))
		{
			clearbuf();
			input_error();
		}
		cout << "Month: ";
		while(!(cin >> date[1]))
		{
			clearbuf();
			input_error();
		}
		cout << "Year: ";
		while(!(cin >> date[2]))
		{
			clearbuf();
			input_error();
		}
	}while(check_birthdate(date[0], date[1], date[2]) != true);	

	char s;
	do
	{
		cout << "Enter sex: ";
		cin >> s;
		clearbuf();

	}while(check_sex(s) != true);

	unsigned short enroll;
	do
	{
		cout << "Enter enroll year: ";
		while(!(cin >> enroll))
		{
			clearbuf();
			input_error();
		}
	}while((check_enroll_year(enroll) != true) || (date[2] >= enroll - 15));

	clearbuf();

	string facul;
	cout << "Enter faculty: ";
	cin.clear();
	getline(cin, facul);

	string dep;
	cout << "Enter department: ";
	cin.clear();
	getline(cin, dep);

	string gro;
	cout << "Enter group: ";
	cin >> gro;
	clearbuf();

	string zachotka;
	cout << "Enter ID: ";
	while(true)
	{	
		cin >> zachotka;
		clearbuf();
		
		if (data != NULL)
		{
			if (find_element_by_id(data, zachotka) != NULL)
			{
				cout << "Error: this ID already exists. Try again: ";
				continue;
			}
		}
		break;
	}	
	
	int sesnum;
	do{
		cout << "Enter number of sessions: ";
		while(!(cin >> sesnum))
		{
			clearbuf();
			input_error();
		}
	}while(!(sesnum >= 1 && sesnum <= 9));

	session ses[sesnum];

	for (int i = 0; i < sesnum; i++)
	{
		int subjnum = 0;
		do
		{
			cout << "Enter number of subjects in session №" << i+1 << ": ";
			while(!(cin >> subjnum))
			{
				clearbuf();
				input_error();
			}
		}while(!(subjnum >= 1 && subjnum <= 10));
		ses[i].set_n(subjnum);
		subject input[subjnum];
		for (int j = 0; j < subjnum; j++)
		{
			string subname;
			unsigned short submark = 0;
			cout << "Enter name of the subject: ";
			cin.ignore();
			getline(cin, subname);
			do
			{	
				cout << "Enter mark: ";
				while(!(cin >> submark))
				{
					clearbuf();
					input_error();
				}
			}while(check_mark(submark) != true);
			input[j].name = subname;
			input[j].mark = submark;
		}
		ses[i].set(input);
	}
	
	student x = student(sesnum);
	x.set_full_name(lastname, firstname, middlename);
	x.set_birthdate(date[0], date[1], date[2]);
	x.set_sex(s);
	x.set_enroll_year(enroll);
	x.set_fac(facul);
	x.set_kaf(dep);
	x.set_group(gro);
	x.set_id(zachotka);
	x.set_marks(ses);
	return x;
}

my_list* read_from_keyboard()
{
	clearbuf();
	my_list* studlist = NULL;
	student x = read_student(studlist);
	studlist = init_list(x);
	char flag;
	while(true)
	{
		cout << "Add more(y/n)? ";
		do
		{
			cin >> flag;
			clearbuf();
		}while(!(flag == 'y' || flag == 'n'));
		if (flag == 'n')
		{
			break;
		}
		studlist = add_element(studlist, read_student(studlist));
	}
	return studlist;
}
