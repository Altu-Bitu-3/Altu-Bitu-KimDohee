#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ������ ��������, ������ ������������ �����ϸ� �ּڰ��� �ȴٴ� �����Ͽ� ����

int main() {
	int n; //���� �迭�� ũ��
	int S = 0; //S��

	cin >> n;

	vector<int> A(n, 0);
	vector<int> B(n, 0);
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	sort(A.begin(), A.end());  //A�� ������������ ����
	sort(B.begin(), B.end(), greater<>());

	for (int i = 0; i < n; i++) {
		S += A[i] * B[i];
	}
	
	cout << S << "\n";
}