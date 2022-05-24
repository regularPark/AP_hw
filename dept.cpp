#include "dept.h"

Dept::Dept() {};
Dept::~Dept() {};

void Dept::setStd(Subject sub, char sub_arr[][10], char info_arr[][10], int i) {
	// �л��� �̸��� �й��� ������ 1~2��° ���� ����.
	Student std;
	std.setNameId(info_arr[0], stoi(info_arr[1]));

	// �л��� ������ ����� "���� ��"�� ���ԵǴ� ���� �Ϲ����̱� ������
	// Table ������ �ؽ�Ʈ ������ �о���̴� ����� ������ �� ���α׷�������
	// for���� �̿��� ���� �Է� ����� ���� �ٶ����� ������ ������.
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


// Ư�� �л��� ���� ���
void Dept::getSubRank_1p(int s_id) {
	vector<int> rank;
	int size = std_list.size();	
	int sub_size = std_list[s_id].sub_list.size();
	for (int i = 0; i < size; i++) { // �л� ���� �̰� �ƴ� ����Ұ�. ���� ���� �� ���� �ű� �ʿ� ����. ���� �̾..
		for (int j = 0; j < sub_size; j++) {
			rank.push_back(std_list[i].sub_list[j].getScore());
		}
	}

	sort(rank.begin(), rank.end());
	find(rank.begin(), rank.end(), )

}

