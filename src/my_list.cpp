#include <iostream>
#include "my_list.h"

my_list* init_list(student x)
{
	my_list* lst;
	lst = new my_list;

	lst->val = x;
	lst->prv = lst;
	lst->nxt = lst;

	return lst;
}

my_list* add_element(my_list* lst, student x)
{
	my_list* tmp;
	my_list* p;

	tmp = new my_list;
	p = lst->nxt;
	lst->nxt = tmp;

	tmp->val = x;
	tmp->nxt = p;
	tmp->prv = lst;

	p->prv = tmp;
	return tmp;
}

my_list* delete_element(my_list* lst)
{
	my_list *prev, *next;
	prev = lst->prv;
	next = lst->nxt;
	prev->nxt = next;
	next->prv = prev;
	delete lst;
	return prev;
}

my_list* delete_list(my_list* lst)
{
	my_list* cur = lst;
	my_list* fin = lst->prv;
	do
	{
		my_list* tmp = cur->nxt;
		delete cur;
		cur = tmp;
	}while(cur != fin);
	return NULL;
}

my_list* find_element_by_id(my_list* lst, string input)
{
	my_list* cur;
	cur = lst;
	do
	{
		if (cur->val.get_id() == input)
		{
			return cur;
		}
		cur = cur->nxt;
	}while(cur != lst);
	return NULL;
}

my_list* get_students_by_year(my_list* lst, unsigned short start, unsigned short end)
{
	my_list* cur = lst;
	my_list* res = init_list(student(1));
	my_list* root = res;
	int x;
	bool flag = false;
	do
	{
		x = cur->val.get_birth_year();
		if(x >= start && x <= end)
		{
			res = add_element(res, cur->val);
			flag = true;
		}
		cur = cur->nxt;
	}while(cur != lst);
	if(flag)
	{
		res = delete_element(root);
		return res;
	}
	else
	{
		return NULL;
	}
}

my_list* get_students_by_mark(my_list* lst, unsigned short ses, unsigned short mark)
{
	my_list* cur = lst;
	my_list* res = init_list(student(1));
	my_list* root = res;
	bool flag = false;
	do
	{
		if(cur->val.get_n() >= ses)
		{
			session tmp;
		        tmp = cur->val.get_nth_session(ses);
			if (tmp.get_avrg() >= (mark-0.5) && tmp.get_avrg() < (mark+0.5))
			{
				res = add_element(res, cur->val);
				flag = true;
			}
		}
		cur = cur->nxt;
	}while(cur != lst);
	if (flag)
	{
		res = delete_element(root);
		return res;
	}
	else
	{
		return NULL;
	}
}

void print_list(my_list* lst)
{
	my_list* cur;
	cur = lst;
	do
	{
		cur->val.print();
		cout << "=====================END OF ENTRY=====================" << endl;
		cur = cur->nxt;
	}while(cur != lst);
}
