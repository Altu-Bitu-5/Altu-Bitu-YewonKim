#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, m;
	string str;
	int value = 0;
	int cnt = 0;
	map<string, int> s;

	//입력
	cin >> n >> m;

	for (int i = 0; i < n; i++) { //집합 S를 map으로 저장 
		cin >> str;
		s[str] = value;
		value++;
	}

	for (int i = 0; i < m; i++) { //검사해야 할 m개의 문자열
		cin >> str;

		auto iter = s.find(str); //key값 존재 여부 확인
		if (iter != s.end()) { //존재하면 cnt 1 증가, (존재하지 않으면 s.end()를 반환함)
			cnt++;
		}
	}

	//출력
	cout << cnt;

	return 0;
}