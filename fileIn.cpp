#include "fileIn.h"


ifstream fileIn::sem_in() {
	ifstream fin;
	int sem;

	while (true) {
		if (!fin) {
			cout << "�����߻�" << endl;
		}
		cout << "�б� �Է� ( 1 / 2 ) > ";
		cin >> sem;

		if (sem == 1) {
			setSem(1);
			fin.open("1st_semester.txt");
			break;
		}
		else if (sem == 2) {
			setSem(2);
			fin.open("2nd_semester.txt");
			break;
		}
		else {
			cout << "1 / 2 �߿� ������ Ȯ���ϰ� ���� �б⸦ �ٽ� �Է����ּ��� " << endl;
		}
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
		}
		cnt++;	// �й��� ���� �ѹ��� ����.
	}

	fin.close();

	return mme;
}