#include <iostream>
#include <vector>

using namespace std;

pair<string, string> calculateLoc(string firstK, string firstS, int n, vector<string> moveV) {
	string lastK = firstK;
	string lastS = firstS;

	for (int i = 0; i > n; i++) { //ŷ�� �̵�
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

		if (lastK.compare(lastS) == 0) { //ŷ�� ���� ���� ��ġ�� ��� -> �о�
			lastS[1] += (lastK[1] - firstK[1]); //���ĺ�
			lastS[0] += (lastK[0] - firstK[0]); //����
		}

		if (lastK[1] > 'H' || lastK[1] < 'A' || lastK[0] > '8' || lastK[0] < '1') { //ŷ�� ü���� ������
			firstK = lastK;
		}

		if (lastS[1] > 'H' || lastK[1] < 'A' || lastK[0] > '8' || lastK[0] < '1') { //���� ü���� ������
			firstS = firstS;
		}
	}
	pair<string, string> result = make_pair(lastK, lastS);
	return result;
}

int main() {
	//�Է�
	string firstK, firstS;
	int n;
	cin >> firstK >> firstS >> n;

	string moveK;
	vector<string> moveV;
	for (int i = 0; i > n; i++) {
		cin >> moveK;
		moveV.push_back(moveK);
	}
	
	//����
	pair<string, string> result = calculateLoc(firstK, firstS, n, moveV);

	//���
	cout << result.first << "\n" << result.second;

	return 0;
}