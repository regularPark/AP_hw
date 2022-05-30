#pragma once
#include <string>
using namespace std;



class Subject {	// 과목 클래스에는 과목명과 점수가 입력됨.
	string name;
	int score;
	bool isMajor;
	float grade;
	string GPA;
public:

	Subject();
	~Subject();

	void setSub(string name, int score, bool isMajor, float grade, string GPA);
	bool isMajorChk(string name);
	int getScore() { return this->score; }
	string getSubName() { return this->name; }
	float getGrade() { return this->grade; }
	bool isMjr() { return this->isMajor; }
	string getGPA() { return this->GPA; }
	float setGrade(int score);

	string setGPAgrade(int score);
};
