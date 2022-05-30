#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#include "student.h"
#include "subject.h"

class Dept {
	vector<Student> std_list; // Student 클래스 이용한 vector로 학생 리스트 생성.
public:	
	Dept();
	~Dept();

	void setStd(Subject sub, char(*sub_arr)[10], char(*info_arr)[10], int i); // 학생 정보 생성 함수
	int searchStd();	// 학생 검색 함수
	void searchSid(int s_id);	// 학번으로 학생 검색 함수

	map<int, float> getGPA(int s_id);		// 평점 검색 함수
	map<int, float> getMajorGPA(int s_id);	// 전공 평점 검색 함수
	void searchNrank();						// 상위 n명 검색 함수
	void printSubRank(map<int, float> rank_arr, int n);	// 석차 출력 함수
	void showSemRank();						// 학기별 석차 출력함수

	// 전체 평점 석차 함수
	void getTotalRank(map<int, float> gpa_1, map<int, float> gpa_2, map<int, float> m_gpa_1, map<int, float> m_gpa_2); 
	// 학생 1명의 전체 평점 함수
	void getTotalRank_1p(map<int, float> gpa_1, map<int, float> gpa_2, map<int, float> m_gpa_1, map<int, float> m_gpa_2, int s_id); 

	// 평점 출력 함수
	void printGPA(map<int, float> rank, map<int, float> mRank);
	void printGPA_1p(map<int, float> rank, map<int, float> mRank, int s_id);
	void printGPA_(int s_id);

	// UX 향상 위한 과목명 출력 함수
	void printSubName();
};
