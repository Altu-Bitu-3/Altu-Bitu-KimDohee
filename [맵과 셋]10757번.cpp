#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector <int> A;
vector <int> B;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string a, b;
	int up_count = 0; //올림 관리 변수
	int sum = 0; //각각 자릿수 더한 값
	string a_b_sum; //최종 결과 담을 문자열

	cin >> a >> b;  //A, B를 string으로 차례대로 입력받기

	//a, b자릿수 차이나면..? -> 빈자리만큼 0으로 채우기
	//편리성을 위해 a>b로 설정

	if (a.size() < b.size()) {
		swap(a, b);
	}
	int diff = a.size() - b.size(); //자릿수 차이 계산

	for (int i = 0; i < a.size(); i++) {
		A.push_back(a[i] - '0');  //-'0': 아스키코드 값 빼줌
	}

	for (int i = 0; i < diff; i++) { //자릿수 차이만큼 b의 빈자리를 0으로 채우기
		B.push_back(0);
	}

	for (int i = 0; i < b.size(); i++) {
		B.push_back(b[i] - '0');
	}


	//일의자릿수부터 차례대로 더하기
	for (int i = a.size() - 1; i >= 0; i--) {
		sum = A[i] + B[i];

		if (up_count == 1) { //올림관리변수의 값이 이미 1이라면, sum에 1추가
			sum++;
			up_count = 0;
		}

		if (sum > 9) {
			sum = sum % 10; //10으로 나눈 나머지로 변경, 올림 관리 변수값 1 증가
			up_count++;
		}

		a_b_sum.append(to_string(sum));
	}
	if (up_count == 1) {  //마지막 연산을 끝내고 올림 변수==1이면 a_b_sum에 '1'을 덧붙여줌
		a_b_sum.append("1");
	}

	for (int i = a_b_sum.size() - 1; i >= 0; i--) {
		cout << a_b_sum[i];
	}

	return 0;
}