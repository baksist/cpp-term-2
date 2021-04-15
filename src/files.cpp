#include <iostream>
#include <fstream>
#include "files.h"
#include "crypto.h"

using namespace std;

void save_data(my_list* lst)
{
	my_list* cur = lst;
	ofstream fout;
	string filename;
	string password;

	cout << "Enter name of the file: ";
	cin >> filename;
	cout << "Enter password: ";
	cin >> password;

	fout.open(filename);
	do
	{
		student tmp = cur->val;
		fout << encrypt(tmp.get_name(0), password) << endl;
		fout << encrypt(tmp.get_name(1), password) << endl;
		fout << encrypt(tmp.get_name(2), password) << endl;
		fout << encrypt(tmp.get_birthdate(), password) << endl;
		fout << encrypt(string(1, tmp.get_sex()), password) << endl;
		fout << encrypt(to_string(tmp.get_enroll_year()), password) << endl;
		fout << encrypt(tmp.get_fac(), password) << endl;
		fout << encrypt(tmp.get_kaf(), password) << endl;
		fout << encrypt(tmp.get_group(), password) << endl;
		fout << encrypt(tmp.get_id(), password) << endl;
		fout << encrypt(to_string(tmp.get_n()), password) << endl;
		for(int i = 0; i < tmp.get_n(); i++)
		{
			session tmp_ses = tmp.get_nth_session(i+1);
			subject* tmp_subj = tmp_ses.get();
			for(int j = 0; j < tmp_ses.get_n(); j++)
			{
				fout << encrypt(((tmp_subj + j)->name + ": " + to_string((tmp_subj + j)->mark)), password) << endl;
			}
			fout << encrypt("END OF SESSION", password) << endl;
		}
		fout << encrypt("END OF ENTRY", password) << endl;
		cur = cur->nxt;
	}while(cur != lst);
	fout << encrypt("END OF FILE", password) << endl;

	fout.close();
}

my_list* read_from_file(my_list* lst)
{
	lst = init_list(student(1));
	my_list* root = lst;
	ifstream fin;
	string filename;
	string password;
	string s = "";

	cout << "Enter name of the file: ";
	cin >> filename;
	cout << "Enter password: ";
	cin >> password;

	fin.open(filename);
	
	while(true)
	{
		student x;
		
		getline(fin, s);
		s = decrypt(s, password);
		if (s == "END OF FILE")
		{
			break;
		}
		
		string name[3];
		name[0] = s;
		
		getline(fin, s);
		s = decrypt(s, password);
		name[1] = s;
		
		getline(fin, s);
		s = decrypt(s, password);
		name[2] = s;
		
		x.set_full_name(name[0], name[1], name[2]);
		
		getline(fin, s);
		s = decrypt(s, password);
		unsigned short date[3];
			int cur, prev = 0;
			cur = s.find('.');
			date[0] = stoi(s.substr(prev, cur - prev));
			prev = cur + 1;
			cur = s.find('.', prev);
			date[1] = stoi(s.substr(prev, cur - prev));
			prev = cur + 1;
			cur = s.find('.', prev);
			date[2] = stoi(s.substr(prev, cur - prev));
		x.set_birthdate(date[0], date[1], date[2]);
		
		getline(fin, s);
		s = decrypt(s, password);
		if(s == "M")
		{
			x.set_sex('M');
		}
		else
		{
			x.set_sex('F');
		}

		getline(fin, s);
		s = decrypt(s, password);
		x.set_enroll_year(stoi(s));
		
		getline(fin, s);
		s = decrypt(s, password);
		x.set_fac(s);
		
		getline(fin, s);
		s = decrypt(s, password);
		x.set_kaf(s);
		
		getline(fin, s);
		s = decrypt(s, password);
		x.set_group(s);
		
		getline(fin, s);
		s = decrypt(s, password);
		x.set_id(s);
		
		getline(fin, s);
		s = decrypt(s, password);
		unsigned short n = stoi(s);
		x.set_n(n);
		
		session mrks[n];
		for (int i = 0; i < n; i++)
		{
			getline(fin, s);
			s = decrypt(s, password);
			mrks[i].set_n(0);
			while(s != "END OF SESSION")
			{
				subject tmp;
				tmp.name = s.substr(0, s.find(':'));
				tmp.mark = stoi(s.substr(s.find(':') + 1, string::npos));
				mrks[i].add_subject(tmp);
				getline(fin, s);
				s = decrypt(s, password); 
			}
		}
		x.set_marks(mrks);
		getline(fin, s);
		s = decrypt(s, password);
		lst = add_element(lst, x);
	}
	fin.close();
	lst = delete_element(root);
	return lst;
}
