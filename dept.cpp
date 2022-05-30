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
		sub.setSub(sub_arr[j], stoi(info_arr[j]), sub.isMajorChk(sub_arr[j]), sub.setGrade(stoi(info_arr[j])), sub.setGPAgrade(stoi(info_arr[j])));
		std.addSub(sub);
	}
	std_list.push_back(std);
}


// 특정 학생의 이름을 매개변수로 받은 후 평점을 구하는 함수
int Dept::searchStd() {
	int size = std_list.size();
	int fName = 0; // 이름이 같은 학생의 수를 카운팅하는 변수
	int target = 0;
	string n;
	int s_id;
	cout << "검색 가능한 학생 이름\n";
	for (int i = 0; i < size; i++) {
		cout << std_list[i].getName() << "    ";

	}
	cout << "\n\n";

	cout << "성적을 확인하고자 하는 학생의 이름 입력 > ";

	cin >> n;
	
	// 이름으로 학생을 찾기

	for (int i = 0; i < size; i++) {
		if (std_list[i].getName() == n) {
			fName++; // 동명이인, 학생의 존재여부를 위해 카운트하는 변수
			target = i;
		}
	}

	// fName 변수가 0이면 입력한 이름의 학생이 명단에 존재하지 않음
	if (fName == 0) {
		string name;
		
		cout << "\n존재하지 않는 학생입니다. 다시 입력해주세요." << endl;

		// 이후 연계되어 다른 성적 출력 함수에 사용될 학번을 return
		return searchStd();
	}

	// 입력한 이름의 학생이 1명.
	else if (fName == 1) {
		int s_id = std_list[target].getID();
		cout << "\n이름 : " << std_list[target].getName() << "\t학번 :" << std_list[target].getID() << endl; 
		printGPA_1p(getGPA(target + 1), getMajorGPA(target + 1), target + 1); // 평점을 구하는 함수
		return s_id;
	}

	// 입력한 이름의 학생이 1명 이상.
	else if (fName > 1) {

		cout << "\n이름이 같은 학생이 두 명 이상입니다. " << endl;
		for (int i = 0; i < size; i++) {
			if (std_list[i].getName() == n) {
				// 동명인 학생의 이름과 학번을 출력하여 사용자가 학번으로 검색할 수 있도록 유도.
				cout << "\n이름 : " << std_list[i].getName() << "\t학번 :" << std_list[i].getID() << endl;
			}
		}

		// 알아낸 학번으로 성적을 검색
		cout << "\n성적을 확인할 학생의 학번을 입력 > ";
		cin >> s_id;
		searchSid(s_id);
		return s_id;

	}

}

