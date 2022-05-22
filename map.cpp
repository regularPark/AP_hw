#include <iostream>
#include <string>
#include <vector>
using namespace std;


// Student가 들어갈 Dept를 만들고 연결리스트로 만듦.

class Student {
private:
	string name;
	vector<string> lecture;
	vector<int> score;
	vector<bool> isMajor;

public:
	Student(string _name) :	name(_name) {}
	Student() :	name("default") {}

	void setName(string name) {
		this->name = name;
	}
	
	void print() {
		cout << name << endl;
	}

	void addGrade(string _lecture, int score_, bool isMajor_) {
		lecture.push_back(_lecture);
		score.push_back(score_);
		isMajor.push_back(isMajor_);
	}

	void printGrades() {
		int size = lecture.size();
		for (int i = 0; i < size; i++) {
			cout << lecture[i] << ' ' << score[i];
			if (isMajor[i])
				cout << " Major" << endl;
			else
				cout << " GE" << endl;
		}
		printAvg();
	}

	void printAvg() {
		int len = score.size();
		float sum = 0, avg;
		for (int i = 0; i < len; i++) {
			sum += score[i];
		}
		avg = sum / len;
		cout << "평균 : " << avg;
	}
};


// 배열의 형태임 결국, major와 score가 같이 들어갔는데? major가 재정렬된다면?
// 다른 과목을 가리키게 될 수도 있다.
// 1. 과목명으로 전공 비전공을 판단하자. + key - 전공명 / value - 점수

int main() {
	Student Park("Park");
	Park.print();
	Park.addGrade("DS", 90, true);
	Park.addGrade("Meditation", 70, false);
	Park.printGrades();
	cout << "\n\n";

	Student Kim;
	cout << "\n";
	Kim.setName("Ron");
	Kim.print();
	Kim.addGrade("OS", 85, true);
	Kim.addGrade("CV", 70, true);
	Kim.addGrade("Python", 95, true);
	Kim.printGrades();

	return 0;
}