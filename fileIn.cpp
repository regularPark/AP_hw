#include "fileIn.h"


ifstream fileIn::sem_in() {
	ifstream fin;

	while (sem != 1 || sem != 2) {
		string sem;

		if (!fin) {
			cout << "에러발생" << endl;
		}

		cout << "학기 입력 ( 1 / 2 ) > ";
		cin >> sem;

		if (sem == "1") {
			setSem(1);
			fin.open("1st_semester.txt");
			break;
		}
		else if (sem == "2") {
			setSem(2);
			fin.open("2nd_semester.txt");
			break;
		}
	

		cout << "확인하고자 하는 학기를 정확히 입력해주세요.\n";
	}

	cout << endl;
	
	return fin;
}

ifstream fileIn::firstSem() {
	ifstream f1;
	f1.open("1st_semester.txt");
	return f1;
}

ifstream fileIn::secondSem() {
	ifstream f2;
	f2.open("2nd_semester.txt");
	return f2;
}

Dept fileIn::fileRead(ifstream fin, Dept mme, Subject sub) {

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
		}
		cnt++;	// 학번과 라인 넘버가 같다.
	}

	fin.close();

	return mme;
}