//학번으로 학생을 찾는 함수
void Dept::searchSid(int s_id) {
	int size = std_list.size();
	// 학번으로 학생을 찾기
	for (int i = 0; i < size; i++) {
		if (std_list[i].getID() == s_id) {
			cout << "\n이름 : " << std_list[i].getName() << "\t학번 :" << std_list[i].getID() << endl;

			printGPA_1p(getGPA(i + 1), getMajorGPA(i + 1), i + 1); // 평점을 출력하는 함수
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


// 전공 평점 구하는 함수
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

bool cmp(pair<int, float>& a, pair<int, float>& b) {	// map의 value였던 것의 크기로 정렬하는 함수.
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

	sort(vec.begin(), vec.end(), cmp);	// 벡터 재정렬하기 위해 Algorithm의 내장함수 sort() 사용.
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
void Dept::searchNrank() {
	string sub_name;
	int n;
	

	int size = std_list.size();
	int sub_size = std_list[0].sub_list.size();
	map<int, float> sub_score;	// 학번과 성적을 담는 map 생성
		

	// 과목을 찾을 수 있도록 과목명 출력
	for (int j = 0; j < sub_size; j++) {
			cout << std_list[0].sub_list[j].getSubName().substr(0, std_list[0].sub_list[j].getSubName().length() - 2) << "     ";
	}
	
	cout << "\n\n석차를 확인할 과목 이름을 입력 > ";
	while (true) {	// 과목명을 잘못 입력했을때의 예외처리.
		cin >> sub_name;
		bool isExist = false;
		for (int j = 0; j < sub_size; j++) {
			if (std_list[0].sub_list[j].getSubName().substr(0, std_list[0].sub_list[j].getSubName().length() - 2) == sub_name) {
				isExist = true;
				break;
			}
		}
		if (isExist) break;
		
		cout << "과목명을 확인 후 올바른 과목명을 재입력해주세요." << endl;
		for (int j = 0; j < sub_size; j++) {
			cout << std_list[0].sub_list[j].getSubName().substr(0, std_list[0].sub_list[j].getSubName().length() - 2) << "     ";
		}
		cout << "\n석차를 확인할 과목 이름을 입력 > ";
	}
	cout << endl;

	cout << "상위 n명 중 알고 싶은 n을 입력 > ";
	while (true) {
		cin >> n;
		// 학생의 수를 벗어나는 수를 입력 시 예외처리.
		if (n < 1 || n > 15) {
			cout << "\n1 ~ 15 사이의 석차를 입력 > ";
		}
		else break;
	}
	
	cout << "\n----------상위 " << n << "명 명단----------" << endl;
	
	
	// 과목명으로 성적 찾기, substr를 사용한 이유는 최초에 파일에는 DB/m, Human/g 처럼 전공 교양 구분을 위한
	// 식별자가 존재하기 때문임. 뒤의 두 글자로 전공 여부를 판단하고, 사용자에게 출력시에는 substr 함수로
	// 두 글자를 삭제 후 출력한다.
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < sub_size; j++) {
			if (std_list[i].sub_list[j].getSubName().substr(0, std_list[i].sub_list[j].getSubName().length() - 2) == sub_name) {
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
			cout << "\t" << num << "등\t" << std_list[i.first - 1].getName() << " " << std_list[i.first - 1].getID() << endl;
		num++;
	}
}

// 학기별 등수 출력 - 기존에 만들어 둔 평점을 담는 map을 사용
void Dept::showSemRank() {
	printGPA(getGPA(1), getMajorGPA(1));
}


// 한 학기의 석차와 전공 석차를 매기기 위해 map -> vector로 변환
// 학번을 key로, 성적을 value로 사용하는 이유는 학번에는 중복이 존재할 수 없다는 것을 가정했을 때,
// map에서 key의 성질인 중복을 허용하지 않는 것과 일맥상통하며, 중복된 값이 입력됐을 때 무시하기 때문에
// 혹여 성적이 동률일 때 map에 삽입되지 않는 상황 또한 피한 것이다.
void Dept::printGPA(map<int, float> rank_arr, map<int, float> m_rank_arr) {
		
	vector<pair<int, float>> vec(rank_arr.begin(), rank_arr.end());
	vector<pair<int, float>> mVec(m_rank_arr.begin(), m_rank_arr.end());

	// 내림차순으로 정렬하기 위해 생성한 cmp 함수와 Algorithm 헤더의 
	// 내장함수 sort()를 이용하여 vector로 전환한 성적을 내림차순으로 정렬.
	sort(vec.begin(), vec.end(), cmp);
	sort(mVec.begin(), mVec.end(), cmp);

	int num = 1;
	int m_num = 1;
	
	cout << "--------해당 학기 석차--------" << endl;
	for (auto i : vec) {
		cout << "\t" << num << "등\t" << std_list[i.first - 1].getName() << " " << std_list[i.first - 1].getID() << endl;
		num++;
	}

	cout << "\n\n";

	cout << "--------전공 학점 석차--------" << endl;
	for (auto i : mVec) {
		cout << "\t" << m_num << "등\t" << std_list[i.first - 1].getName() << " " << std_list[i.first - 1].getID() << endl;
		m_num++;
	}
}


// 마찬가지로 map을 vector로 변환한다.
void Dept::getTotalRank(map<int, float> gpa_1, map<int, float> gpa_2, map<int, float> m_gpa_1, map<int, float> m_gpa_2) {
	map<int, float> gpa;
	map<int, float> m_gpa;
	int size = gpa_1.size();

	for (int i = 0; i < size; i++) {
		gpa.insert({ i+1, (gpa_1.at(i+1) + gpa_2.at(i+1)) / 2 });
		m_gpa.insert({ i+1, (m_gpa_1.at(i+1) + m_gpa_2.at(i+1)) / 2 });
	}

	vector<pair<int, float>> vec(gpa.begin(), gpa.end());
	vector<pair<int, float>> mVec(m_gpa.begin(), m_gpa.end());

	sort(vec.begin(), vec.end(), cmp);
	sort(mVec.begin(), mVec.end(), cmp);

	int num = 1;
	int m_num = 1;

	for (auto i : vec) {
		cout << "\t" << num << "등\t" << std_list[i.first - 1].getName() << " " << std_list[i.first - 1].getID() << endl;
		num++;
	}

	cout << "\n\n";

	
	cout << "--------전공 학점 석차--------" << endl;
	for (auto i : mVec) {
		cout << "\t" << m_num << "등\t" << std_list[i.first - 1].getName() << " " << std_list[i.first - 1].getID() << endl;
		m_num++;
	}
}


void Dept::getTotalRank_1p(map<int, float> gpa_1, map<int, float> gpa_2, map<int, float> m_gpa_1, map<int, float> m_gpa_2, int s_id) {
	map<int, float> gpa;
	map<int, float> m_gpa;
	int size = gpa_1.size();

	for (int i = 0; i < size; i++) {
		gpa.insert({ i + 1, (gpa_1.at(i + 1) + gpa_2.at(i + 1)) / 2 });
		m_gpa.insert({ i + 1, (m_gpa_1.at(i + 1) + m_gpa_2.at(i + 1)) / 2 });
	}

	vector<pair<int, float>> vec(gpa.begin(), gpa.end());
	vector<pair<int, float>> mVec(m_gpa.begin(), m_gpa.end());

	sort(vec.begin(), vec.end(), cmp);
	sort(mVec.begin(), mVec.end(), cmp);


	cout << endl;

	// 전체 학기 평점이 담긴 map을  vector화하여 sort() 함수를 이용해 정렬
	// 이후 학번으로 검색하여 출력하는 과정
	for (auto i : vec) {
		if (std_list[i.first - 1].getID() == s_id) {
			cout << "전체 학기 평점(교양 포함) : " << i.second << endl;
		}		
	}
	cout << "--------전체 학기 평점--------" << endl;


	cout << "\n\n";


	for (auto i : mVec) {
		if (std_list[i.first - 1].getID() == s_id) {
			cout << "전체 학기 전공 평점 : " << i.second << endl;
		}
	}
	cout << "--------전체 전공 평점--------" << endl;

}


// 5번 기능을 위해 과목명을 출력함
void Dept::printSubName() {
	int sub_size = std_list[0].sub_list.size();

	// 과목을 찾을 수 있도록 과목명 출력
	for (int j = 0; j < sub_size; j++) {
		cout << std_list[0].sub_list[j].getSubName().substr(0, std_list[0].sub_list[j].getSubName().length() - 2) << "\t\t";
	}
	cout << endl;
}

void Dept::printGPA_(int s_id) {
	int sub_size = std_list[0].sub_list.size();
	// 과목별 원점수와 학점을 출력
	for (int j = 0; j < sub_size; j++) {
		cout << std_list[s_id - 1].sub_list[j].getGPA() << " " << std_list[s_id - 1].sub_list[j].getScore() << "\t\t";
	}
	cout << endl;
}
