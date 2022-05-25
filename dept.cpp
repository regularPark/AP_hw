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
		sub.setSub(sub_arr[j], stoi(info_arr[j]), sub.isMajorChk(sub_arr[j]), sub.setGrade(stoi(info_arr[j])));
		std.addSub(sub);
	}
	std_list.push_back(std);
}

// 특정 학생의 평점을 구하는 함수
void Dept::searchStd(string n) {
	int size = std_list.size();
	int target;

	// 이름으로 학생을 찾기
	for (int i = 0; i < size; i++) {
		if (std_list[i].getName() == n) {
			target = i;
			cout << std_list[i].getName() << " " << std_list[i].getID() << endl;
			
			printGPA_1p(getGPA(i+1), i+1); // 평점을 구하는 함수
		}
	}
}


// 평점을 담은 벡터를 반환함.
map<int, float> Dept::getGPA(int s_id) {
	map<int, float> gpaRank;	// 평점을 담는 벡터 생성
	int size = std_list.size();	// 학생 수
	int sub_size = std_list[s_id].sub_list.size(); // 과목 수 ! 특정 학생의 학번을 이용했지만 다른 학생들의 이수 과목 수도 같은 것으로 가정했기 때문에 사용.
	for (int i = 0; i < size; i++) {
		float sum = 0;

		for (int j = 0; j < sub_size; j++) {
			sum += std_list[i].sub_list[j].getGrade();
		}
		gpaRank.insert({ i+1, (sum / sub_size) }); // 평점 vector 생성.
	}
	return gpaRank;
}


// 전공 평점 벡터 반환 함수 추가

bool cmp(pair<int, float> &a, pair<int, float> &b) {
	if (a.second == b.second) 
		return a.first < b.first;
	return a.second > b.second;
}


// map은 key값의 중복을 허용하지 않기 때문에, 원소가 삭제되어 key값을 중복이 없는 학번으로 설정하였음
// 학생 1명 평점 출력, 등수 출력해야됨.
void Dept::printGPA_1p(map<int, float> rank_arr, int s_id) {
	vector<pair<int, float>> vec(rank_arr.begin(), rank_arr.end());
	sort(vec.begin(), vec.end(), cmp);
	int num = 1;
	for (auto i : vec) {
		cout << num << "등 : \t" << i.first << "\t" << i.second << endl;
		num++;
	}
	
}
