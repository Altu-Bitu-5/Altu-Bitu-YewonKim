#include <iostream>
#include <algorithm>

using namespace std;

//�ø����ȣ�� �ڸ��� �� ���ϱ�(���ڸ�)
int sum(string a) {
	int result = 0;

	for (int i = 0; i < a.length(); i++) {
		int anum = a[i] - '0';//string to int
		if (anum >= 0 && anum <= 9) { //�����̸� ����
			result = result + anum;
		}
	}
	return result;
}

//�� �Լ�
bool cmp(string a, string b) {
	if (a.length() != b.length()) { //���� ª�� �� ����
		return a.length() < b.length();
	}
	int asum = sum(a);
	int bsum = sum(b);
	if (asum != bsum) { //(���� ������) �ڸ��� �� ���� �� ����
		return asum < bsum;
	}
	return a < b; //(����, �ڸ��� �� ��� ������) ����������
}

int main() {
	int n;
	string arr[50];

	//�Է�
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//���� ����
	sort(arr, arr + n, cmp);

	//���
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}