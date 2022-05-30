#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>
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
		cout << "실행하고자 하는 기능의 번호 입력(1 ~ 6 사이의 정수) > ";
		cin >> select;

		switch (select) {

		case 1:
			cout << endl;
			// 예외 : 이름이 없을 떄, 동명의 학생이 있을때-> 학번으로 검색하도록 유도. 전체 평점 같으면, 전공 평점 높은 사람 등수가 높음.
			// 학기에 이름을 입력해버렸을 때
			mme = hd.fileRead(hd.sem_in(), mme, sub);
			
			
			mme.searchStd();
			break;

		case 2:
			cout << endl;

			// 예외 처리 : 과목 없을 때, 등수가 0~15 사이의 정수가 아닐때  + 과목명 알려주기
			mme = hd.fileRead(hd.sem_in(), mme, sub);
			
			cout << "검색할 수 있는 과목명 : ";

			mme.searchNrank();	// 과목별 등수를 구하는 함수
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
			int s_id;

			cout << endl;
			m1 = hd.fileRead(hd.firstSem(), m1, sub);	// 1학기 성적 배열
			m2 = hd.fileRead(hd.secondSem(), m2, sub);	// 2학기 성적 배열

			mt = hd.fileRead(hd.firstSem(), mt, sub);	// 1~2학기 모든 성적을 담을 클래스
			
			

			cout << endl;
			// 1학기 성적 출력
			s_id = m1.searchStd(); // 이름 오타 난 다음 학번으로 찾을 때 int 값 넘어오는게 이상하다!...
			cout << "----------------1학기 성적----------------" << endl;

			// 2학기 성적 출력
			// 첫번째에서 출력과 동시에 int를 리턴해서 동명이인의 경우 학번으로 바로 2학기 성적을 확인할수있도록함.
			m2.searchSid(s_id);
			cout << "----------------2학기 성적----------------\n" << endl;

			// 개별 과목 성적
			// 1학기 과목이름
			cout << endl;
			m1.printSubName();
			m1.printGPA_(s_id);
			cout << endl;

			m2.printSubName();
			m2.printGPA_(s_id);
			cout << "--------------------------------전체 성적--------------------------------\n";
			cout << endl;

			// 전체 성적 출력

			mt.getTotalRank_1p(m1.getGPA(1), m2.getGPA(1), m1.getMajorGPA(1), m2.getMajorGPA(1), s_id);

			break;
		case 6:
			exit(1);

		default:
			cout << "1 ~ 6 사이의 정수를 입력해주세요" << endl;
			break;
		}
	}
}
