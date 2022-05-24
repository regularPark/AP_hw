#pragma once
#include <string>
#include <vector>
using namespace std;

#include "subject.h"

class Student {
	string name;
	int id;
public:
	vector<Subject> sub_list;

	Student();
	~Student();

	void setNameId(string name, int id);
	void addSub(Subject sub);
	string getName();
	int getID();
};