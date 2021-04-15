#pragma once
#include <string>
#include <iostream>

using namespace std;

class data_string
{
	private:
		string data;
	public:
		virtual void set_data(string input)
		{
			data = input;
		}
		virtual string get_data() const
		{
			return data;
		}
};

class faculty: public data_string 
{
	string data;
};

class department: public data_string 
{
	string data;
};

class group: public data_string 
{
	string data;
};

class id: public data_string 
{
	string data;
};

class fullname: public data_string
{
	string name[3];
	public:
		void set_data(string last_name, string first_name, string middle_name)
		{
			name[0] = last_name;
			name[1] = first_name;
			name[2] = middle_name;
		}
		string get_data() const
		{
			string s = name[0] + ' ' + name[1] + ' ' + name[2];
			return s;
		}
		string get_i_data(int i) const
		{
			return name[i];
		}
};

struct subject
{
	string name;
	unsigned short mark;

	subject& operator =(const subject& right)
	{
		if (this == &right)
		{
			return *this;
		}
		this->name = right.name;
		this->mark = right.mark;
		return *this;
	}
};

typedef struct subject subject;

class session
{
	subject subjects[10];
	unsigned short n;
	public:
		
		void set_n(unsigned short x)
		{
			n = x;
		}
	
		void set(subject input[])
		{
			for(int i = 0; i < n; i++)
			{
				subjects[i] = input[i];
			}
		}

		int get_n() const
		{
			return n;
		}

		subject* get()
		{
			return subjects;
		}

		double get_avrg()
		{
			double x = 0;
			for (int i = 0; i < n; i++)
			{
				x += subjects[i].mark;
			}
			x /= n;
			return x;
		}

		void print()
		{
			for (int i = 0; i < n; i++)
			{
				cout << subjects[i].name << ": " << subjects[i].mark << endl;
			}
		}

		void add_subject(subject input)
		{
			subjects[n] = input;
			n++;
		}

		void delete_subject(string input)
		{
			int i;
			for (i = 0; i < n; i++)
			{
				if (subjects[i].name ==	input)
				{
					break;
				}
			}
			for (; i < n-1; i++)
			{
				subjects[i] = subjects[i+1];
			}
			n--;
		}
		
		void edit_subject(string input, int new_mark)
		{
			for (int i = 0; i < n; i++)
			{
				if (input == subjects[i].name)
				{
					subjects[i].mark = new_mark;
				}
			}
		}

		session& operator=(const session& right)
		{
			if (this == &right)
			{
				return *this;
			}
			this->n = right.n;
			for (int i = 0; i < n; i++)
			{
				this->subjects[i] = right.subjects[i];
			}
			return *this;
		}
};

class student
{
	private:
		fullname fio;
		unsigned short birthdate[3];
		char sex;
		unsigned short enroll_year;
		faculty fac;
		department kaf;
		group gr;
		id zach;
		unsigned short n_sessions;
		session marks[9];
		friend student edit(student input);
	public:
		student(){;}
		student(unsigned short x)
		{
			n_sessions = x;
		}
		~student()
		{
			n_sessions = 0;
		}	
		string get_full_name() const;
		string get_name(int i)
		{
			return fio.get_i_data(i);
		}
		void set_full_name(string last_name, string first_name, string middle_name);
		
		string get_birthdate();
		unsigned short get_birth_year();
		void set_birthdate(unsigned short day, unsigned short month, unsigned short year);
		
		char get_sex() const;
		void set_sex(char input);
		
		unsigned short get_enroll_year() const;
		void set_enroll_year(unsigned short input);
		
		string get_fac() const;
		void set_fac(string input);
		
		string get_kaf() const;
		void set_kaf(string input);
		
		string get_group() const;
		void set_group(string input);
		
		string get_id() const;
		void set_id(string input);
		
		unsigned short get_n() const;
		void set_n(unsigned short x)
		{
			n_sessions = x;
		}
		session* get_marks();
		void set_marks(session input[]);
		session get_nth_session(unsigned short x);

		void print();

		student& operator=(const student& right)
		{
			if (this == &right)
			{
				return *this;
			}
			this->set_full_name(right.fio.get_i_data(0), right.fio.get_i_data(1), right.fio.get_i_data(2));
			this->set_birthdate(right.birthdate[0], right.birthdate[1], right.birthdate[2]);
			sex = right.get_sex();
			enroll_year = right.enroll_year;
			this->set_fac(right.get_fac());
			this->set_kaf(right.get_kaf());
			this->set_group(right.get_group());
			this->set_id(right.get_id());
			n_sessions = right.n_sessions;
			for(int i = 0; i < n_sessions; i++)
			{
				marks[i].set_n(right.marks[i].get_n());
				marks[i] = right.marks[i];	
			}
			return *this;
		}
};
