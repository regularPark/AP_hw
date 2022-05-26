#include "dept.h"

Dept::Dept() {};
Dept::~Dept() {};

// 학생의 이름, 학번, 과목명과 원점수, 전공 여부, 환산 점수를 set하는 함수
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

// 특정 학생의 이름을 매개변수로 받은 후 평점을 구하는 함수
void Dept::searchStd(string n) {
	int size = std_list.size();
	int target;

	// 이름으로 학생을 찾기
	for (int i = 0; i < size; i++) {
		if (std_list[i].getName() == n) {
			cout << "\n이름 : " << std_list[i].getName() << "\t학번 :" << std_list[i].getID() << endl;

			printGPA_1p(getGPA(i + 1), getMajorGPA(i + 1), i + 1); // 평점을 구하는 함수
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
		gpaRank.insert({ i + 1, (sum / sub_size) }); // 평점 vector 생성.
	}
	return gpaRank;
}


// 전공 평점 벡터 반환 함수 추가
map<int, float> Dept::getMajorGPA(int s_id) {
	map<int, float> mGpaRank;	// 평점을 담는 벡터 생성
	int size = std_list.size();	// 학생 수
	int sub_size = std_list[s_id].sub_list.size(); // 과목 수 ! 특정 학생의 학번을 이용했지만 다른 학생들의 이수 과목 수도 같은 것으로 가정했기 때문에 사용.
	for (int i = 0; i < size; i++) {
		float sum = 0;
		int major_size = 0;

		for (int j = 0; j < sub_size; j++) {
			if (std_list[i].sub_list[j].isMjr()) {
				sum += std_list[i].sub_list[j].getGrade();
				major_size++;
			}
		}
		mGpaRank.insert({ i + 1, (sum / major_size) }); // 평점 vector 생성.
	}
	return mGpaRank;
}

bool cmp(pair<int, float>& a, pair<int, float>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}


// map은 key값의 중복을 허용하지 않기 때문에, 원소가 삭제되어 key값을 중복이 없는 학번으로 설정하였음
// 학생 1명 평점 출력, 등수 출력해야됨.
void Dept::printGPA_1p(map<int, float> rank_arr, map<int, float> m_rank_arr, int s_id) {

	// value 값으로 정렬하기 위해 map을 vector로 옮긴 후에 정렬하는 과정을 거침.
	vector<pair<int, float>> vec(rank_arr.begin(), rank_arr.end());
	vector<pair<int, float>> mVec(m_rank_arr.begin(), m_rank_arr.end());

	sort(vec.begin(), vec.end(), cmp);
	sort(mVec.begin(), mVec.end(), cmp);
	
	int num = 1;
	int m_num = 1;
	for (auto i : vec) {
		if (i.first == s_id)
			cout << "전체 학점 석차 " << num << "등\t" << "학기 평점 : " << i.second << endl;
		num++;
	}
	
	for (auto i : mVec) {
		if (i.first == s_id)
			cout << "전공 학점 석차 " << m_num << "등\t" << "학기 전공 평점 : " << i.second << endl;
		m_num++;
	}
}


// 과목별 상위 n명의 이름 출력하는 기능
void Dept::searchNrank(string sub_name, int n) {
	int size = std_list.size();
	int sub_size = std_list[n - 1].sub_list.size();
	map<int, float> sub_score;	// 학번과 성적을 담는 map 생성
	
	// 과목명으로 성적 찾기
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < sub_size; j++) {
			if (std_list[i].sub_list[j].getSubName() == sub_name) {
				sub_score.insert({ std_list[i].getID(), std_list[i].sub_list[j].getScore() });
			}
		}		
	}
	printSubRank(sub_score, n);
	
}

// 
void Dept::printSubRank(map<int, float> sub_score, int n) {
	// value 값으로 정렬하기 위해 map을 vector로 옮긴 후에 정렬하는 과정을 거침.
	vector<pair<int, float>> vec(sub_score.begin(), sub_score.end());

	sort(vec.begin(), vec.end(), cmp);

	int num = 1;
	for (auto i : vec) {
		if (num <= n)
			cout << num << "등\t" << std_list[i.first - 1].getName() << endl;
		num++;
	}
}
