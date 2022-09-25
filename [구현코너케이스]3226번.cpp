#include <iostream>
#include <string>

using namespace std;

int callSum(string a, string b, int d) {
	int sum = 0; //전화요금 합계 저장
	int h = stoi(a);  //string을 정수로 변환
	int m = stoi(b); 
	int new_m = m;   //60분을 넘어갈 것 대비해서 새로운 카피본 생성
	int new_h = h;   //24시를 넘어갈 것 대비해서 새로운 카피본 생성

	if ((m + d) < 60) {  //60분 안 넘어가면 그냥 더해주기
		new_m = m + d;
	}
	else {  //60분 넘어가면 60으로 나눈 나머지를 저장, hour도 똑같은 방식으로 판단
		new_m = (m + d) % 60;
		if ((h + (m + d) / 60) < 24) {
			new_h = h + ((m + d) / 60);
		}
		else {
			new_h = (h + ((m + d) / 60)) % 24;
		}
	}

	if ((h == 6) && (new_h == 7)) { //통화 후 아침 7시로 넘어가면, 단위 시간 당 요금 달라지므로 조건 따로 빼주기
		sum += 5 * (d - new_m) + 10 * new_m;
	}
	else if ((h == 18) && (new_h == 19)) { //위와 동일
		sum += 10 * (d - new_m) + 5 * new_m;
	}
	else {
		if ((h > 6) && (h < 19)) {  //7시~19시: 1분에 10원
			sum += 10 * d;
		}
		else {  //19시~7시: 1분에 5원
			sum += 5 * d;
		}

	}
	return sum;

}


int main() {
	//입력
	int n; //상근이가 건 전화의 수
	cin >> n;

	int sum = 0;

	while (n--) {
		string s = "";
		cin >> s;

		string h = s.substr(0, 2);  //문자열 각 칸에 해당하는 숫자를 int로 저장
		string m = s.substr(3, 2);
		int d;
		cin >> d;   //DD 입력

		sum = sum + callSum(h, m, d);
	}
	cout << sum << '\n';

	return 0;
}