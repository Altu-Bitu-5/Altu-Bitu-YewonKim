#include <iostream>
#include <algorithm>

using namespace std;

//시리얼번호의 자리수 합 구하기(숫자만)
int sum(string a) {
	int result = 0;

	for (int i = 0; i < a.length(); i++) {
		int anum = a[i] - '0';//string to int
		if (anum >= 0 && anum <= 9) { //숫자이면 더함
			result = result + anum;
		}
	}
	return result;
}

//비교 함수
bool cmp(string a, string b) {
	if (a.length() != b.length()) { //길이 짧은 것 먼저
		return a.length() < b.length();
	}
	int asum = sum(a);
	int bsum = sum(b);
	if (asum != bsum) { //(길이 같으면) 자리수 합 작은 것 먼저
		return asum < bsum;
	}
	return a < b; //(길이, 자리수 합 모두 같으면) 사전순으로
}

int main() {
	int n;
	string arr[50];

	//입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//정렬 연산
	sort(arr, arr + n, cmp);

	//출력
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}