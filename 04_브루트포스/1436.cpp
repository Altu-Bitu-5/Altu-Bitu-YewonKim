#include <iostream>
//#include <string>

using namespace std;
const int ANS = 10000000;
const int NUM = 666;

int findNum(int n) {
	int num = 0;
	//string snum = to_string(num); �ð��ʰ� �ڵ�
	int seq = 0;

	for (int i = NUM; i < ANS; i++) {
		num = i;
		while (num >= 666) {
			if (num % 1000 == 666) {
				seq++;
				if (seq == n) {
					return i;
					break;
				}
				break;
			}
			num /= 10;
		}
		if (seq == n) {
			return i;
			break;
		}
	}
	
	
	/* �ð��ʰ�
	while (seq != n) {
		for (int i = 0; i < snum.length() - 2; i++) { //snum�� 666�� ���ԵǾ� �ִ��� ���鼭 Ȯ��
			if (snum[i] == 6 && snum[i + 1] == 6 && snum[i + 2] == 6) {
				seq++; //666�� ���Ե� �����̸� seq�� +1
			}
		}
		num++;
	} 
	return num-1;
	*/
}

int main() {
	//�Է�
	int n;
	cin >> n;

	//����
	int result = findNum(n);

	//���
	cout << result;

	return 0;
}