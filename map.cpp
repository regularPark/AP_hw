#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
using namespace std;


// Student가 들어갈 Dept를 만들고 연결리스트로 만듦.

class Student {
private:
	string name;
	vector<string> lecture;	// txt파일 첫째줄에서 받아감.
	vector<int> score;
	vector<bool> isMajor;

public:
	Student(string _name) : name(_name) {}
	Student() : name("default") {}

	void setName(string name) {
		this->name = name;
	}

	void print() {
		cout << name << endl;
	}

	void addGrade(int score_, bool isMajor_) {
		score.push_back(score_);
		isMajor.push_back(isMajor_);
	}

	void addLecture(string lec) {
		lecture.push_back(lec);
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



int main() {
	// 일단 학생 이름(15명)부터 받고, 과목명(10개)과 전공여부를 입력받음. 그 다음 15x10개의 성적 랜덤 생성.

	// 150x2 총 300개의 성적을 타이핑으로 입력하는 것은 낭비로 생각되어,
	// 성적은 난수 생성에 맡김.
	
	
	// 과목명 입력
	int num_lec_1;
	cout << "1학기 과목 개수 입력(10 이상) >> ";
	cin >> num_lec_1;
		
	for (int i = 0; i < num_lec_1; i++) {

	}


	// txt 파일 출력
	ofstream fout("student.txt");
	if (!fout) {
		cout << "파일 없음";
		return 0;
	}	
	
	srand(time(NULL));
	
	// 성적을 txt로 출력한 다음
	fout << "Random Num" << endl;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < num_lec_1; j++) {
			int rn = rand() % 51 + 50;
			fout << rn << "\t";
		}
		fout << endl;
	}

	fout << false;

	fout << endl;

	// txt를 불러와서 성적에 대입하기
	

	fout.close();

	return 0;
}
