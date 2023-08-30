#include <iostream>
#include <cmath>

using namespace std;

int main() {
	//입력
	string a, b;
	int sum = 0;
	int round = 0;
	string result = "";
	string blank = "0";

	cin >> a >> b;

	//계산
	int alength = a.length();
	int blength = b.length();

	if (alength < blength) {
		swap(a, b);
		swap(alength, blength);
	}

	if (alength != blength) {
		for (int i = (alength - blength); i > 0; i--) {
			b = blank + b;
		}
	}

	for (int i = alength - 1; i >= 0; i--) {
		int anum = a[i] - '0';
		int bnum = b[i] - '0';

		sum = anum + bnum;

		if (round == 1) {
			sum++;
			round--;
		}
		if (sum > 9) {
			round++;
			result += (sum % 10) + '0';
		}
		else {
			result += (sum + '0');
		}
	}

	//출력
	if (round == 1) {
		result += "1";
	}

	for (int i = result.length()-1; i >= 0; i--) {
		cout << result[i];
	}

	return 0;
}