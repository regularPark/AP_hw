#pragma once
#include <string>
using namespace std;

class Subject {	// 과목 클래스에는 과목명과 점수가 입력됨.
	string name;
	int score;
	bool isMajor;
public:
	Subject();
	~Subject();

	void setSub(string name, int score, bool isMajor);
	bool isMajorChk(string name);
	int getScore() { return this->score; }
	bool isMjr() { return this->isMajor; }
};