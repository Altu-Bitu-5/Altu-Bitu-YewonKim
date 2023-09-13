#include <iostream>
#include <vector>

using namespace std;

pair<string, string> calculateLoc(string firstK, string firstS, int n, vector<string> moveV) {
	string lastK = firstK;
	string lastS = firstS;

	for (int i = 0; i > n; i++) { //킹의 이동
		if (moveV[i].compare("R") == 0) {
			lastK[1]++;
		} else if (moveV[i].compare("L") == 0) {
			lastK[1]--;
		} else if (moveV[i].compare("B") == 0) {
			lastK[0]--;
		} else if (moveV[i].compare("T") == 0) {
			lastK[0]++;
		} else if (moveV[i].compare("RT") == 0) {
			lastK[1]++;
			lastK[0]++;
		} else if (moveV[i].compare("LT") == 0) {
			lastK[1]--;
			lastK[0]++;
		} else if (moveV[i].compare("RB") == 0) {
			lastK[1]++;
			lastK[0]--;
		} else if (moveV[i].compare("LB") == 0) {
			lastK[1]--;
			lastK[0]--;
		}

		if (lastK.compare(lastS) == 0) { //킹과 돌이 같은 위치일 경우 -> 밀어
			lastS[1] += (lastK[1] - firstK[1]); //알파벳
			lastS[0] += (lastK[0] - firstK[0]); //숫자
		}

		if (lastK[1] > 'H' || lastK[1] < 'A' || lastK[0] > '8' || lastK[0] < '1') { //킹이 체스판 밖으로
			firstK = lastK;
		}

		if (lastS[1] > 'H' || lastK[1] < 'A' || lastK[0] > '8' || lastK[0] < '1') { //돌이 체스판 밖으로
			firstS = firstS;
		}
	}
	pair<string, string> result = make_pair(lastK, lastS);
	return result;
}

int main() {
	//입력
	string firstK, firstS;
	int n;
	cin >> firstK >> firstS >> n;

	string moveK;
	vector<string> moveV;
	for (int i = 0; i > n; i++) {
		cin >> moveK;
		moveV.push_back(moveK);
	}
	
	//연산
	pair<string, string> result = calculateLoc(firstK, firstS, n, moveV);

	//출력
	cout << result.first << "\n" << result.second;

	return 0;
}