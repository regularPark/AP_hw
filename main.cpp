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
			cout << "�����߻�" << endl;
		}
		cout << "�� �б�? ( 1 / 2 ) > ";
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
			cout << "1 / 2 �߿� ������ Ȯ���ϰ� ���� �б⸦ �ٽ� �Է����ּ��� " << endl;
		}
	}

	cout << endl;

	Dept mme;
	Subject sub;
	
	int cnt = 0;
	char s_Arr[100];
	char sub_Arr[10][10];	// ������� �����ϴ� �迭
	char buf[100];	// �ҷ����� ������ �ӽ������ϴ� buffer.

	char i_Arr[100];
	char info_Arr[10][10]; // �̸��� ID, ������ �ҷ�����. (�ʱ�ȭ �ʿ�)
	
	

	while (fin.getline(buf, 100)) {
		if (cnt == 0) {	// �ҷ����� txt ������ ù ���� ������� ǥ���Ѵ�.
			strcpy(s_Arr, buf);
			char* ptr = strtok(s_Arr, "\t");
			int i = 0;
			while (ptr != NULL) {
				strcpy(sub_Arr[i], ptr);
				ptr = strtok(NULL, "\t");
				i++;
			} //strtok �Լ��� \t�� �������� ���ڿ��� �߶� �迭�� �����Ѵ�.
			cout << buf << endl;
			cout << endl;
		}

		else {
			// ���������� 2��° ���� ���ڿ����� �߶󳻾� �迭�� ����.
			strcpy(i_Arr, buf);
			char* ptr = strtok(i_Arr, "\t");
			int i = 0;
			while (ptr != NULL) {
				strcpy(info_Arr[i], ptr);
				ptr = strtok(NULL, "\t");
				i++;
			}

			// vector�� �л��� ���� Ŭ������ push back�ϱ� ���� ���� �Լ�
			mme.setStd(sub, sub_Arr, info_Arr, i);
			cout << buf << endl;
		}		
		cnt++;	// �й��� ���� �ѹ��� ����.
	}
	

	fin.close();

	int select;
	string name;
	int n;

	
	cout << "\n\n----------�ϰ��� �ϴ� �۾��� ����----------" << endl;
	cout << "1. �л� 1���� ��� ��� / ���� ���� ��� ���" << endl;
	cout << "2. �Է��� ������ ���� n�� ���� ��� " << endl;
	cout << "3. ��ü ��� ���" << endl;
	cout << "4. �б⺰ ��� ���" << endl;
	cout << "5. �л� 1���� ���� ���� ����, �б� ����, �� ���� ���" << endl;
	cout << endl;
	cout << "�����ϰ��� �ϴ� ����� ��ȣ �Է�(1 ~ 5 ������ ����) > ";
	cin >> select;

	switch (select) {
	case 1:
		cout << "������ Ȯ���ϰ��� �ϴ� �л��� �̸� or �й� or �̸�&�й� ��θ� �Է� > ";
		cin >> name;
		mme.searchStd(name);
		break;
	case 2:
		cout << "n�� �Է� > ";
		cin >> n;
		break;
	default:
		cout << "1 ~ 5 ������ ������ �Է����ּ���" << endl;
	}



}