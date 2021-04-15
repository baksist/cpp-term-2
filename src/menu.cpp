#include <iostream>
#include "menu.h"
#include "read.h"
#include "files.h"

using namespace std;

my_list* menu(int x, my_list* lst)
{ 
	switch(x)
	{
		case 1:
			if (lst != NULL)
				lst = delete_list(lst);
			lst = read_from_keyboard();
			break;
		case 2:
			if (lst != NULL)
				lst = delete_list(lst);
			lst = read_from_file(lst);
			break;
		case 3:
			if (lst != NULL)
			{
				cin.ignore();
				lst = add_element(lst, read_student(lst));
			}
			break;
		case 4:
			if (lst != NULL)
				lst = edit_entry(lst);
			break;
		case 5:
			if (lst != NULL)
				lst = delete_entry(lst);
			break;
		case 6:
			if (lst != NULL)
				print_list(lst);
			break;
		case 7:
			if (lst != NULL)
				print_result(lst);
			break;
		case 8:
			if (lst != NULL)
				save_data(lst);
			break;
		case 0:
			if (lst != NULL)
				lst = delete_list(lst);
			exit(0);
			break;
		default:
			cout << "Error: no matching options\n";
		   	break;	
	}
	return lst;
}

my_list* edit_entry(my_list* input)
{
	string ed_id;
	cout << "Enter ID of student you want to edit: ";
	cin >> ed_id;
	my_list* x = find_element_by_id(input, ed_id);
	if (x == NULL)
	{
		cout << "Entry not found!" << endl;
	}
	else
	{
		x->val = edit(x->val);
	}
	return input;	
}

my_list* delete_entry(my_list* input)
{	
	string del_id;
	cout << "Enter ID of student you want to delete: ";
	cin >> del_id;
	my_list* del = find_element_by_id(input, del_id);
	if (del == NULL)
	{
		cout << "Entry not found!" << endl;
	}
	else
	{
		if (del == del->nxt)
		{
			input = delete_list(input);
		}
		else
		{
			input = delete_element(del);
		}
	}
	return input;
}

void print_result(my_list* input)
{
	unsigned short beg, end;
	cout << "Enter birth year interval\n";
	cout << "Start: ";
	while(!(cin >> beg))
	{
		clearbuf();
		input_error();
	}
	cout << "End: ";
	while(!(cin >> end))
	{
		clearbuf();
		input_error();
	}
	my_list* output = get_students_by_year(input, beg, end);
	if(output == NULL)
	{
		cout << "No students found in interval " << beg << "-" << end << endl;
	}
	else
	{
		unsigned short sesnum;
		cout << "Enter a number of session to sort through: ";
		while(!(cin >> sesnum))
		{
			clearbuf();
			input_error();
		}
		my_list* a = get_students_by_mark(output, sesnum, 5);
		if (a == NULL)
		{
			cout << "No A students found!" << endl;
		}
		else
		{
			cout << "A students:" << endl;
			print_list(a);
		}
		
		my_list* b = get_students_by_mark(output, sesnum, 4);
		if (b == NULL)
		{
			cout << "No B students found!" << endl;
		}
		else
		{
			cout << "B students:" << endl;
			print_list(b);
		}

		my_list* c = get_students_by_mark(output, sesnum, 3);
		if (c == NULL)
		{
			cout << "No C students found!" << endl;
		}
		else
		{
			cout << "C students:" << endl;
			print_list(c);
		}
	}
}
