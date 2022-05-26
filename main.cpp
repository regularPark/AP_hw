#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "student.h"
#include "dept.h"
#include "subject.h"
#include "fileIn.h"



int main() {
	
	while (true) {
		Dept mme, m1, m2, mt;

		Subject sub;
		fileIn hd;

		int select;
		string name;
		int n;
		string sub_name;

		cout << "\n\n----------하고자 하는 작업을 선택----------" << endl;
		cout << "1. 학생 1명의 등수 출력 / 전공 과목 등수 출력" << endl;
		cout << "2. 입력한 과목의 상위 n명 성명 출력 " << endl;
		cout << "3. 전체 등수 출력" << endl;
		cout << "4. 학기별 등수 출력" << endl;
		cout << "5. 학생 1명의 개별 과목 성적, 학기 평점, 총 평점 출력" << endl;
		cout << "6. 종료" << endl;
		cout << endl;
		cout << "실행하고자 하는 기능의 번호 입력(1 ~ 5 사이의 정수) > ";
		cin >> select;

		switch (select) {

		case 1:
			cout << endl;
			// 예외 : 이름이 없을 떄, 동명의 학생이 있을때-> 학번으로 검색하도록 유도. 전체 평점 같으면, 전공 평점 높은 사람 등수가 높음.
			// 학기에 이름을 입력해버렸을 때
			mme = hd.fileRead(hd.sem_in(), mme, sub);
			cout << "성적을 확인하고자 하는 학생의 이름 입력 > ";
			cin >> name;
			mme.searchStd(name);
			break;

		case 2:
			cout << endl;

			// 예외 처리 : 과목 없을 때, 등수가 0~15 사이의 정수가 아닐때  + 과목명 알려주기
			mme = hd.fileRead(hd.sem_in(), mme, sub);
			cout << "과목명 : ";
			cout << "과목 이름을 입력 > ";
			cin >> sub_name;
			cout << "알고 싶은 등수를 입력 > ";
			cin >> n;
			mme.searchNrank(sub_name, n);
			break;

		case 3:
			cout << endl;
			m1 = hd.fileRead(hd.firstSem(), m1, sub);	// 1학기 성적 Dept
			m2 = hd.fileRead(hd.secondSem(), m2, sub);	// 2학기 성적 Dept

			cout << "--------전체 학기 석차--------" << endl;

			mt = hd.fileRead(hd.firstSem(), mt, sub);
			mt.getTotalRank(m1.getGPA(1), m2.getGPA(1), m1.getMajorGPA(1), m2.getMajorGPA(1));
			
			break;

		case 4:
			mme = hd.fileRead(hd.sem_in(), mme, sub);

			cout << hd.getSem() << "학기 성적" << endl;
			mme.showSemRank();

			break;

		case 5:
			cout << "학생의 이름을 입력 > ";
			cin >> name;

		case 6:
			exit(1);

		default:
			cout << "1 ~ 6 사이의 정수를 입력해주세요" << endl;
			break;
		}
	}
}
