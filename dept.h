#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#include "student.h"
#include "subject.h"

class Dept {
	vector<Student> std_list;

public:
	
	Dept();
	~Dept();



	void setStd(Subject sub, char(*sub_arr)[10], char(*info_arr)[10], int i);
	int searchStd(string name);
	void searchSid(int s_id);

	map<int, float> getGPA(int s_id);
	map<int, float> getMajorGPA(int s_id);
	void searchNrank();
	void printSubRank(map<int, float> rank_arr, int n);
	void showSemRank();
	void getTotalRank(map<int, float> gpa_1, map<int, float> gpa_2, map<int, float> m_gpa_1, map<int, float> m_gpa_2);
	void getTotalRank_1p(map<int, float> gpa_1, map<int, float> gpa_2, map<int, float> m_gpa_1, map<int, float> m_gpa_2, int s_id);

	void printGPA(map<int, float> rank, map<int, float> mRank);
	void printGPA_1p(map<int, float> rank, map<int, float> mRank, int s_id);
	void printSubName();
	void printGPA_(int s_id);
};
