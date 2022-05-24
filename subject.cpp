#include "subject.h"

Subject::Subject() { this->name = "Nothing"; }
Subject::~Subject() {};

void Subject::setSub(string name, int score, bool isMajor) {
	this->name = name;
	this->score = score;
	this->isMajor = isMajor;
}
bool Subject::isMajorChk(string name) {
	if (name[name.length() - 1] == 'm') {
		return true;
	}
	return false;
}