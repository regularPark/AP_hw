#pragma once
#include <string>
using namespace std;

class Subject {	// ���� Ŭ�������� ������ ������ �Էµ�.
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