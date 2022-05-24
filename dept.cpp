#include "dept.h"

Dept::Dept() {};
Dept::~Dept() {};

void Dept::setStd(Subject sub, char sub_arr[][10], char info_arr[][10], int i) {
	// 학생의 이름과 학번은 파일의 1~2번째 열에 존재.
	Student std;
	std.setNameId(info_arr[0], stoi(info_arr[1]));

	// 학생의 점수가 과목과 "같은 열"에 기입되는 것이 일반적이기 때문에
	// Table 형식의 텍스트 파일을 읽어들이는 방식을 선택한 이 프로그램에서는
	// for문을 이용한 성적 입력 방법이 가장 바람직한 것으로 생각됨.
	for (int j = 2; j < i; j++) {
		sub.setSub(sub_arr[j], stoi(info_arr[j]), sub.isMajorChk(sub_arr[j]));
		std.addSub(sub);
	}
	std_list.push_back(std);
}

void Dept::searchStd(string n) {
	int size = std_list.size();
	int target;
	for (int i = 0; i < size; i++) {
		if (std_list[i].getName() == n) {
			target = i;
			cout << std_list[i].getName() << " " << std_list[i].getID() << endl;
			getSubRank_1p(std_list[i].getID());
		}
	}
}


// 특정 학생의 과목별 등수
void Dept::getSubRank_1p(int s_id) {
	vector<int> rank;
	int size = std_list.size();	
	int sub_size = std_list[s_id].sub_list.size();
	for (int i = 0; i < size; i++) { // 학생 전부 이거 아님 축소할것. 과목 전부 다 순위 매길 필요 없음. 내일 이어서..
		for (int j = 0; j < sub_size; j++) {
			rank.push_back(std_list[i].sub_list[j].getScore());
		}
	}

	sort(rank.begin(), rank.end());
	find(rank.begin(), rank.end(), )

}

