#pragma once
#include <string>
using namespace std;

class Subject {	// 과목 클래스에는 과목명과 점수가 입력됨.
	string name;
	int score;
	bool isMajor;
	float grade;
public:

	Subject();
	~Subject();

	void setSub(string name, int score, bool isMajor, float grade);
	bool isMajorChk(string name);
	int getScore() { return this->score; }
	float getGrade() { return this->grade; }
	bool isMjr() { return this->isMajor; }
	float setGrade(int score);
};
