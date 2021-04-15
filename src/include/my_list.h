#pragma once
#include "students.h"

typedef struct my_list my_list;

struct my_list
{
	struct my_list* nxt;
	student val;
	struct my_list* prv;
};

my_list* init_list(student x);
my_list* add_element(my_list* lst, student x);
my_list* delete_element(my_list* lst);
my_list* delete_list(my_list* lst);
my_list* find_element_by_id(my_list* lst, string input);
my_list* get_students_by_year(my_list* lst, unsigned short start, unsigned short end);
my_list* get_students_by_mark(my_list* lst, unsigned short ses, unsigned short mark);
void print_list(my_list* lst);
