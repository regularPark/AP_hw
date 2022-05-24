#include "student.h"

Student::Student() { this->name = "Nobody"; }

Student::~Student() {};

void Student::setNameId(string name, int id) {
	this->name = name;
	this->id = id;
}

void Student::addSub(Subject sub) {
	sub_list.push_back(sub);
}

string Student::getName() {
	return this->name;
}

int Student::getID() {
	return this->id;
}

