#include <iostream>
#include "students.h"
#include "validation.h"

string student::get_full_name() const
{
	return fio.get_data();
}

void student::set_full_name(string last_name, string first_name, string middle_name)
{
	fio.set_data(last_name, first_name, middle_name);
}

string student::get_birthdate()
{
	string output = to_string(birthdate[0]) + '.' + to_string(birthdate[1]) + '.' + to_string(birthdate[2]);
	return output;
}

unsigned short student::get_birth_year()
{
	return birthdate[2];
}

void student::set_birthdate(unsigned short day, unsigned short month, unsigned short year)
{
	birthdate[0] = day;
	birthdate[1] = month;
	birthdate[2] = year;
}

char student::get_sex() const
{
	return sex;
}

void student::set_sex(char input)
{
	sex = input;
}

unsigned short student::get_enroll_year() const
{
	return enroll_year;
}

void student::set_enroll_year(unsigned short input)
{
	enroll_year = input;
}

string student::get_fac() const
{
	return fac.get_data();
}

void student::set_fac(string input)
{
	fac.set_data(input);
}

string student::get_kaf() const
{
	return kaf.get_data();
}

void student::set_kaf(string input)
{
	kaf.set_data(input);
}

string student::get_group() const
{
	return gr.get_data();
}

void student::set_group(string input)
{
	gr.set_data(input);
}

string student::get_id() const
{
	return zach.get_data();
}

void student::set_id(string input)
{
	zach.set_data(input);
}

unsigned short student::get_n() const
{
	return n_sessions;
}

session* student::get_marks()
{
	return marks;
}

void student::set_marks(session input[])
{
	for(int i = 0; i < n_sessions; i++)
	{
		marks[i].set_n(input[i].get_n());
		marks[i] = input[i];
	}
}

session student::get_nth_session(unsigned short x)
{
	return marks[x-1];
}

void student::print()
{
	cout << "Full name: " << get_full_name() << endl;
	cout << "Date of birth: " << get_birthdate() << endl;
	cout << "Sex: " << get_sex() << endl;
	cout << "Enrolled in: " << get_enroll_year() << endl;
	cout << "Faculty: " << get_fac() << endl;
	cout << "Department: " << get_kaf() << endl;
	cout << "Group: " << get_group() << endl;
	cout << "ID: " << get_id() << endl;
	cout << "Sessions passed: " << get_n() << endl;
	for (int i = 0; i < n_sessions; i++)
	{
		cout << "Session №" << i+1 << ":\n";
		marks[i].print();
		cout << "Average score: " << marks[i].get_avrg() << endl;
	}
}

