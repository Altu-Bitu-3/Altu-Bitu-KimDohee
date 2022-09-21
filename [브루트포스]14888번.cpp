#include <iostream>
#include <vector>

using namespace std;

int n;
int mx = -1000000000;
int mn = 1000000000;
int num[11];
int op[4];


void getResult(int result, int idx) {  //idx는 수를 담은 num의 인덱스
	

	if (idx == n) {  //재귀 종료 조건
		if (mn > result) {
			mn = result;
		}
		if (mx < result) {
			mx = result;
		}
		
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;  //연산자 소모했으므로 하나 감소
			if (i == 0) { //더하기
				getResult(result + num[idx], idx + 1);  //num의 다음 인덱스와의 연산 진행
			}
			else if (i == 1) {//빼기
				getResult(result - num[idx], idx + 1);
			}
			else if (i == 2) {  //곱하기
				getResult(result * num[idx], idx + 1);
			}
			else {				//나누기
			getResult(result / num[idx], idx + 1);
			}
		
			op[i]++;   //하나 다시 늘림
		}
	}
}


int main() {
	//수의 개수 입력
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	getResult(num[0], 1);

	cout << mx << '\n' << mn << '\n';


	return 0;
}