#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
using namespace std;

#include "dept.h"
#include "subject.h"

class fileIn {
	int sem;
public:
	fileIn() {};
	~fileIn() {};
	void setSem(int sem) { this->sem = sem; }
	int getSem() { return this->sem; }
	
	ifstream firstSem();
	ifstream secondSem();

	ifstream sem_in();

	Dept fileRead(ifstream fin, Dept mme, Subject sub);
};