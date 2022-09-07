#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 한줄은 오름차순, 한줄은 내림차순으로 정렬하면 최솟값이 된다는 가정하에 진행

int main() {
	int n; //정수 배열의 크기
	int S = 0; //S값

	cin >> n;

	vector<int> A(n, 0);
	vector<int> B(n, 0);
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	sort(A.begin(), A.end());  //A를 오름차순으로 정렬
	sort(B.begin(), B.end(), greater<>());

	for (int i = 0; i < n; i++) {
		S += A[i] * B[i];
	}
	
	cout << S << "\n";
}