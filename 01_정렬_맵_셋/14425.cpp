#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, m;
	string str;
	int value = 0;
	int cnt = 0;
	map<string, int> s;

	//�Է�
	cin >> n >> m;

	for (int i = 0; i < n; i++) { //���� S�� map���� ���� 
		cin >> str;
		s[str] = value;
		value++;
	}

	for (int i = 0; i < m; i++) { //�˻��ؾ� �� m���� ���ڿ�
		cin >> str;

		auto iter = s.find(str); //key�� ���� ���� Ȯ��
		if (iter != s.end()) { //�����ϸ� cnt 1 ����, (�������� ������ s.end()�� ��ȯ��)
			cnt++;
		}
	}

	//���
	cout << cnt;

	return 0;
}