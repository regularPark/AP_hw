#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "student.h"
#include "subject.h"


class Dept {
	vector<Student> std_list;

public:

	Dept();
	~Dept();

	void setStd(Subject sub, char(*sub_arr)[10], char(*info_arr)[10], int i);
	void searchStd(string name);
	void searchStd(int id);
	void searchStd(string name, int id);

	void getSubRank_1p(int s_id);


};