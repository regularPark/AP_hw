#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "student.h"
#include "dept.h"
#include "subject.h"



int main() {	
	ifstream fin;
	int sem;


	while (true) {
		if (!fin) {
			cout << "에러발생" << endl;
		}
		cout << "몇 학기? ( 1 / 2 ) > ";
		cin >> sem;

		if (sem == 1) {
			fin.open("1st_semester.txt");
			break;
		}
		else if (sem == 2) {
			fin.open("2nd_semester.txt");
			break;
		}
		else {
			cout << "1 / 2 중에 성적을 확인하고 싶은 학기를 다시 입력해주세요 " << endl;
		}
	}

	cout << endl;

	Dept mme;
	Subject sub;
	
	int cnt = 0;
	char s_Arr[100];
	char sub_Arr[10][10];	// 과목명을 저장하는 배열
	char buf[100];	// 불러들인 라인을 임시저장하는 buffer.

	char i_Arr[100];
	char info_Arr[10][10]; // 이름과 ID, 점수를 불러들임. (초기화 필요)
	
	

	while (fin.getline(buf, 100)) {
		if (cnt == 0) {	// 불러들인 txt 파일의 첫 줄은 과목명을 표기한다.
			strcpy(s_Arr, buf);
			char* ptr = strtok(s_Arr, "\t");
			int i = 0;
			while (ptr != NULL) {
				strcpy(sub_Arr[i], ptr);
				ptr = strtok(NULL, "\t");
				i++;
			} //strtok 함수로 \t을 기준으로 문자열을 잘라내 배열에 저장한다.
			cout << buf << endl;
			cout << endl;
		}

		else {
			// 마찬가지로 2번째 줄의 문자열들을 잘라내어 배열에 넣음.
			strcpy(i_Arr, buf);
			char* ptr = strtok(i_Arr, "\t");
			int i = 0;
			while (ptr != NULL) {
				strcpy(info_Arr[i], ptr);
				ptr = strtok(NULL, "\t");
				i++;
			}

			// vector에 학생의 정보 클래스를 push back하기 위해 만든 함수
			mme.setStd(sub, sub_Arr, info_Arr, i);
			cout << buf << endl;
		}		
		cnt++;	// 학번과 라인 넘버가 같다.
	}
	

	fin.close();

	int select;
	string name;
	int n;

	
	cout << "\n\n----------하고자 하는 작업을 선택----------" << endl;
	cout << "1. 학생 1명의 등수 출력 / 전공 과목 등수 출력" << endl;
	cout << "2. 입력한 과목의 상위 n명 성명 출력 " << endl;
	cout << "3. 전체 등수 출력" << endl;
	cout << "4. 학기별 등수 출력" << endl;
	cout << "5. 학생 1명의 개별 과목 성적, 학기 평점, 총 평점 출력" << endl;
	cout << endl;
	cout << "실행하고자 하는 기능의 번호 입력(1 ~ 5 사이의 정수) > ";
	cin >> select;

	switch (select) {
	case 1:
		cout << "성적을 확인하고자 하는 학생의 이름 or 학번 or 이름&학번 모두를 입력 > ";
		cin >> name;
		mme.searchStd(name);
		break;
	case 2:
		cout << "n을 입력 > ";
		cin >> n;
		break;
	default:
		cout << "1 ~ 5 사이의 정수를 입력해주세요" << endl;
	}



}