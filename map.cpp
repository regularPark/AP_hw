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
	ofstream fout("student.txt");
	if (!fout) {
		cout << "파일 없음";
		return 0;
	}


	// 일단 학생 이름(15명)부터 받고, 과목명(10개)과 전공여부를 입력받음. 그 다음 15x10개의 성적 랜덤 생성.
	// 동명의 학생이 존재할수도 있기 때문에 학번을 넣는 것이 바람직하다.
	// 이름도 key/value 형식으로 받을 것인지 생각해야함.

	// 150x2 총 300개의 성적을 타이핑으로 입력하는 것은 낭비로 생각되어,
	// 성적은 난수 생성에 맡김.


	// 과목명 입력
	int num_lec_1;
	cout << "1학기 과목 개수 입력(10 이상) >> ";
	cin >> num_lec_1;


	map<string, bool> lec_arr; // 과목명을 담는 배열
	string lec_name;		// 과목명 입력
	bool isMajor;			// 전공 여부 입력
	for (int i = 0; i < num_lec_1; i++) {
		cout << "과목명 입력 >> ";
		cin >> lec_name;
		cout << "전공이면 1, 교양이면 0 입력 >> ";
		cin >> isMajor;
		lec_arr.insert(make_pair(lec_name, isMajor));
	}

	map<string, bool>::iterator it;

	for (it = lec_arr.begin(); it != lec_arr.end(); it++) {
		fout << it->first;
		if (it->second == true) {
			fout << " /M" << "\t";
		}
		else {
			fout << " /G" << "\t";
		}
	}
	fout << endl;


	srand(time(NULL));	// 난수 생성

	// 성적을 txt로 출력
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < num_lec_1; j++) {
			int rn = rand() % 51 + 50;	// 50~100점 사이에서 성적 랜덤 생성.
			fout << rn << "\t";
		}
		fout << endl;
	}


	fout << endl;

	// txt를 불러와서 성적에 대입하기


	fout.close();

	return 0;
}
