#include <iostream>
//#include <string>

using namespace std;
const int ANS = 10000000;
const int NUM = 666;

int findNum(int n) {
	int num = 0;
	//string snum = to_string(num); 시간초과 코드
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
	
	
	/* 시간초과
	while (seq != n) {
		for (int i = 0; i < snum.length() - 2; i++) { //snum에 666이 포함되어 있는지 돌면서 확인
			if (snum[i] == 6 && snum[i + 1] == 6 && snum[i + 2] == 6) {
				seq++; //666이 포함된 숫자이면 seq에 +1
			}
		}
		num++;
	} 
	return num-1;
	*/
}

int main() {
	//입력
	int n;
	cin >> n;

	//연산
	int result = findNum(n);

	//출력
	cout << result;

	return 0;
}