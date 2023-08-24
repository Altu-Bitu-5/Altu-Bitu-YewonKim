#include <iostream>
#include <tuple>
#include <cmath> //abs(), floor()

using namespace std;

tuple<int, int, int> diet(int w0, int i0, int i, int a, int d, int t) { //체중 & 기초대사량 변화 계산하는 함수
	//w: 체중, m: 기초대사량
	int w1 = w0, m1 = i0; //case1(기초대사량 변화 고려 X)
	int w2 = w0, m2 = i0; //case2(기초대사량 변화 고려 O)

	while (d--) { //다이어트 기간동안
		//체중 += 일일 에너지 섭취량 - 일일 에너지 소비량
		//일일 에너지 소비량 = 일일 기초 대사량 + 일일 활동 대사량

		//체중 변화
		w1 += i - (m1 + a); //case1에서의 체중 변화(m1에 변화 X)
		w2 += i - (m2 + a); //case2에서의 체중 변화(m2에 변화 O)

		//기초대사량 변화(m2만 변화 O)
		if (abs(i - (m2 + a)) > t) { //(일일 에너지 섭취량 - 일일 에너지 소비량)의 절댓값 > 기초대사량 변화 역치라면
			m2 += float(i - (m2 + a)) / 2.0; //(일일 에너지 섭취량 - 일일 에너지 소비량)/2의 내림만큼이 기초대사량에 더해짐
			//이때 float끼리의 나눗셈이어야 하는 점 주의!
		}
	}
	return { w1, w2, m2 }; //변화한 값인 w1(case1의 변화한 체중), w2(case2의 변화한 체중), m2(case2의 변화한 기초대사량) 리턴
}

int main() {
	//입력
	int w0, i0, i, a; //w0:다이어트 전 체중, i0:다이어트 전 일일 에너지 섭취량 및 일일 기초 대사량, i:다이어트 기간 일일 에너지 섭취량, a:다이어트 기간 일일 활동 대사량
	int d, t; //d:다이어트 기간, t:기초대사량 변화 역치 
	int final_weight, final_meta; //다이어트 후 최종 체중, 최종 기초대사량

	cin >> w0 >> i0 >> t; //w0, i0, t 입력 받음
	cin >> d >> i >> a; //d, i. a 입력 받음

	//연산
	tuple<int, int, int> tmp = diet(w0, i0, i, a, d, t); //다이어트 기간동안 변화한 값을 diet 함수에서 계산 후 tuple로 리턴받음
	int w1 = get<0>(tmp), m1 = i0; //case1: 기초대사량 변화 고려 X
	int w2 = get<1>(tmp), m2 = get<2>(tmp); //case2: 기초대사량 변화 고려 O

	//출력
	//case1
	if (w1 <= 0) { //데시의 사망, 체중이 0g 이하인 경우(기초대사량의 변화가 없고, i0은 0보다 크기때문에 기초대사량이 0Kcal 이하인 경우는 고려 X)
		cout << "Danger Diet\n"; //"Danger Diet" 메세지 출력
	}
	else {
		cout << w1 << " " << m1 << "\n"; //다이어트 후 예상 체중 & 기초대사량(처음과 변화X) 출력
	}

	//case2
	if (w2 <= 0 || m2 <= 0) { //데시의 사망, 체중이 0g 이하이거나 기초대사량이 0Kcal 이하인 경우
		cout << "Danger Diet"; //"Danger Diet" 메세지 출력
	}
	else {
		cout << w2 << " " << m2 << " "; //다이어트 후 예상 체중 & 기초대샤량 출력
		if (m2 < i0) { //다이어트 후 기초대사량 < 다이어트 전 기초대사량
			cout << "YOYO"; //"YOYO" 메세지 출력
		}
		else {
			cout << "NO"; //"NO" 메세지 출력(요요 X)
		}
	}
	return 0;
}