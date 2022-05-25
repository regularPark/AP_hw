#include "subject.h"

Subject::Subject() { this->name = "Nothing"; }
Subject::~Subject() {};

void Subject::setSub(string name, int score, bool isMajor, float grade) {
	this->name = name;
	this->score = score;
	this->isMajor = isMajor;
	this->grade = grade;
}
bool Subject::isMajorChk(string name) {
	if (name[name.length() - 1] == 'm') {
		return true;
	}
	return false;
}

float Subject::setGrade(int score) {
	if (score > 95 && score <= 100) {
		return 4.5;
	}
	else if (score > 90 && score <= 95) {
		return 4.0;
	}
	else if (score > 85 && score <= 90) {
		return 3.5;
	}
	else if (score > 80 && score <= 85) {
		return 3.0;
	}
	else if (score > 75 && score <= 80) {
		return 2.5;
	}
	else if (score > 70 && score <= 75) {
		return 2.0;
	}
	else if (score > 65 && score <= 70) {
		return 1.5;
	}
	else if (score > 60 && score <= 65) {
		return 1.0;
	}
	else if (score > 0 && score <= 60) {
		return 0.0;
	}
}