student edit(student input)
{
	int n;
	cout << "What would you like to edit?" << endl;
	while(true)
	{	
		cout << "\t1. Name" << endl;
		cout << "\t2. Date of birth" << endl;
		cout << "\t3. Sex" << endl;
		cout << "\t4. Year of enroll" << endl;
		cout << "\t5. Faculty" << endl;
		cout << "\t6. Department" << endl;
		cout << "\t7. Group" << endl;
		cout << "\t8. Marks" << endl;
		cout << "\t0. Exit edit mode" << endl;
		cin >> n;
		if (n == 1)
		{
			string new_name[3];
			cout << "Enter last name: ";
			cin.ignore();
			getline(cin, new_name[0]);
			cout << "Enter first name: ";
			cin.ignore();
			getline(cin, new_name[1]);
			cout << "Enter middle name: ";
			cin.ignore();
			getline(cin, new_name[2]);
			input.set_full_name(new_name[0], new_name[1], new_name[2]);
			cout << "Name edited!" << endl;
		}
		if (n == 2)
		{
			unsigned short new_date[3];
			cout << "Enter date of birth\n";
			do
			{
				cout << "Day: ";
				while(!(cin >> new_date[0]))
				{
					clearbuf();
					input_error();
				}
				cout << "Month: ";
				while(!(cin >> new_date[1]))
				{
					clearbuf();
					input_error();
				}
				cout << "Year: ";
				while(!(cin >> new_date[2]))
				{
					clearbuf();
					input_error();
				}
			}while(check_birthdate(new_date[0], new_date[1], new_date[2]) != true);	
			
			for(int i = 0; i < 3; i++)
			{
				input.birthdate[i] = new_date[i];
			}
		}
		if (n == 3)
		{
			char new_s;
			do
			{
				cout << "Enter sex: ";
				cin >> new_s;
				clearbuf();

			}while(check_sex(new_s) != true);
			input.sex = new_s;
		}
		if (n == 4)
		{
			unsigned short new_enr;
			do
			{
				cout << "Enter enroll year: ";
				while(!(cin >> new_enr))
				{
					clearbuf();
					input_error();
				}
			}while(check_enroll_year(new_enr) != true);
			input.enroll_year = new_enr;
		}
		if (n == 5)
		{
			string new_fac;
			cin.ignore();
			getline(cin, new_fac);
			input.set_fac(new_fac);
		}
		if (n == 6)
		{
			string new_kaf;
			cin.ignore();
			getline(cin, new_kaf);
			input.set_kaf(new_kaf);
		}
		if (n == 7)
		{
			string new_group;
			cin.ignore();
			getline(cin, new_group);
			input.set_group(new_group);
		}
		if (n == 8)
		{
			int choice;
			cout << "What would you like to do?" << endl;
			cout << "1. Add new session" << endl;
			cout << "2. Edit existing session" << endl;
			while(!(cin >> choice))
			{
				clearbuf();
				input_error();
			}
			if (choice == 1)
			{
				if (input.get_n() < 9)
				{
					int newsubj;
					cout << "Enter number of subjects in new session: ";
					while(!(cin >> newsubj))
					{
						clearbuf();
						input_error();
					}
					if (newsubj >= 1 && newsubj <= 10)
					{
						input.n_sessions++;
						for (int i = 0; i < newsubj; i++)
						{
							subject tmp;
							string s;
							unsigned short x;
							cout << "Enter name of the subject: ";
							cin.ignore();
							getline(cin, s);
							do
							{	
								cout << "Enter mark: ";
								while(!(cin >> x))
								{
									clearbuf();
									input_error();
								}
							}while(check_mark(x) != true);
							tmp.name = s;
							tmp.mark = x;
							input.marks[input.n_sessions-1].add_subject(tmp);
						}
					}
					else
					{
						cout << "Session can't have more than 10 subjects!" << endl;
					}
				}
				else
				{
					cout << "Can't add more than 9 sessions!" << endl;
				}
			}
			if (choice == 2)
			{
				unsigned short x;
				cout << "Enter number of a session you want to edit(1-" << input.n_sessions << "): ";
				session* cur;
				while (!(cin >> x))
				{
					clearbuf();
					input_error();
				}
				if (x <= input.n_sessions)
				{
					cur = &input.marks[x-1];
					cout << "Session №" << x << ":\n";
					cur->print();
					while(true)
					{
						unsigned short seschoice;
						cout << "1. Add subject" << endl;
						cout << "2. Delete subject" << endl;
						cout << "3. Edit mark for existing subject" << endl;
						cout << "0. Quit session" << endl;
						while(!(cin >> seschoice))
						{
							clearbuf();
							input_error();
						}
						if (seschoice == 1)
						{
							subject tmp;
							string s;
							unsigned short m;
							cout << "Enter name of the subject: ";
							cin.ignore();
							getline(cin, s);
							do
							{	
								cout << "Enter mark: ";
								while(!(cin >> x))
								{
									clearbuf();
									input_error();
								}
							}while(check_mark(x) != true);
							tmp.name = s;
							tmp.mark = x;
							cur->add_subject(tmp);
						}
						if (seschoice == 2)
						{
							string del_s;
							cout << "Enter name of the subject: ";
							cin.ignore();
							getline(cin, del_s);
							cur->delete_subject(del_s);
						}
						if (seschoice == 3)
						{
							string edit_sub;
							cout << "Enter name of the subject: ";
							cin.ignore();
							getline(cin, edit_sub);
							unsigned short new_mark;
							cout << "Enter mark: ";
							do
							{
								while(!(cin >> new_mark))
								{
									clearbuf();
									input_error();
								}
							}while(check_mark(new_mark) != true);
							cur->edit_subject(edit_sub, new_mark);
						}	
						if (seschoice == 0)
						{
							break;
						}
					}
				}
				else
				{
					cout << "Session not found!" << endl;
				}
			}	
		}
		if (n == 0)
		{
			break;
		}
	}
	student output = input;
	return output;
}
