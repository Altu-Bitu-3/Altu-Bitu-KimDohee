#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e6; //최대 범위 지정

//에라토스테네스의 체
void getPrime(vector<bool>& isPrime) { //1,000,000 이하 소수 저장하는 벡터
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= MAX; i++) {
		if (isPrime[i] == true) {
			for (int j = i * i; j <= MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}
}


void goldBach(int n, vector<bool>& isPrime) {  //골드바흐 문제 해결

	bool answer = false;

	for (int i = 2; i <= n; i++) {
		if ((isPrime[i]) && (isPrime[n - i])) { //특정 소수가 쌍에 포함되려면, n-특정 소수의 값도 벡터안에서 true값을 가져야한다(소수여야한다)

			cout << n << " = " << i << " + " << n - i << '\n';

			answer = true; //합이 n을 만족하는 경우가 있으므로 true대입
			break;
		}
	}

	if (answer == false) { //합이 n을 만족하는 경우가 없을때
		cout << "Goldbach's conjecture is wrong." << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> isPrime(MAX + 1, true);   //소수 배열 저장하는 벡터
	
	getPrime(isPrime);  //소수 체크 먼저 진행

	//입력
	while (true) {
		int n;
		cin >> n;

		if (n == 0) //n==0이면 입력 종료
			break;

		goldBach(n, isPrime);
	}

	return 0;
}